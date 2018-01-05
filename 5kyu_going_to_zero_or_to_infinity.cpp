class Suite
{
public:
  static double going(int n)
  {
    double result = 0;

    if (n == 0)
      return 0;
    if (n == 1)
      return 1;

    for (int i = 2; i <= n; i++)
      result = (result + 1) / i;

    int temp = result * 1000000;
    double dTemp = temp;
    result = (dTemp / 1000000);

    return result + 1;
  }
};
