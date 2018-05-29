#include <iostream>
#include <vector>

using namespace std;

int calculate(int num, vector<int>& cache)
{
	if (num == 0) return 1;

	int& ret = cache[num - 1];

	if (ret != -1) return ret;

	if (num >= 3) {
		return ret = calculate(num - 1, cache) + calculate(num - 2, cache) + calculate(num - 3, cache);
	}
	else if (num == 2) {
		return ret = calculate(num - 1, cache) + calculate(num - 2, cache);
	}
	else if (num == 1) {
		return ret = 1;
	}

    return 0;
}

int main(void)
{
    int T;
    cin >> T;
    
    for(int i = 0; i < T; ++i){
        int num;
        cin >> num;
        vector<int> cache(num, -1);

        cout << calculate(num, cache) << endl;
    }

    return 0;
}