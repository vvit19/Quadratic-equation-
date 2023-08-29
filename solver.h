#ifndef SOLVER_H_
#define SOLVER_H_

/// @brief Number of roots
enum RootsNum {
    ZERO_ROOTS = 0, ///< 0 roots
    ONE_ROOT   = 1, ///< 1 root
    TWO_ROOTS  = 2, ///< 2 roots
    INF_ROOTS  = 3  ///< Infinity roots
}; 

/// @brief Solves quadratic equaton (ax^2 + bx + c = 0)
/// @param a Coefficient a
/// @param b Coefficient b
/// @param c Coefficient c
/// @param x_1 First root 
/// @param x_2 Second root
/// @return Number of equation roots
RootsNum solve_quadratic(double a, double b, double c, double* x_1, double* x_2);

/// @brief Solves linear equation (ax + b = 0)
/// @param a Coefficient a
/// @param b Coefficient b
/// @param x_1 Equation root
/// @return Number of equation roots
RootsNum solve_linear(double a, double b, double* x_1);

/// @brief Runs program in SOLVE mode
void run_solver();

#endif