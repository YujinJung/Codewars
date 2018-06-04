#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int num;
	cin >> num;

	vector<int> fill;
	for (int i = 0; i < num; ++i) {
		int input;
		cin >> input;
		fill.push_back(input);
	}

	if (num == 0) {
		cout << 0 << endl;
		return 0;
	}
	if (num == 1) {
		cout << fill[0] << endl;
		return 0;
	}

	// 0 - prev 0 / 1 - prev 1 / 2 - prev 2
	vector<vector<int> > cache(num, { -1, -1, -1 });
	cache[0][0] = 0;
	cache[0][1] = cache[0][2] = fill[0];

	for (int i = 1; i < num; ++i) {
		cache[i][0] = max(max(cache[i - 1][0], cache[i - 1][1]), cache[i - 1][2]);
		cache[i][1] = fill[i] + cache[i - 1][0];
		cache[i][2] = fill[i] + cache[i - 1][1];
	}

	cout << max(max(cache[num - 1][0], cache[num - 1][1]), cache[num - 1][2]) << endl;

	return 0;
}