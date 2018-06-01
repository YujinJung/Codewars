#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<vector<long long>> v(N, {-1, -1});
    v[0][0] = 0;
    v[0][1] = 1;

    for (int i = 1; i < N; ++i) {
        v[i][0] = v[i - 1][0] + v[i - 1][1];
        v[i][1] = v[i - 1][0];
    }

    cout << v[N - 1][0] + v[N - 1][1] << endl;

    return 0;
}