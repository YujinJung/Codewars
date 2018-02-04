#include <vector>
#include <string>
typedef long long ll;

class Thirteen
{
public:
  static ll thirt(long long n)
  {
    std::vector<int> remainder(1, 1);
    std::vector<int> num;
    ll number = n;

    getVector(num, number);
    getRemain(remainder, num.size());

    ll sum = 0;
    while (num.size() > 2)
    {
      sum = 0;
      for (int i = 0; i < num.size(); i++)
      {
        sum += num.at(i) * remainder.at(i);
        std::cout << num.at(i) << "*" << remainder.at(i) << " : ";
        std::cout << sum << std::endl;
      }
      std::cout << sum << std::endl;
      getVector(num, sum);
    }

    return sum;
  }

  static void getVector(std::vector<int> &num, int number)
  {
    num.clear();
    while (number != 0)
    {
      num.push_back(number % 10);
      number /= 10;
    }
  }

  static void getRemain(std::vector<int> &remainder, const int &num)
  {
    for (int i = 1; i < num; i++)
    {
      int temp = remainder.back() * 10;
      std::cout << "remain: " << temp << std::endl;
      remainder.push_back(temp % 13);
    }
  }
};