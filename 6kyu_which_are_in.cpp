class WhichAreIn
{

  public:
  
  static bool comp(std::string s1, std::string s2)
  {
    int s1_index = 0;
    int s2_index = 0;
    
    for(auto x : s2)
    {
      if(s1.at(s1_index) == x)
      {
        s1_index++;
        if(s1_index == s1.size()) return true;
      }
      else
      {
        s1_index = 0;
      }
      
      s2_index++;
    }
    
    if(s1_index == s1.size())
      return true;
    
    return false;
  }
  static std::vector<std::string> inArray(std::vector<std::string> &array1, std::vector<std::string> &array2)
  {
    std::vector<std::string> result;
    
    for(auto x : array1)
    {
      for(auto y : array2)
      {
        if(comp(x, y))
        {
          result.push_back(x);
          break;
        }
      }
    }
    
    std::sort(result.begin(), result.end());
    return result;
  }
  
};
