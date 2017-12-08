/*
 * Write a function that accepts a square matrix (n x n 2D array) and returns the determinant of the matrix.
 * 
 * How to take the determinant of a matrix -- it is simplest to start with the smallest cases: A 1x1 matrix |a| has determinant a. A 2x2 matrix [[a, b], [c, d]] or
 * 
 *  * |a b|
 *  * |c d|
 * 
 * has determinant ad - bc.
 * 
 * The determinant of an n x n sized matrix is calculated by reducing the problem to the calculation of the determinants of n n-1 x n-1 matrices. For the 3x3 case, [[a, b, c], [d, e, f], [g, h, i]] or
 * 
 *  * |a b c|
 * |d e f|
 * |g h i|
 * 
 * the determinant is: a * det(a_minor) - b * det(b_minor) + c * det(c_minor) where det(a_minor) refers to taking the determinant of the 2x2 matrix created by crossing out the row and column in which the element a occurs, or
 * 
 *  * |e f|
 *  * |h i|
 * 
 * Note the alternation of signs.
 * 
 * The determinant of larger matrices are calculated analogously, e.g. if M is a 4x4 matrix with first row [a, b, c, d], det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d * det(d_minor)
 */

#include <iostream>
#include <vector>

using namespace std;

long long determinant(vector< vector<long long> > m) {
  // if not n*n matrix return 0;
  if(m.size() < 1) return 0;
  if(m.size() != m.at(0).size()) return 0;
  
  // size is 1, return element
  if(m.size() == 1)  return m.at(0).at(0);

  // For each element in the first row, create a new matrix(x_minor) that removes the element's columns and rows.
  // and find a new matrix's determinant.
  // if M is a 4x4 matrix with first row [a, b, c, d], 
  // det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d * det(d_minor)
  int minus = 1;
  long long result = 0;
  for(int i = 0; i < m.at(0).size(); i++)
  {
    vector<vector<long long> > subMatrix;
    for(int j = 1; j < m.size(); j++)
    {
      vector<long long> cof;
      for(int k = 0; k < m.at(0).size(); k++)
      {
        if(k == i) continue;
        cof.push_back(m.at(j).at(k));
      }
      subMatrix.push_back(cof);
    }
    result += minus*m.at(0).at(i)*determinant(subMatrix);
    minus *= -1;
  }
  
  return result;
}