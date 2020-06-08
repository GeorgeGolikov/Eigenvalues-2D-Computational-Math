#include "matrix_eigenvalues2D.hpp"
#include "solve_square_equation.hpp"
#include <stdexcept>

// only for 2*2 matrix!
std::vector<double> matrix_eigenvalues2D(const std::vector<double> & matrix,
                                         int rows, int columns)
{
  if (matrix.size() != rows * columns || rows != columns || rows != 2)
  {
    throw std::invalid_argument("Given rows and columns does not match the matrix!"
                                "Remember that the matrix must be 2*2.\n");
  }
  else
  {
    /* the function solve_square_equation() calculates
    the roots of the square equation "det(matrix - eigenvalue*E) = 0"
    which are the required eigenvalues of the given matrix */
    return std::move(solve_square_equation(1, -1*(matrix[0]+matrix[3]),
                                           ((matrix[0]*matrix[3])-(matrix[1]*matrix[2]))));
  }
}
