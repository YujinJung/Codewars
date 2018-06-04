#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double min(double a, double b) { return a < b ? a : b; }

void calculate(long long fullX[2], long long fullY[2], vector<vector<int> >& input, double& length, vector<int>& left)
{

	// half
	if (left.size() == input.size() / 2)
	{
		long long x = fullX[0] - (2 * fullX[1]);
		long long y = fullY[0] - (2 * fullY[1]);

		double len = sqrt(x * x + y * y);
		length = min(length, len);

		return;
	}

	int max = left.empty() ? 1 : (input.size() / 2) + left.size();
	for (int i = left.empty() ? 0 : left.back() + 1; i <= max; ++i)
	{
		left.push_back(i);
		fullX[1] += input[i][0]; fullY[1] += input[i][1];
		calculate(fullX, fullY, input, length, left);
		fullX[1] -= input[i][0]; fullY[1] -= input[i][1];
		left.pop_back();
	}

}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int N;
		cin >> N;
		vector<vector<int> > input(N, { -1, -1 });
		vector<vector<int> > cache(N, { -1, -1 });

		int x = 0, y = 0;
		for (int j = 0; j < N; ++j)
		{
			cin >> input[j][0] >> input[j][1];
			x += input[j][0];
			y += input[j][1];
		}

		long long fullX[2] = { 0, 0 };
		long long fullY[2] = { 0, 0 };
		vector<int> left;
		double length = 987654321.0;
		fullX[0] = x; fullY[0] = y;
		calculate(fullX, fullY, input, length, left);

		cout << fixed;
		cout.precision(6);
		cout << length << endl;

	} // for

	return 0;
}