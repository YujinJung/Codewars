#include <math.h>
#include <iostream>

typedef long long ll;
class ASum
{
  public:
    static ll findNb(ll m)
    {
        ll sq = sqrt(m);
        ll p = sq * sq;

        if (m != p)
            return -1;

        bool tf = false;
        ll ans;

        for (ll i = 1; i < 100000; i++)
        {
            if ((i * (i + 1)) / 2 == sq)
            {
                ans = i;
                tf = true;
                break;
            }
        }
        if (tf == false)
            return -1;
        if (tf == true)
            return ans;

        return -1;
    }
};