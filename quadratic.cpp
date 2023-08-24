#include "quadratic.h"
#include "tests.h"
#include "solver.h"
#include "io.h"
#include "comm_line_arg.h"
#include <cstdio>
#include <cmath>
#include <cassert>

const int USER_PROGRAMMER = 2;
const int USER_ASK_HELP = 1;
const int REGULAR_USER = 0;

int main(int argc, char** argv) 
{
    if (check_input(argc, argv, HELP))
    {
        help_cmd();
        return USER_ASK_HELP;
    }

    if (check_input(argc, argv, TEST))
    {
        test_cmd();
        return USER_PROGRAMMER;
    }

    main_solver();
    return REGULAR_USER;
}

void main_solver()
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


