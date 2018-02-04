/*
 * A friend of mine takes a sequence of numbers from 1 to n (where n > 0).
 * Within that sequence, he chooses two numbers, a and b.
 * He says that the product of a and b should be equal to the sum of all numbers in the sequence, excluding a and b.
 * Given a number n, could you tell me the numbers he excluded from the sequence?
 * The function takes the parameter: n (don't worry, n is always strictly greater than 0 and small enough so we shouldn't have overflow) and returns an array of the form:
 * 
 * [(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or or [{a, b}, ...]
 * with all (a, b) which are the possible removed numbers in the sequence 1 to n.
 * 
 * [(a, b), ...] or [[a, b], ...] or {{a, b}, ...} or ...will be sorted in increasing order of the "a".
 * 
 * It happens that there are several possible (a, b). The function returns an empty array if no possible numbers are found which will prove that my friend has not told the truth! (Go: in this case return nil).
 * 
 * (See examples for each language in "RUN EXAMPLES")
 * 
 * #Examples:
 * 
 * removNb(26) should return [(15, 21), (21, 15)]
 * or
 * 
 * removNb(26) should return { {15, 21}, {21, 15} }
 * or
 * 
 * removeNb(26) should return [[15, 21], [21, 15]]
 * or
 * 
 * removNb(26) should return [ {15, 21}, {21, 15} ]
 * or
 * 
 * in C:
 * removNb(26) should return  **an array of pairs {{15, 21}{21, 15}}**
 * tested by way of strings.
 */

#include <vector>

using namespace std;

class RemovedNumbers
{
public:
  static vector<vector<long long>> removNb(long long n);
};

// sum(1, n) - (n * (n + 1)) / 2
// x * y = (n * (n + 1)) / 2 - x - y
// x * y + y = (n ( n+1)) / 2 -x
// y(x+1)
// y = (sum(1, n) - x) / ( x + 1)

vector<vector<long long>> RemovedNumbers::removNb(long long n)
{
  long long sumOfFull = (n * (n + 1)) / 2;
  vector<vector<long long>> ret;
  for (int i = 1; i < n; i++)
  {
    // y = (sum(1, n) - x) / ( x + 1)
    // y = ((n * (n + 1)) / 2(x + 1) - x / (x + 1))
    long long y = (sumOfFull - i) / (i + 1);
    if ((sumOfFull - i) % (i + 1) != 0 || y > n || y < 0)
      continue;

    vector<long long> temp;
    temp.push_back(i);
    temp.push_back(y);
    ret.push_back(temp);
  }

  return ret;
}