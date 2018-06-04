#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N;
	cin >> N;

    if (N == 1) {
        cout << 9 << endl;
        return 0;
    }

    const int NUMDIGIT = 10;
    const int MAX = 1000000000;
    vector<int> cache(NUMDIGIT, 1);
    cache[0] = 0;

    for (int i = 1; i < N; ++i) {
        int prev = 0, cur = cache[0], next = cache[1];
        for (int j = 0; j < NUMDIGIT; ++j) {
            if (j != 9)
                next = cache[j + 1];
            else
                next = 0;

            cache[j] = (prev + next) % MAX;

            prev = cur;
            cur = next;
        }
    }

    int sum = 0;
    for (auto& e : cache)
        sum = (sum + e) % MAX;

    cout << sum << endl;

    return 0;
}