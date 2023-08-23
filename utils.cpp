#include "quadratic.h"
#include <stdio.h>
#include <math.h>

bool is_equal(double a, double b) 
{
    return fabs(a - b) < EPS;
}

bool is_zero(double a)
{
    return fabs(a - 0) < EPS;
}

void clean_buffer() {
    int ch;
    while ((ch = getchar()) != '\n') 
        { }
}