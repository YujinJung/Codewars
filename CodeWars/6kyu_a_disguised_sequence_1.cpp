class HiddenSeq
{
    public:
    typedef unsigned long long ull;
    static long long fcn(int n)
    {
      long long n0 = 1, n1 = 2;
      long long res = 0;
      
      if(n == 0) return 0;
      if(n == 1) return 1;
      if(n == 2) return 2;
      
      for(int i = 2; i <= n; ++i)
      {
        res = (n1/(5*(n0-0.2*n1)))*n0*6;
        n0 = n1;
        n1 = res;
      }
      
      return res;
    }
};