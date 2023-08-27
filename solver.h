#ifndef SOLVER_H_
#define SOLVER_H_

enum RootsNum {
    ZERO_ROOTS = 0,
    ONE_ROOT   = 1,
    TWO_ROOTS  = 2,
    INF_ROOTS  = 3
}; 

enum ResultStatus {
    RUN_TESTS = 0,
    SOLVE_EQUATION = 0, 
    GIVE_INFO = 0,
    TESTS_ERROR = 1
};

RootsNum solve_quadratic(double a, double b, double c, double* x_1, double* x_2);
RootsNum solve_linear(double a, double b, double* x_1);

#endif