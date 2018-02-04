#include <set>

class DoubleLinear
{
public:
    static int dblLinear(int n)
    {
      if(n == 0) return 1;
      std::set<int> s;
      s.insert(1);
      int i = 1;
      int max = 987654321;
      
      for(std::set<int>::iterator iter = s.begin(); i <= max;)
      {
        s.insert(i);
        s.insert(i*2 + 1);
        s.insert(i*3 + 1);
        iter++;
        i = *iter;
        if(s.size() > n + 1 && max == 987654321)
          max = ((*iter) * 3 + 1) / 2;
        
          
      }
      
      int res = 0; 
      i = 0;
      for(auto iter = s.begin(); iter != s.end(); iter++, i++)
        if(i == n) res = *iter;
      
      return res;
    }
};