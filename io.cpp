#include "quadratic.h"
#include <cstdio>
#include <cmath>
#include <cassert>

void read_coeff(double* coeff, char ch) 
{
    assert(coeff);

    bool correct_input = false;
    printf("%c = ", ch);

    while (correct_input != true) 
    {
        if (scanf("%lf", coeff) != 1) 
        {
            printf("Incorrect input! Input number once again!\n");
            clean_buffer();
            printf("%c = ", ch);
            continue;
        }

        if (!std::isfinite(*coeff))
        {
            printf("Very big coefficient! Input it once again\n");
            continue;
        }

        correct_input = true;
    }
}

void output_solutions(RootsNum Nroots, double x_1, double x_2) {
    
    switch (Nroots)
    {
    case ZERO_ROOTS:
        printf("no real solutions\n");
        break;
    case ONE_ROOT:
        printf("x = %.3f\n", x_1);
        break;
    case TWO_ROOTS:
        printf("x_1 = %.3f\n"
               "x_2 = %.3f\n", 
               x_1, x_2);
        break;
    case INF_ROOTS:
        printf("(-oo, +oo)\n");
        break;
    default:
        assert(0 && "Unknown number of roots.\n");
        break;
    }
}


