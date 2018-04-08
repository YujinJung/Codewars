std::vector<int> sqrtApproximation(double number) 
{
  double a = 1;
  
  if(number == 0) return { 0 };
  
  while(a * a <= number)
  {
    if(a * a == number) return { a };
    a++;
  }
  
  return { a-1, a };
}
