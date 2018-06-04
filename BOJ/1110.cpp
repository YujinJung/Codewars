#include <iostream>
using namespace std;


int main(void)
{
	int N;
	cin >> N;

	int n0, n1;
	n0 = N / 10 % 10;
	n1 = N % 10;

	int i = 0;
	while (true) {
		int num = (n0 + n1) % 10;
		n0 = n1;
		n1 = num;

		++i;
		if (n0 * 10 + n1 == N) break;
	}

	cout << i << endl;

	return 0;
}