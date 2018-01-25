#include <algorithm>

class Kata
{
public:
    std::vector<int> sortArray(std::vector<int> array)
    {
      std::vector<int> v1;
      
      auto iter = array.begin();
      
      for( ; iter != array.end(); iter++)
      {
        if(*iter % 2 == 1)
        {
          v1.push_back(*iter);
          *iter = 987654321;
        }
      }
      
      std::sort(v1.begin(), v1.end());
      
      iter = array.begin();
      int i = 0;
      
      for( ; iter != array.end(); iter++)
      {
        if(*iter == 987654321)
        {
          *iter = v1.at(i);
          i++;
        }
      }
      
      return array;
    }
};