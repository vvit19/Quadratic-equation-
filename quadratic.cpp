#include "quadratic.h"
#include "tests.h"
#include "solver.h"
#include "io.h"
#include <cstdio>
#include <cmath>
#include <cassert>

/*const int USER_PROGRAMMER = 1;
const int USER_NOT_PROGRAMMER = 0;*/

int main(/*int argc, char** argv*/) 
{
    /*if (check_input(argc, argv, "--help"))
    {
        printf("Print --test to run unit tests\n"
               "Print --help to learn about flags\n");
    }

    if (check_input(argc, argv, "--test"))
    {
        run_all_tests();
        return USER_PROGRAMMER;
    }*/
    run_all_tests();
    
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
    
    return 0;
}

/*bool check_input(int len, char **input, char* text)
{
    for (int i = 1; i < len; i++) 
    {
        char* ptr_input = input[i];
        char *ptr_text = text;
        for (int j = 0; *ptr_input++ = *ptr_text++; j++)
        {
            if (*ptr_input == '\0') return true;
        }
    }
    return false;
}*/
