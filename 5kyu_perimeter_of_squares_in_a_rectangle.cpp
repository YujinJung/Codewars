typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n);
};

ull SumFct::perimeter(int n)
{
  ull sum = 2;
  ull first = 1, second = 1;
  ull temp = 0;
  
  if(n <= 0) return 0; 
  
  for(int i = 1; i < n; i++) {
    temp = first;
    first = second;
    second += temp;
    
    sum += second;
  }
  
  sum = sum<<2;
  
  return sum;
}