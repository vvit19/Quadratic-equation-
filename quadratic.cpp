#include "tests.h"
#include "solver.h"
#include "io.h"
#include "cmd_arg.h"
#include <cstdio>
#include <cassert>

int runner(ProgrammMode mode, FILE* file);
int run_solver();

int main(int argc, char** argv) 
{
    FILE* file = nullptr;
    ProgrammMode mode = check_input(argc, argv, &file);
    runner(mode, file);
}

int runner(ProgrammMode mode, FILE* file)
{  
    switch (mode)
    {
    case TESTS:
        assert(file);
        return run_all_tests(file);
        break;
    case HELP:
        return help_cmd();
    case SOLVE:
        return run_solver();
        break;
    default:
        return -1;
        break;
    }
}

int run_solver()
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
    return SOLVE_EQUATION;
}


