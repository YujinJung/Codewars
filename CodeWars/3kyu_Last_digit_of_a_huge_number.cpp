#include <list>
#include <iostream>

using namespace std;
int last_digit(list<int> array) 
{
  if(array.size() == 0) return 1;
  
  
  int result, powN;
  
  int n1 = array.front(); array.pop_front();
  if(array.empty()) return n1 % 10;
  int n2 = array.front(); array.pop_front();
  
  // array size is 2
  if(array.size() == 0)
  {
    if(n2 == 0) return 1;
    if(n1 == 0) return 0;
    if(n1 == 1) return 1;
    if(n2 == 1) return n1 % 10;
    
    powN = n2 % 4;
  }
  else
  {
    int n3 = array.front(); array.pop_front();
    
     // array size is 3
    if(array.size() == 0)
    {
      if(n3 == 0) n2 = 1;
      if(n2 == 0) n1 = 1;
      if(n1 == 0) return 0;
      if(n2 == 1) return n1 % 10;
      if(n1 == 1) return 1;
    
      if(n3 == 0) return n1 % 10;
      
      if(n3 == 1)
      {
        powN = n2 % 4;
      }
      else if(n3 % 2 == 1)
      {
        if(n2 % 2 == 0) powN = 0; 
        else  powN = n2 % 4;
      }
      else
      {
        if(n2 % 2 == 0) powN = 0;
        else powN = 1;
      }
    }
    else// array size is over 4
    {
      int n4 = array.front(); array.pop_front();
     
      // calculate elements after 4th
      if(!array.empty())
      {
        int back = array.back(); array.pop_back();
        
        while(!array.empty())
        {
          int down = array.back(); array.pop_back();
          if(back == 0) down = 1;
          back = down;      
        }
        
       if(back == 0) n4 = 1;
      }
      
      if(n4 == 0) n3 = 1;
      if(n3 == 0) n2 = 1;
      if(n2 == 0) n1 = 1;
      
      if(n1 == 0) return 0;
      if(n2 == 1) return n1 % 10;
      if(n1 == 1) return 1;
     
      if(n4 == 0)
      {
        powN = n2 % 4;
      }
      else
      {
        if(n3 == 0)
        {
          return n1 % 10;
        }
        
        if(n3 == 1)
        {
          powN = n2 % 4;
        }
        else if(n3 % 2 == 1)
        {
          if(n2 % 2 == 0)  powN = 0; 
          else  powN = n2 % 4; 
        }
        else
        {
          if(n2 % 2 == 0) powN = 0;
          else powN = 1;
        }
      }
    }
  }
  
  // calculate last digit
  if (powN == 0) powN = 4;
  result = 1;
  n1 = n1 % 10;
  for(int i = 0; i < powN; ++i)
  {
    result = (result * n1) % 10;
  }
  
  return result;
}
