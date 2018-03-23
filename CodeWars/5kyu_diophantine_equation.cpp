#include <vector>
#include <cmath>
#include <utility>

class Dioph
{
  public:
  static std::vector<std::pair <long, long>> solEquaStr(long long n)
  {
    std::vector<std::pair <long, long>> result;
    int max = std::sqrt(n);
    
    long long xMinus2y = 0;
    long long xPlus2y = 0;
    long long x, y;
    
    for(int i = 1; i < max; ++i)
    {
      int temp = n % i;
      if(n % i == 0)
      {
        xMinus2y = i;
        xPlus2y = n / i;
        if((xPlus2y + xMinus2y) % 2 == 0 && (xPlus2y - xMinus2y) % 4 == 0)
        {
          x = (xPlus2y + xMinus2y) / 2;
          y = (xPlus2y - xMinus2y) / 4;
          
          result.push_back(std::make_pair(x, y));
        }
      }
    }
    
    return result;
  }
};

// n = (x - 2*y)(x + 2*y)
// x + 2*y = n / (x - 2*y)
// x - 2*y = ?