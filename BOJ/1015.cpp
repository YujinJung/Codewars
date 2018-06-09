#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<pair<int, int> > input;
    for(int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        input.push_back(make_pair(temp, i));
    }

    sort(input.begin(), input.end());

    vector<int> output(N);
    for(int i = 0; i < N; ++i)
        output[input[i].second] = i;

    for(int i = 0; i < N; ++i)
        cout<<output[i]<<" ";

    return 0;
}