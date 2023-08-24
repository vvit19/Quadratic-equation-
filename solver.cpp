#include "solver.h"
#include "quadratic.h"
#include "utils.h"
#include <cstdio>
#include <cmath>
#include <cassert>

RootsNum solve_quadratic(double a, double b, double c, double* x_1, double* x_2) 
{
    assert(x_1);
    assert(x_2);

    if (is_zero(a)) 
    {
        return solve_linear(b, c, x_1);
    }

    double discriminant = discriminant_calculation(a, b, c);

    if (discriminant < 0) 
    {
        return ZERO_ROOTS;
    }

    *x_1 = (- b + sqrt(discriminant)) / (2 * a);

    if (is_zero(discriminant)) 
    {
        return ONE_ROOT;
    }

    *x_2 = (- b - sqrt(discriminant)) / (2 * a);
    return TWO_ROOTS;
}

RootsNum solve_linear(double a, double b, double* x_1) 
{ 
    assert(x_1);

    if (is_zero(a)) 
    {
        if (is_zero(b)) 
        {
            return INF_ROOTS;
        }
        return ZERO_ROOTS;
    }

    *x_1 = - b / a;
    return ONE_ROOT;
}

double discriminant_calculation(double a, double b, double c) 
{
    return b * b - 4 * a * c;
}


