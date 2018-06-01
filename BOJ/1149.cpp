#include <iostream>
#include <vector>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int main(void)
{
	// Input
	int N;
	cin >> N;

	vector<vector<int> > cost;
	vector<vector<int> > dp;
	cost.reserve(N);
	dp.reserve(N);

	for (int i = 0; i < N; ++i) {
		vector<int> input;
		input.reserve(N);
		vector<int> inDP(3, -1);
		dp.push_back(inDP);

		for (int j = 0; j < 3; ++j) {
			int temp;
			cin >> temp;
			input.push_back(temp);
		}
		cost.push_back(input);
	}

	// Calculate
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];

	for (int i = 1; i < N; ++i) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	cout << min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]) << endl;


	return 0;
}