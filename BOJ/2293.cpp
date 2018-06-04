#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<int> coin;
	int temp;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		coin.push_back(temp);
	}

	vector<int> cache(k + 1, 0);
	cache[0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = coin[i]; j <= k; ++j)
			cache[j] += cache[j - coin[i]];
	}

	cout << cache[k] << endl;

	return 0;
}