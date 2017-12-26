
// 소문자로 되어 있다고 가정되어있는 상태인듯
// CaTTT_TeEEE 이런 것은 판별하지 못함.

#include <string>
#include <algorithm>

std::string to_camel_case(std::string text) {
  std::string result = "";
  char comp[2] = { '_', '-' };
  
  for(int i = 0; i < text.size(); i++)
  {
    std::cout<<"i: "<<i<<","<<comp[0]<<","<<text.at(i)<<std::endl;
    if(text.at(i) == comp[0] || text.at(i) == comp[1])
    {
      i++;
      char trans = text.at(i);
      std::cout<<trans<<std::endl;
      if(trans > 90)
        trans -= 32;
      result += trans;    
      continue;
    }
    result += text.at(i);
  }
  
  return result;
}