#include "tests.h"
#include "solver.h"
#include "io.h"
#include "cmd_arg.h"
#include <cstdio>

enum UserStatus {
    USER_SOLVE_Q,
    USER_USE_CMD
};

void run_solver();

int main(int argc, char** argv) 
{
    if (check_input(argc, argv) )
    {
        return USER_USE_CMD;
    }
    
    run_solver();
    return USER_SOLVE_Q;
}

void run_solver()
{
    printf("I'll solve equation: ax^2 + bx + c = 0\n");

    double a = 0; 
    double b = 0;
    double c = 0;
    double x_1 = 0;
    double x_2 = 0;

    read_coeff(&a, 'a'); 
    read_coeff(&b, 'b');
    read_coeff(&c, 'c');

    RootsNum solve = solve_quadratic(a, b, c, &x_1, &x_2);
    output_solutions(solve, x_1, x_2);
}


