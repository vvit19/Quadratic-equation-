#ifndef TESTS_H_
#define TESTS_H_

#include <cstdio>
#include "solver.h"

struct UnitTest {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    RootsNum roots;
};

int run_all_tests(FILE* file);

#endif