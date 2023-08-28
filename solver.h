#ifndef SOLVER_H_
#define SOLVER_H_

/// @brief number of roots
enum RootsNum {
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_ROOTS  = 3
}; 

/// @brief solves quadratic equaton (ax^2 + bx + c = 0)
/// @param a coefficient a
/// @param b coefficient b
/// @param c coefficient c
/// @param x_1 first root 
/// @param x_2 second root
/// @return number of equation roots
RootsNum solve_quadratic(double a, double b, double c, double* x_1, double* x_2);

/// @brief solves linear equation (ax + b = 0)
/// @param a coefficient a
/// @param b coefficient b
/// @param x_1 equation root
/// @return number of equation roots
RootsNum solve_linear(double a, double b, double* x_1);

/// @brief runs program in SOLVE mode
void run_solver();

#endif