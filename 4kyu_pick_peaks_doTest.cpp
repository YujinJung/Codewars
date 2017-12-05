#include <iostream>
#include <vector>

class PeakData
{
private:
    std::vector<int> pos, peaks;

public:
    PeakData() { }
    PeakData(std::vector<int> posInput, std::vector<int> peaksInput)
    : pos(posInput), peaks(peaksInput)
    { }
    void pushPos(int input) { pos.push_back(input); }
    void pushPeaks(int input) { peaks.push_back(input); }
    std::vector<int> getPos () const { return pos; }
    std::vector<int> getPeaks () const { return peaks; }
    bool operator==(const PeakData& in)
    {
        if((in.getPos() == pos) && (in.getPeaks() == peaks))
          return true;
        return false;
    }
    void print() const
    {
        for(int i = 0; i < pos.size(); i++)
        {
            std::cout<<"pos : " << pos.at(i) << ", peaks : " << peaks.at(i) << std::endl;
        }
        std::cout<<std::endl<<std::endl;
    }
};

PeakData pick_peaks(std::vector<int> v) {
  PeakData result;
  // Your code here
  int pos = 0, peaks = 0;
  bool asc = false;
  
  if(v.size() < 3) return result;
  
  if(v.at(1) > v.at(0)) asc = true;
  
  for(int i = 1; i < v.size(); i++)
  {
    if(asc)
    {
      if(v.at(i-1) < v.at(i))
      {
        pos = i; peaks = v.at(i);
      }
      else if(v.at(i-1) > v.at(i))
      {
        result.pushPos(pos);
        result.pushPeaks(peaks);
        asc = false;
      } 
    }
    else
    {
      if(v.at(i-1) < v.at(i))
      {
        pos = i; peaks = v.at(i);
        asc = true;
      }
    }
  }
  
  return result;
}

void dotest(std::vector<int> v, std::vector<int> a, std::vector<int> b)
{
    PeakData result = pick_peaks(v);
    PeakData expected(a, b);


    if(expected == result) std::cout << "true : " << std::endl;
    else std::cout << "false : " << std::endl;

    result.print();
}

int main(void)
{
    dotest(std::vector<int> {1, 2, 3, 6, 4, 1, 2, 3, 2, 1}, std::vector<int> {3, 7}, std::vector<int> {6, 3});
    dotest(std::vector<int> {3, 2, 3, 6, 4, 1, 2, 3, 2, 1, 2, 2, 2, 1}, std::vector<int> {3, 7, 10}, std::vector<int> {6, 3, 2});
    dotest(std::vector<int> {2, 1, 3, 1, 2, 2, 2, 2, 1}, std::vector<int> {2, 4}, std::vector<int> {3, 2});
    dotest(std::vector<int> {1, 2, 5, 4, 3, 2, 3, 6, 4, 1, 2, 3, 3, 4, 5, 3, 2, 1, 2, 3, 5, 5, 4, 3}, std::vector<int> {2, 7, 14, 20}, std::vector<int> {5, 6, 5, 5});
    dotest(std::vector<int> {1, 1, 1, 1}, std::vector<int> {}, std::vector<int> {});
    dotest(std::vector<int> {4, 8, 7}, std::vector<int> {1}, std::vector<int> {8});

    return 0;
}