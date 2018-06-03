#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int calculate(int n, vector<vector<int> >& sequence, vector<int>& buildTime, vector<int>& dp)
{
	int& ret = dp[n - 1];
	if (ret != -1) return ret;

	for (int i = 0; i < sequence[n - 1].size(); ++i) {
		int pre = sequence[n - 1][i];
		ret = max(ret, calculate(pre, sequence, buildTime, dp));
	}
	if (ret != -1)
		return ret = ret + buildTime[n - 1];
	else
		return ret = buildTime[n - 1];
}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N, K;
		cin >> N >> K;
		vector<int> buildTime;
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			buildTime.push_back(temp);
		}

		vector<vector<int> > sequence(N);
		for (int j = 0; j < K; ++j) {
			int pre, cur;
			cin >> pre >> cur;
			sequence[cur - 1].push_back(pre);
		}
		int target;
		cin >> target;

		vector<int> dp(N, -1);
		cout << calculate(target, sequence, buildTime, dp) << endl;
	}

	return 0;
}