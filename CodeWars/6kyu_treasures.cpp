#include <string>
#include <map>

using namespace std;

string unlock (string str)
{ 
  map<char, int> m;
  
  for(char i = 'a'; i <= 'z'; i++)
  {
    if(i < 'd')
      m[i] = 2;
    else if(i < 'g')
      m[i] = 3;
    else if(i < 'j')
      m[i] = 4;
    else if(i < 'm')
      m[i] = 5;
    else if(i < 'p')
      m[i] = 6;
    else if(i < 't')
      m[i] = 7;
    else if(i < 'w')
      m[i] = 8;
    else if(i <= 'z')
      m[i] = 9;
   
  }
  
  for(char i = 'A'; i <= 'Z'; i++)
  {
    if(i < 'D')
      m[i] = 2;
    else if(i < 'G')
      m[i] = 3;
    else if(i < 'J')
      m[i] = 4;
    else if(i < 'M')
      m[i] = 5;
    else if(i < 'P')
      m[i] = 6;
    else if(i < 'T')
      m[i] = 7;
    else if(i < 'W')
      m[i] = 8;
    else if(i <= 'Z')
      m[i] = 9;
  }
  
  string result = "";
  
  for(int j = 0; j < str.size(); j++)
    result += to_string(m[str.at(j)]);
    
  return result;
}