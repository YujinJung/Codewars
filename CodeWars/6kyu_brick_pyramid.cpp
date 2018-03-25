class Pyramid {
  public:
  static double weight(int row, int pos) 
  {
    int down = 1;
    for(int i = 0; i < row; ++i)
    {
      down *= 2;
    }
    if(pos == 0 || pos == row)
      return (double)(down - 1) / down;
  
    int rem = row*(row+1)/2*down - (down-1)*2;
    rem /= (row-1);
    return (double)rem / down;
  }
};
