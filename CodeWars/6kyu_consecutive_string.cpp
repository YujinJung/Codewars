/*
 * You are given an array strarr of strings and an integer k. Your task is to return the first longest string consisting of k consecutive strings taken in the array.
 * 
 * #Example: longest_consec(["zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail"], 2) --> "abigailtheta"
 * 
 * n being the length of the string array, if n = 0 or k > n or k <= 0 return "".
 */

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

class LongestConsec
{
public:
  static std::string longestConsec(std::vector<std::string> &strarr, int k)
  {
    int n = strarr.size();

    if (n == 0 || k > n || k <= 0)
      return "";

    int max = 0;
    int firstIndex = 0;
    for (int i = 0; i < strarr.size() - k + 1; i++)
    {
      int sum = 0;
      for (int j = 0; j < k; j++)
        sum += strarr.at(i + j).size();

      if (sum > max)
      {
        max = sum;
        firstIndex = i;
      }
    }

    std::string s;
    for (int j = firstIndex; j < firstIndex + k; j++)
      s += strarr.at(j);

    return s;
  }
};