#include "quadratic.h"
#include <cstdio>
#include <cmath>

bool is_equal(double a, double b) 
{
    const double EPS = 1e-10;
    return fabs(a - b) < EPS;
}

bool is_zero(double a)
{
    return is_equal(a, 0);
}

void clean_buffer() {
    int ch;
    while ((ch = getchar()) != '\n') 
        { }
}