/*
 * In this kata you have to create all permutations of an input string and remove duplicates, if present. This means, you have to shuffle all letters from the input in all possible orders.
 * 
 * Examples:
 * 
 *  * permutations("a"); // => vector<string> {"a"}
 *  * permutations("ab"); // => vector<string> {"ab", "ba"}
 *  * permutations("aabb"); // => vector<string> {"aabb", "abab", "abba", "baab", "baba", "bbaa"}
 * The order of the permutations doesn't matter.
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

void doPermutations(vector<string> &result, vector<pair<char, int>> &store, string &str)
{
  if (store.empty())
  {
    result.push_back(str);
    return;
  }

  vector<pair<char, int>> temp = store;

  for (int i = 0; i < store.size(); i++)
  {
    str += store.at(i).first;
    store.at(i).second--;
    if (store.at(i).second == 0)
      store.erase(store.begin() + i);

    doPermutations(result, store, str);
    store = temp;
    str.pop_back();
  }

  return;
}

void chkString(vector<pair<char, int>> &store, const string &s)
{
  vector<int> chk(s.size(), 0);
  for (int i = 0; i < s.size(); i++)
  {
    if (chk.at(i) == 1)
      continue;
    char sIn = s.at(i);
    int sNum = 1;
    for (int j = i + 1; j < s.size(); j++)
    {
      if (sIn == s.at(j))
      {
        chk.at(j) = 1;
        sNum++;
      }
    }
    store.push_back(make_pair(sIn, sNum));
  }
}

vector<string> permutations(string s)
{
  vector<pair<char, int>> store;
  vector<string> result;
  string k;

  chkString(store, s);
  doPermutations(result, store, k);

  return result;
}

  // Best Practice

#include <algorithm>
#include <string>
#include <vector>

std::vector<std::string> permutations(std::string s)
{
  std::sort(s.begin(), s.end());
  std::vector<std::string> result;
  do
  {
    result.push_back(s);
  } while (std::next_permutation(s.begin(), s.end()));
  return result;
}