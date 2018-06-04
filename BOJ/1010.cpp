#include <iostream>
using namespace std;

int calculate(int n, int r, int cache[30][30])
{
	int& ret = cache[n][r];

	if (n == r || r == 0) return ret = 1;
	else if (ret > 0) return ret;
	else return ret = calculate(n - 1, r - 1, cache) + calculate(n - 1, r, cache);
}

int main(void)
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N, M;
		cin >> N >> M;

		int cache[30][30] = { 0, };

		cout << calculate(M, N, cache) << endl;
	}
}