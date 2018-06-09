// 참고 : http://eine.tistory.com/37

#include <iostream>
#include <string>
using namespace std;

#define FAIL 9
const int dfa[10][2] = {
    {5, 1},
    {2, FAIL},
    {3, FAIL},
    {3, 4},
    {5, 7},
    {FAIL, 6},
    {5, 1},
    {8, 7},
    {3, 6},
    {FAIL, FAIL}
};

int main(void)
{
   int T;
   cin >> T;
   for(int i = 0; i < T; ++i)
   {
       string S;
       cin >> S;

       // (100+1+|01)+
       int state = 0;
       for(int i = 0; i < S.size(); ++i)
       {
           char temp = S[i] - '0'; // 0 1
           state = dfa[state][temp];
       }
       bool isPattern = (state == 4 || state == 6 || state == 7);

       cout << (isPattern ? "YES" : "NO") << endl;
   } 

    return 0;
}