/*
 * You are given an array (which will have a length of at least 3, but could be very large) containing integers. The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.
 * 
 * Examples

 * [2, 4, 0, 100, 4, 11, 2602, 36]
 * Should return: 11 (the only odd number)

 * [160, 3, 1719, 19, 11, 13, -21]
 * Should return: 160 (the only even number)
 */

#include <cmath>
#include <vector>

int FindOutlier(std::vector<int> arr)
{
  // vector length >= 3
  int result;
  
  int judgeStateNumber = 0;
  // 하나 섞여 있으면
  int zeroState = std::abs(arr[0]) % 2;
  int firstState = std::abs(arr[1]) % 2;
  int secondState = std::abs(arr[2]) % 2;
  if(zeroState == firstState)
    judgeStateNumber = zeroState;
  else if(zeroState + firstState + secondState == 1)
  {
    if(zeroState == 1) return arr[0];
    return arr[1];
  }
  else
  {
    if(zeroState == 0) return arr[0];
    return arr[1];
  }      
    
  for(int i = 2; i < arr.size(); i++)
    if((std::abs(arr.at(i)) % 2) != judgeStateNumber)
      return arr.at(i);
  
  return 0;
}