#include <iostream>
using namespace std;

int main(void)
{
    while(true) {
        int n[4];
        int ret[16];
        int result;

        cin >> n[0];
        if(n[0] == -1) break;

        cin >> n[1] >> n[2] >> n[3] >> result;

        // 1 4 16 64
        int num = 1;
        ret[0] = n[0];
        for(int i = 1; i < 3; ++i) {
            for(int j = 0; j < num; ++i) {
                int temp = ret[0];
                ret[4 * j] =  temp + n[i];
                ret[4 * j + 1] =  temp - n[i];
                ret[4 * j + 2] =  temp * n[i];
                ret[4 * j + 3] =  temp / n[i];
            }
            num *= 4;
        }

        bool ok = false;
        for(int i = 0; i < 16; ++i){
            if(ret[i] + n[3] == result)
                ok = true;
            if(ret[i] - n[3] == result)
                ok = true;
            if(ret[i] / n[3] == result)
                ok = true;
            if(ret[i] * n[3] == result)
                ok = true;

            if(ok)break;
        }

        if(ok)
                cout << "OK!" << endl;
        else
            cout << "NO!" << endl;
    }
}