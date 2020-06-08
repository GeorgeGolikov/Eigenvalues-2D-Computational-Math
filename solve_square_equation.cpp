#include "solve_square_equation.hpp"
#include <cmath>
#include <iostream>

// the function returns the sign of the value
int sgn(int val)
{
   return (val>0)?(1):((val<0)?(-1):(0));
}

// the function returns the roots of the given equation in std::vector<>
std::vector<double> solve_square_equation(double a, double b, double c)
{
  double d = b*b - 4*a*c;

  switch(sgn(d))
  {
  case 1:
  {
    return std::vector<double>{(-b + std::sqrt(d)) / (2*a),
                               (-b - std::sqrt(d)) / (2*a)};
    break;
  }
  case 0:
  {
    return std::vector<double>{-b / (2*a), -b / (2*a)};
    break;
  }
  case -1:
  {
    std::cout << "\nBe careful! Roots are complex and output vector "
              << "has R-part of the roots in [0]-element and "
              << "I-part in [1]-element.\n";

    return std::vector<double>{-b / (2*a), std::sqrt(std::abs(d)) / (2*a)};
    break;
  }
  }
}
