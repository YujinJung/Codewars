#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int cache[1000] = {0, };
    cache[1] = 1;
    cache[2] = 3;

    for(int i = 3; i <= N; ++i) {
        cache[i] = (cache[i - 1] + 2 * cache[i - 2]) % 10007;
    }
    cout << cache[N] << endl;

    return 0;
}