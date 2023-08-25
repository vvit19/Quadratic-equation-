#include "utils.h"
#include <cstdio>
#include <cmath>
#include <cassert>

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
    int ch = 0;
    while ((ch = getchar()) != '\n') 
        { }
}
