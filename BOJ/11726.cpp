#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int cache[1001];

    cache[1] = 1;
	cache[2] = 2;

	for (int i = 3; i <= N; ++i) {
        cache[i] = (cache[i-1] + cache[i-2]) % 10007;
	}

	cout << cache[N] << endl;

	return 0;
}