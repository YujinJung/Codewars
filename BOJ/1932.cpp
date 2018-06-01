#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
	int N;
	cin >> N;

	vector<vector<int> > v;
	vector<vector<int> > dp;

	for (int i = 0; i < N; ++i) {
		vector<int> v1;
		vector<int> v2;
		for (int j = 0; j < i + 1; ++j) {
			int temp;
			cin >> temp;
			v1.push_back(temp);
			v2.push_back(-1);
		}
		v.push_back(v1);
		dp.push_back(v2);
	}

	dp[0][0] = v[0][0];
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if (j == i) {
				dp[i][j] = v[i][j] + dp[i - 1][j - 1];
			}
			else if (j == 0) 
				dp[i][j] = v[i][j] + dp[i - 1][j];
			else
				dp[i][j] = v[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	int ret = -1;
	for (int i = 0; i < N; ++i) {
		ret = max(ret, dp[N - 1][i]);
	}

	cout << ret << endl;

	return 0;
}