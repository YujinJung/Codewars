#include <algorithm>

class BestTravel
{
public:
  static int chooseBestSum(int t, int k, std::vector<int> &ls)
  {
    if (ls.size() < k)
      return -1;
    std::sort(ls.rbegin(), ls.rend());

    int sum = 0, max = 0;
    for (int i = 0; i < k; i++)
      sum += ls.at(ls.size() - i - 1);

    if (sum > t)
      return -1;

    sum = 0;
    recursive(ls, sum, max, 1, 0, k, t);

    return max;
  }

  static void recursive(const std::vector<int> &ls, int &sum, int &max, int dimention, int order, const int &k, const int &t)
  {
    for (int i = order; i < ls.size(); i++)
    {
      sum += ls.at(i);

      if (dimention == k)
      {
        if (sum > t)
        {
          sum -= ls.at(i);
          continue;
        }
        else if (sum <= t)
          if (max < sum)
            max = sum;
      }
      if (dimention == 1)
        std::cout << std::endl;
      recursive(ls, sum, max, dimention + 1, i + 1, k, t);

      sum -= ls.at(i);
    }

    return;
  }
};
