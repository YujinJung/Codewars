#include <vector>

std::vector<int> beggars(const std::vector<int>& values, unsigned int n){

  if (n == 0) return {};

  std::vector<int> result(n, 0);
  
  int i = 0;
  for(auto& e : values)
  {
    if(i == n) i = 0;
    
    result[i] += e;
    
    ++i;
  }
  
  return result;
}