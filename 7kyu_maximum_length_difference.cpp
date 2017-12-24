class MaxDiffLength
{
public:
    static int mxdiflg(std::vector<std::string> &a1, std::vector<std::string> &a2)
    {  
      int max = 0;
      if(a1.size() == 0 || a2.size() == 0) return -1;
      
      for(int i = 0; i < a1.size(); i++)
      {
        int a1_size = a1.at(i).size();
        for(int j = 0; j < a2.size(); j++)
        {
          int diff = a1_size - a2.at(j).size();
          diff = diff < 0 ? -1 * diff : diff;
          
          if(max < diff) max = diff;
        }
      }
      return max;
    }
};