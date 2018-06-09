#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i) 
    {
        long long x, y;
        cin >> x >> y;
        long long dist = y - x;
        long long sq = sqrt(dist);
        long long po = sq * sq;

        if(dist < 4)
        {
            cout << dist << endl;
            continue;
        }
        
        if(po == dist)
            cout << sq * 2 - 1 << endl;
        else if(po + sq < dist)
            cout << (sq + 1) * 2 - 1 << endl;
        else
            cout << sq * 2 << endl;
    }

    return 0;
}