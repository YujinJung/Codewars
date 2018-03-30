#include <string>

std::string news_is_false(const std::string& news)
{
  std::string comp = "abigail";
  int index = 0;  // index in news
  
  for(auto& e : comp)
  {
    if(index == news.size())
      return "NO";
      
    while(index < news.size())
    {
      if(e == news[index])
      {
        index++;
        break;
      }
      index++;
    }
  }
  
  // When 'l' is the last position
  if(index == news.size() && news.back() != comp.back())
    return "NO";

  return "YES";
}

