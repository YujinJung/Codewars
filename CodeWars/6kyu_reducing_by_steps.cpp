#include <vector>

class Operarray
{
public:
    static long long gcdi(long long x, long long y)
    {
      x = x < 0 ? -x : x;
      y = y < 0 ? -y : y;
      
      int ret = 1;
      for(int i = 2; i <= x && i <= y; ++i)
      {
        if(x % i == 0 && y % i == 0)
        {
          ret = i;
        }
      }
      return ret;
    }
    static long long lcmu(long long x, long long y)
    {
      x = x < 0 ? -x : x;
      y = y < 0 ? -y : y;
      
      for(int i = 1; i <= y; ++i)
      {
        for(int j = 1; y * j <= x * i; ++j)
        {
          if(y * j == x * i)
            return y * j;
        }
      }
      return x * y;
    }
    static long long som(long long a, long long b)
    { return a + b; }
    static long long maxi(long long a, long long b)
    { return a > b ? a : b; }
    static long long mini(long long a, long long b)
    { return a < b ? a : b; }
    
    template<typename Func>
    static std::vector<long long> operArray(Func func, std::vector<long long> &arr, long long init)
    {
        std::vector<long long> ret;
        long long result = init;
        
        for(auto& e : arr)
        {
          init = func(init, e);
          ret.push_back(init);
        }
        return ret;
    }
};