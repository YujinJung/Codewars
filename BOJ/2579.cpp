/*
    1. 계단은 한 번에 한 계단 씩 또는 두 계단 씩 오를 수 있다.
        즉 한 계단을 밟으면서 이어서 다음 계단이나 다음다음 계단으로 오를 수 ㅣ있다.
    2. 연속된 세 개의 계단을 모두 밟아서는 안된다. 단 시작점은 포함되지 않는다.
    3 . 마지막 도착계단은 반드시 밟아야한다.
 */

#include <iostream>
#include <vector>

using namespace std;

int max(int n, int m)
{
    return n > m ? n : m;
}

int calculate(const vector<int>& stair, vector<int>& score, int num, int onestep)
{
    int curScore = stair[num - 1];
    int& ret = score[num - 1];
   
    if(ret != -1) return ret;

    if(num + 1 == stair.size()) {
        if (onestep < 2)
            return ret = curScore + stair.back();
    }
    else if(num + 2 == stair.size()) {
        if(onestep == 0)
            ret = curScore + calculate(stair, score, num + 1, onestep + 1);
        
        return ret = curScore + stair.back();
    }
    else {
        if (onestep < 2)
            ret = curScore + calculate(stair, score, num + 1, onestep + 1);
        ret = max(ret, curScore + calculate(stair, score, num + 2, 0));
    }

    return ret;
}

int main(void)
{
    int T;
    cin >> T;
    
    vector<int> stair;
    vector<int> cache(T, -1);
    for(int i = 0; i < T; ++i){
        int temp;
        cin >> temp;
        stair.push_back(temp);
    }

    cout << calculate(stair, cache, 1, 0) << endl;
}