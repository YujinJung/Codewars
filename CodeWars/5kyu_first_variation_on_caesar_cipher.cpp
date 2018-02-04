#include <iostream>
#include <vector>
#include <string>

class CaesarCipher
{
  public:
	static int alphaCase(const char &a)
	{
		// 65 - 90 / 97 - 122
		if (a >= 65 && a <= 90)
			return 1; // upper
		else if (a >= 97 && a <= 122)
			return 2; // lower

		// not alpha
		return 0;
	}

	static std::vector<std::string> movingShift(const std::string &s, int shift)
	{
		// shift -> ...
		// Calculate part length
		int partLen = 0;
		if (s.size() % 5 > 0)
			partLen = s.size() / 5 + 1;
		else
			partLen = s.size() / 5;

		std::vector<std::string> result;
		std::string input;
		int partLenIndex = 0, shiftIndex = shift;
		for (auto x : s)
		{
			if (shiftIndex == 26)
				shiftIndex = 0;

			if (partLenIndex == partLen)
			{
				result.push_back(input);
				input.clear();
				partLenIndex = 0;
			}

			// upper case
			if (alphaCase(x) == 1)
			{
				x += shiftIndex;
				if (alphaCase(x) != 1)
					x -= 26;
			} // lowercase
			else if (alphaCase(x) == 2)
			{
				x += shiftIndex;
				if (alphaCase(x) != 2)
					x -= 26;
			}

			input.push_back(x);

			shiftIndex++;
			partLenIndex++;
		}

		if (!input.empty())
			result.push_back(input);

		for (int i = result.size(); i < 5; i++)
			result.push_back("");

		return result;
	}
	static std::string demovingShift(std::vector<std::string> &s, int shift)
	{
		int shiftIndex = shift;
		std::string result;

		for (auto y : s)
		{
			for (auto x : y)
			{
				if (alphaCase(x) == 1)
				{
					x -= shiftIndex;
					if (alphaCase(x) != 1)
						x += 26;
				} // lowercase
				else if (alphaCase(x) == 2)
				{
					x -= shiftIndex;
					if (alphaCase(x) != 2)
						x += 26;
				}

				shiftIndex++;
				if (shiftIndex == 26)
					shiftIndex = 0;

				result.push_back(x);
			}
		}

		return result;
	}
};

int main(void)
{
	std::string u = "I should have known that you would have a perfect answer for me!!!";
	std::vector<std::string> sol = {"J vltasl rlhr ", "zdfog odxr ypw", " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"};

	std::vector<std::string> res = CaesarCipher::movingShift(u, 1);
	std::string strRes = CaesarCipher::demovingShift(sol, 1);

	return 0;
}
