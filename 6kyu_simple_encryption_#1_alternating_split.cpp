std::string encrypt(std::string text, int n)
{
    std::vector<std::string> v(2);
    std::string result = text;
    
    for(int i = 0; i < n; i++)
    {
      int j = 0;
      for(auto x : result)
      {
        v.at(j).push_back(x);     
        j = (j+1) % 2;
      }
      result = "";
      result = v.at(1) + v.at(0); 
      v.at(0) = v.at(1) = "";
    }
    
    return result;
}

std::string decrypt(std::string encryptedText, int n)
{
    if(n <= 0) return encryptedText;
    
    std::string result;
    std::string text = encryptedText;
    std::string s1, s2;
    int mid = text.size() / 2;
    
    for(int i = 0; i < n; i++)
    {
      result = "";
      if(text.size() % 2 == 1)
      {
        s1 = text.substr(0, mid);
        s2 = text.substr(mid, mid + 1);
      }
      else
      {
        s1 = text.substr(0, mid);
        s2 = text.substr(mid, mid);
      }
      
      int j = 0;
      for(; j < s1.size(); j++)
      {
        result.push_back(s2.at(j));
        result.push_back(s1.at(j));
      }
      
      if(s2.size() > s1.size())
        result.push_back(s2.at(j));
        
      text = result;
    }
    
    return result;
}