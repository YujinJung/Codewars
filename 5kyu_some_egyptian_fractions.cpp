/*
 * Given a rational number n
 * 
 *  * - n >= 0, with denominator strictly positive -
 * 
 * as a string (example: "2/3" in Ruby, Python, Clojure, JS, CS) or as two strings (example: "2" "3" in Haskell, Java, CSharp, C++, Swift) decompose this number as a sum of rationals with numerators equal to one and without repetitions (2/3 = 1/2 + 1/6 is correct but not 2/3 = 1/3 + 1/3, 1/3 is repeated).
 * 
 * The algorithm must be "greedy", so at each stage the new rational obtained in the decomposition must have a denominator as small as possible. In this manner the sum of a few fractions in the decomposition gives a rather good approximation of the rational to decompose.
 * 
 * 2/3 = 1/3 + 1/3 doesn't fit because of the repetition but also because the first 1/3 has a denominator bigger than the one in 1/2 in the decomposition 2/3 = 1/2 + 1/6.
 * 
 * Example: (You can see other examples in "Test Examples")
 * 
 *  * decompose("21/23") or decompose "21" "23" 
 *  * should return ["1/2", "1/3", "1/13", "1/359", "1/644046"] in Ruby, Python, Clojure, JS, CS, Haskell
 *  * and "[1/2, 1/3, 1/13, 1/359, 1/644046]" in Java, CSharp, C++
 *  * and "1/2,1/3,1/13,1/359,1/644046" in C, Swift
 * 
 * The decomposition of 21/23 as
 * 
 *  * 21/23 = 1/2 + 1/3 + 1/13 + 1/598 + 1/897
 * 
 * is exact but don't fulfill our requirement because 598 is bigger than 359. Same for
 * 
 *  * 21/23 = 1/2 + 1/3 + 1/23 + 1/46 + 1/69 (23 is bigger than 13)
 *  * or 
 *  * 21/23 = 1/2 + 1/3 + 1/15 + 1/110 + 1/253 (15 is bigger than 13).
 * 
 * The rational given to decompose could be greater than one or equal to one, in which case the first "fraction" will be an integer (with an implicit denominator of 1).
 * 
 *  * If the numerator parses to zero the function "decompose" returns [] (or "").
 *  * The number could also be a decimal which can be expressed as a rational (ex: 0.6 in Ruby, Python, Clojure,JS, CS or "66" "100" in Haskell, Java, CSharp, C++, C, Swift).
 * Ref: http://en.wikipedia.org/wiki/Egyptian_fraction
 */

using namespace std;

// http://ohyecloudy.com/pnotes/archives/243/
template <typename TO, typename FROM>
TO NumberStringCast(const FROM &from)
{
  stringstream ss;
  ss << from;

  TO result;
  ss >> result;

  assert(!ss.fail() && !ss.bad() && ss.eof());
  if (ss.fail() || ss.bad() || !ss.eof())
  {
    // 예외 처리
  }

  return result;
}

class Decomp
{
public:
  static string decompose(const string &nrStr, const string &drStr);
  static void makeIrreducibleFraction(long long &nr, long long &dr);
};

void Decomp::makeIrreducibleFraction(long long &nr, long long &dr)
{
  long long i = 1;
  while (i < dr && i < nr)
  {
    i++;
    while (nr % i == 0 && dr % i == 0)
    {
      nr /= i;
      dr /= i;
    }
  }
}

string Decomp::decompose(const string &nrStr, const string &drStr)
{
  long long nr = NumberStringCast<long long, string>(nrStr);
  long long dr = NumberStringCast<long long, string>(drStr);

  makeIrreducibleFraction(nr, dr);
  string result = "[";

  if (nrStr == "1" || nr <= 0 || dr <= 0)
    return "[]";
  if (nr > dr)
  {
    result = result + NumberStringCast<string, long long>(nr / dr);
    nr %= dr;

    if (nr == 0)
      return result + "]";
    result += ", ";
  }

  long long dec = 0;
  while (nr != 1)
  {
    dec = dr / nr + 1;
    nr = nr * dec - dr;
    dr = dr * dec;

    if (nr != 1)
      makeIrreducibleFraction(nr, dr);

    result = result + "1/" + NumberStringCast<string, long long>(dec) + ", ";
  }

  result = result + NumberStringCast<string, long long>(nr) + "/" + NumberStringCast<string, long long>(dr) + "]";

  return result;
}