typedef long long ll;

class Johnann
{
public:
  static void vectorJA(std::vector<ll> &j, std::vector<ll> &a, const int &n)
  {
    j.push_back(0);
    a.push_back(1);

    for (ll i = 1; i < n; i++)
    {
      j.push_back(i - a.at(j.at(i - 1)));
      a.push_back(i - j.at(a.at(i - 1)));
    }
  }
  static std::vector<ll> john(ll n)
  {
    std::vector<ll> j, a;
    vectorJA(j, a, n);
    return j;
  }
  static std::vector<long long> ann(long long n)
  {
    std::vector<ll> j, a;
    vectorJA(j, a, n);
    return a;
  }
  static long long sumJohn(long long n)
  {
    std::vector<ll> j, a;
    j.push_back(0);
    a.push_back(1);

    ll result = j.at(0);
    for (ll i = 1; i < n; i++)
    {
      j.push_back(i - a.at(j.at(i - 1)));
      a.push_back(i - j.at(a.at(i - 1)));
      result += i - a.at(j.at(i - 1));
    }
    return result;
  }
  static long long sumAnn(long long n)
  {
    std::vector<ll> j, a;
    j.push_back(0);
    a.push_back(1);

    ll result = a.at(0);
    for (ll i = 1; i < n; i++)
    {
      j.push_back(i - a.at(j.at(i - 1)));
      a.push_back(i - j.at(a.at(i - 1)));
      result += i - j.at(a.at(i - 1));
    }
    return result;
  }
};
