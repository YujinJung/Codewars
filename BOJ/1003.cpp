#include <iostream>
#include <vector>

int fibonacci(int n, std::vector<std::vector<int> >& dp) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else if (dp[n][2] != -1) {
		return dp[n][2];
	}
	else {
		int& ret = dp[n][2];
		ret = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
		dp[n][0] = dp[n - 1][0] + dp[n - 2][0];
		dp[n][1] = dp[n - 1][1] + dp[n - 2][1];

		return ret;
	}
}

int main(void)
{
    int T;
    std::cin >> T;

    for(int i = 0; i < T; ++i) {
       int N;
       std::cin >> N;

       if(N == 0)
       {
            std::cout << 1 << " " << 0 << std::endl;
            continue;
       }
        else if(N == 1)
        {
            std::cout << 0 << " " << 1 << std::endl;
            continue;
        }

       std::vector<std::vector<int>> dp(N + 1, {-1, -1, -1});

       dp[0][0] = 1; dp[0][1] = 0; dp[0][2] = 0;
       dp[1][0] = 0; dp[1][1] = 1; dp[1][2] = 1;

       fibonacci(N, dp);
       std::cout << dp[N][0] << " " << dp[N][1] << std::endl;
    }
	
	return 0;
}