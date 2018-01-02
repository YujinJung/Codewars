#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>

void InitChars(std::map<char, char> &m, std::vector<char> &v)
{
	char index = 0;
	// UpperCase
	for (char i = 65; i <= 90; i++, index++)
	{
		m[i] = index;
		v.push_back(i);
	}

	// LowerCase
	for (char i = 97; i <= 122; i++, index++)
	{
		m[i] = index;
		v.push_back(i);
	}

	// digit
	for (char i = 48; i <= 57; i++, index++)
	{
		m[i] = index;
		v.push_back(i);
	}

	// 32 space 46 .
	m[32] = index;
	v.push_back(32);
	m[46] = index + 1;
	v.push_back(46);
}

void enc(char &x)
{
	// 2
	char chk = 0x14;
	x = chk ^ x;

	// 3
	char firstBit = x & 0x07; // 0000 0xxxx
	firstBit = firstBit << 3; // 00xx x000
	char lastBit = x & 0x38; // 00xx x000
	lastBit = lastBit >> 3; // 0000 0xxx ?? 다 1되면/./?

	x = firstBit + lastBit;

	/*
	* 4
	* Change every odd bit against the following bit of the char
	*/
	char oddBit = x & 0x15;
	oddBit = oddBit << 1;

	char evenBit = x & 0x2A;
	evenBit = evenBit >> 1;

	x = oddBit + evenBit;

	/*
	* 5
	* Reverse the whole line of bits of the char
	*/
	// 00xx  xxxx
	// 0012 3456
	// 0065 4321
	chk = x;
	x = 0x00;
	for (int i = 0; i < 6; i++)
	{
		x = x << 1;
		x += chk & 0x01;
		chk = chk >> 1;
	}

	/*
	* 6
	* Change the first bit against the third bit of the char
	*/
	// 00x0 x000
	firstBit = x & 0x20;
	firstBit = firstBit >> 2;
	lastBit = x & 0x08;
	lastBit = lastBit << 2;

	// 1101 0111
	// D7
	x = x & 0xD7;
	x = x | firstBit | lastBit;
}

/*
* a ^ b => same : 0, dif : 1
* a &
*/
std::string encrypt(std::string text)
{
	if (text == "") return "";

	std::string result;
	std::string ruleOneStr;
	std::map<char, char> m;
	std::vector<char> v;
	int chkFirst = 0;
	char preChar;

	InitChars(m, v);

	for (auto t : text)
	{
		char x = m.at(t);

		if (chkFirst == 0)
		{
			chkFirst = 1;
			preChar = x;
			continue;
		}

		// 1.5 2.1
		char preFifth = 0x02 & preChar; // 0000 00x0
		preFifth = preFifth << 4; // 00x0 0000
		char curFirst = 0x20 & x; // 00x0 0000
		curFirst = curFirst >> 4; // 0000 00x0

		preChar = preChar & 0xFD;
		preChar = preChar | curFirst;
		x = x & 0xDF;
		x = x | preFifth;

		ruleOneStr.push_back(v.at(preChar));
		preChar = x;
	}
	ruleOneStr.push_back(v.at(preChar));

	for (auto t : ruleOneStr)
	{
		char x = m.at(t);

		enc(x);
		result.push_back(v.at(x));
	}
	return result;
}


void dec(char& x)
{
	char chk = 0x10; // 0001 0000

					 // 6
	char firstBit = x & 0x20;
	firstBit = firstBit >> 2;
	char lastBit = x & 0x08;
	lastBit = lastBit << 2;

	x = x & 0xD7;
	x = x | firstBit | lastBit;

	// 5
	chk = x;
	x = 0x00;
	for (int i = 0; i < 5; i++)
	{
		x += chk & 0x01;
		x = x << 1;
		chk = chk >> 1;
	}
	x += chk & 0x01;

	// 4
	char oddBit = x & 0x15;
	oddBit = oddBit << 1;

	char evenBit = x & 0x2A;
	evenBit = evenBit >> 1;

	x = oddBit + evenBit;

	// 3
	firstBit = x & 0x07; // 0000 0xxxx
	firstBit = firstBit << 3; // 00xx x000
	lastBit = x & 0x38; // 00xx x000
	lastBit = lastBit >> 3; // 0000 0xxx ?? 다 1되면/./?

	x = firstBit + lastBit;

	// 2
	chk = 0x14;
	x = chk ^ x;
}

std::string decrypt(std::string encryptedText)
{
	if (encryptedText == "") return "";

	std::string result;
	std::string text;
	std::map<char, char> m;
	std::vector<char> v;
	int chkFirst = 0;
	char preChar;

	InitChars(m, v);

	// 6 - 2
	for (auto t : encryptedText)
	{
		char x = m.at(t);
		dec(x);
		text.push_back(v.at(x));
	}

	// 1
	for (auto t : text)
	{
		char x = m.at(t);

		if (chkFirst == 0)
		{
			chkFirst = 1;
			preChar = x;
			continue;
		}

		char preFifth = 0x02 & preChar; // 0000 00x0
		preFifth = preFifth << 4; // 00x0 0000
		char curFirst = 0x20 & x; // 00x0 0000
		curFirst = curFirst >> 4; // 0000 00x0

		preChar = preChar & 0xFD;
		preChar = preChar | curFirst;
		x = x & 0xDF;
		x = x | preFifth;

		result.push_back(v.at(preChar));
		preChar = x;
	}
	result.push_back(v.at(preChar));

	return result;
}

int main(void)
{
	//std::string str = encrypt("Abc");
	std::string str = encrypt("Abc");
	str = decrypt("K");

	system("pause");
}