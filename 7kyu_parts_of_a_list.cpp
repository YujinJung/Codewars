/*
 * Write a function partlist that gives all the ways to divide a list (an array) of at least two elements into two non-empty parts.
 * 
 * Each two non empty parts will be in a pair (or an array for languages without tuples or a structin C - C: see Examples test Cases - )
 * Each part will be in a string
 * Elements of a pair must be in the same order as in the original array.
 * Example:
 * 
 * a = ["az", "toto", "picaro", "zone", "kiwi"] -->
 * 
 * [["az", "toto picaro zone kiwi"], ["az toto", "picaro zone kiwi"], ["az toto picaro", "zone kiwi"], ["az toto picaro zone", "kiwi"]]
 * 
 * or
 * 
 * a = {"az", "toto", "picaro", "zone", "kiwi"} -->
 * 
 * {{"az", "toto picaro zone kiwi"}, {"az toto", "picaro zone kiwi"}, {"az toto picaro", "zone kiwi"}, {"az toto picaro zone", "kiwi"}}
 * 
 * or
 * 
 * a = ["az", "toto", "picaro", "zone", "kiwi"] -->
 * 
 * [("az", "toto picaro zone kiwi"), ("az toto", "picaro zone kiwi"), ("az toto picaro", "zone kiwi"), ("az toto picaro zone", "kiwi")]
 * 
 * or
 * 
 * a = [|"az", "toto", "picaro", "zone", "kiwi"|] -->
 * 
 * [("az", "toto picaro zone kiwi"), ("az toto", "picaro zone kiwi"), ("az toto picaro", "zone kiwi"), ("az toto picaro zone", "kiwi")]
 * 
 * You can see other examples for each language in "Your test cases"
 */

#include <vector>
#include <utility>

class PartList
{
public:
    static std::vector<std::pair <std::string, std::string>> partlist(std::vector<std::string> &arr)
    {
      std::vector<std::pair <std::string, std::string>> l;
      std::pair <std::string, std::string> p;
      int index = 0;
      while (index < arr.size() - 1) {
        std::string s1, s2;
        
        for (int i = 0; i <= index; i++)
          s1 += " " + arr[i];
          
        for (int i = index + 1; i < arr.size(); i++)
          s2 += " " + arr[i];
          
        p = std::make_pair(s1.substr(1), s2.substr(1));
        l.push_back(p);
        index++;
      }
      return l;
    }
};