#include <vector>

class SqInRect
{
  public:
  static std::vector<int> sqInRect(int lng, int wdth)
  {
    std::vector<int> result;
    if(lng == wdth) return result; 
    
    int min, max;
    int area = 0;
    if(lng < wdth)
    {
      min = lng;
      max = wdth;    
    }
    else
    {
      min = wdth;
      max = lng;
    }
    area = min * max;
    
    while(area > 0)
    {
      area -= min * min;
      result.push_back(min);
      
      max = area / min;
      if(max < min)
      {
        int temp = min;
        min = max;
        max = temp;
      }
    }
   
    return result;
  }
};