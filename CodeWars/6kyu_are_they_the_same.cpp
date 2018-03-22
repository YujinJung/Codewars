#include <algorithm>
#include <vector>

class Same {
public :
    static bool comp(std::vector<int> a, std::vector<int> b)
    {
      if(a.size() == 0 && b.size() == 0) return true;
      if(a.size() == 0 || b.size() == 0) return false;
      
      for(int i = 0; i < a.size(); ++i)
        a[i] = a[i] * a[i];
      
      std::sort(a.begin(), a.end());
      std::sort(b.begin(), b.end());
      
      while(!a.empty())
      {
        if(a.back() == b.back())
        {
          a.pop_back();
          b.pop_back();
        }
        else
          return false;
      }
      return true;
    }
};