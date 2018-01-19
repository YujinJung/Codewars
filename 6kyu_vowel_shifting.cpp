/*
 * You get a "text" and have to shift the vowels by "n" positions to the right.
 * (Negative value for n should shift to the left.)
 * "Position" means the vowel's position if taken as one item in a list of all vowels within the string.
 * A shift by 1 would mean, that every vowel shifts to the place of the next vowel.
 * 
 * Shifting over the edges of the text should continue at the other edge.
 * 
 * Example:
 * 
 * text = "This is a test!"
 * n = 1
 * output = "Thes is i tast!"
 * 
 * text = "This is a test!"
 * n = 3
 * output = "This as e tist!"
 * 
 * If text is null or empty return exactly this value.
 * Vowels are "a,e,i,o,u". 
 * 
 * 
 * Have fun coding it and please don't forget to vote and rank this kata! :-)
 * 
 * I have created other katas. Have a look if you like coding and challenges.
 */

#include <vector>
std::string vowelShift(std::string text, int n)
{
  std::vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

  std::vector<int> position;
  std::vector<char> str;

  for (int i = 0; i < text.size(); i++)
  {
    for (int j = 0; j < vowels.size(); j++)
    {
      if (text.at(i) == vowels.at(j))
      {
        position.push_back(i);
        str.push_back(text.at(i));
      }
    }
  }

  for (int i = 0; i < position.size(); i++)
  {
    int textPosition = position.at(i);
    n %= position.size();
    int strPosition = i - n;
    if (strPosition < 0)
      strPosition += position.size();
    text.at(textPosition) = str.at(strPosition);
  }

  return text;
}