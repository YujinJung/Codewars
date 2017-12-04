/* 
 * https://www.codewars.com/kata/steps-in-primes/cpp
 *  
 * g = steps / m = start / n = end
 * 
 */


#include <vector>
#include <iostream>
#include <utility>

class StepInPrimes
{
public:
    // if there are no such primes return {0, 0}
    static std::pair <long long, long long> step(int g, long long m, long long n);
};

bool isPrime(long long a)
{
  if(a % 2 == 0) return false;
  for(long long i = 3; i * i <= a; i = i + 2)
  {
    if(a != i && a % i == 0) 
      return false;
  }
  
  return true;
}

std::pair <long long, long long> StepInPrimes::step(int g, long long m, long long n)
{
  std::pair <long long, long long> ret;
  
  for(long long i = m + g; i < n; i++)
  {
    if(isPrime(i - g) && isPrime(i)) 
      return std::make_pair(i - g, i);
  }
  
  ret = std::make_pair(0, 0);
  return ret;
}

void dotest(int g, long long m, long long n, std::pair<long long, long long> expected)
{
    StepInPrimes s;
    std::pair<long long, long long> print = s.step(g, m, n);
    if(expected == print) std::cout << "true : ";
    else std::cout << "false : ";
    std::cout<<"{"<<print.first<<", "<<print.second<<"}"<<std::endl;
}

int main(void)
{
    dotest(2, 100, 110, {101, 103});
    dotest(11,30000,100000, {0, 0});
    dotest(2,2,50, {3, 5});
    dotest(4,100,110, {103, 107});
    dotest(6,100,110, {101, 107});
    dotest(8,300,400, {359, 367});
    dotest(10,300,400, {307, 317});

    return 0;
}