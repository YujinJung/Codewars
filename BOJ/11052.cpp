#include <iostream>

using namespace std;
int max(int a, int b) { return a > b ? a : b; }

int main(void)
{
    int N;
    cin >> N;
    int price[1001];
    int cache[1001];

    for(int i = 1; i <= N; ++i) {
        cin >> price[i];
    }

    cache[1] = price[1];
    for(int i = 2; i <= N; ++i) {
        cache[i] = price[i];
        for(int j = 1; j <= (i / 2); ++j) {
            int sum = cache[j] + cache[i-j];
            cache[i] = max(cache[i], sum);
        }
    }

    cout << cache[N] << endl;
}