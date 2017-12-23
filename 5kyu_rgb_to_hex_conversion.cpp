#include <iostream>
#include <string>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b);
  static std::string rgbToHex(int color);
};

std::string RGBToHex::rgbToHex(int originColor)
{
  std::string result = "";
  int color = originColor;
  
  if(color <= 0) return "00";
  if(color >= 255) return "FF";
  
  while(color != 0)
  {
    int remain = color % 16;
    color /= 16;
    if(remain < 10){
      result.insert(0, std::to_string(remain));
    }
    else if(remain == 10)
      result.insert(0, "A");
    else if(remain == 11)
      result.insert(0, "B");
    else if(remain == 12)
      result.insert(0, "C");
    else if(remain == 13)
      result.insert(0, "D");
    else if(remain == 14)
      result.insert(0, "E");
    else if(remain == 15)
      result.insert(0, "F");
  }
  
  if(originColor < 16) result.insert(0, "0");
  return result;
}

std::string RGBToHex::rgb(int r, int g, int b)
{
  std::string result = "";
  result += rgbToHex(r);
  result += rgbToHex(g);
  result += rgbToHex(b);
  return result;
}
