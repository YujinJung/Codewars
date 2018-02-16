
string kaCokadekaMe(string word)
{
    string vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vowelsSize = vowels.size();
    
    string result = "ka";
    int vowelChk = 0;
    
    for(int i = 0; i < word.size(); ++i)
    {
      int j = 0; 
      for(j = 0; j < vowelsSize; ++j)
      {
        if(word[i] == vowels[j])
          break;
      }
      
      cout<<j<<", "<<vowelsSize<<endl;
      // no vowel
      if(j == vowelsSize)
      {
        if(vowelChk == 1)
        {
          result += "ka";
          vowelChk = 0; 
        }
      }
      else // vowel
      {
        vowelChk = 1;
      }
      result.push_back(word[i]);
    }
  
    return result;
}