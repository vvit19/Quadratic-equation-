#include "quadratic.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

void read_coeff(double* coeff, char ch) 
{
    assert(coeff);
    printf("%c = ", ch);
    while (scanf("%lf", coeff) != 1) 
    {
        printf("Incorrect input! Input number once again!\n");
        clean_buffer();
        printf("%c = ", ch);
    }
    if (!isfinite(*coeff)) 
    {
        printf("Very big coefficient! Input it once again\n");
        read_coeff(coeff, ch);
    }
}

void output_solutions(nRoots nroots, double x_1, double x_2) {
    switch (nroots)
    {
    case ZERO_ROOTS:
        printf("no real solutions\n");
        break;
    case ONE_ROOT:
        printf("x = %.3f\n", x_1);
        break;
    case TWO_ROOTS:
        printf("x_1 = %.3f\nx_2 = %.3f\n", x_1, x_2);
        break;
    case INF_ROOTS:
        printf("(-oo, +oo)\n");
        break;
    default:
        assert(0 && "Unknown number of roots.\n");
        break;
    }
}


