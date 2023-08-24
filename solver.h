#ifndef QUADRATIC_H_
#include "quadratic.h"
#define QUADRATIC_H_
#endif

#ifndef SOLVER_H_
#define SOLVER_H_

RootsNum solve_quadratic(double a, double b, double c, double* x_1, double* x_2);
RootsNum solve_linear(double a, double b, double* x_1);
double discriminant_calculation(double a, double b, double c);

#endif