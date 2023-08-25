#ifndef TESTS_H_
#define TESTS_H_
#include "solver.h"

struct UnitTest {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    RootsNum roots;
};

void run_all_tests();

#endif