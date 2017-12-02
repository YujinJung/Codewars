/*
 * In this Kata, you will implement The Luhn Algorithm, which is used to help validate credit card numbers.
 * 
 * Given a positive integer of up to 16 digits, return true if it is a valid credit card number, and false if it is not.
 * 
 * Here is the algorithm:
 * 
 * 1.
 * If there are an even number of digits, double every other digit starting with the first, and if there are an odd number of digits, double every other digit starting with the second. Another way to think about it is, from the right to left, double every other digit starting with the second to last digit.
 * 
 * 1714 => [1*, 7, 1*, 4] => [2, 7, 2, 4]
 * 12345 => [1, 2*, 3, 4*, 5] => [1, 4, 3, 8, 5]
 * 891 => [8, 9*, 1] => [8, 18, 1]
 * 
 * 
 * 2.
 * If a resulting doubled number is greater than 9, replace it with either the sum of it's own digits, or 9 subtracted from it.
 * 
 * [8, 18*, 1] => [8, (1+8), 1] => [8, 9, 1]
 * (or)
 * [8, 18*, 1] => [8, (18-9), 1] => [8, 9, 1]
 * 
 * 
 * 3.
 * Sum all of the final digits
 * 
 *  [8, 9, 1] => 8+9+1 => 18
 * 
 * 
 * 4.
 * Finally, take that sum and divide it by 10. If the remainder equals zero, the original credit card number is valid.
 * 
 *  18 (modulus) 10 => 8.  
 *  8 does not equal 0, so 891 is not a valid credit card number.
 */

class Kata {
  public:
  static bool validate(long long int n) {
    bool flag = false;
    int index = 0;
    int sum = 0;
    
    while(n != 0)
    {
      index = n % 10;
      n /= 10;
      if(flag)
      {
        flag = false;
        index *= 2;
        if(index >= 10)
        {
          sum += index % 10;
          index /= 10;
        }
        sum += index;
      }
      else
      {
        flag = true;
        sum += index;
      }
    }
    
    if((sum % 10) == 0) return true;
    
    return false;
  }
};