#include "tests.h"
#include "solver.h"
#include "utils.h"
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

bool test_solve_quadratic(UnitTest* test);
void run_test(UnitTest* test, int* counter_tests, int* counter_passed_tests);
void check_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);
bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected);
bool is_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);

const int test_size = 6; //amount of struct elements

void run_all_tests() 
{
    FILE* file = fopen("text.txt", "r");
    assert(file && "file not found");

    int max_file_size = calc_file_size(file);
    UnitTest* tests = (UnitTest*) malloc(max_file_size * sizeof(UnitTest));
    char* buffer = (char*) malloc(max_file_size * sizeof(char));

    int file_size = read_file(file, buffer, max_file_size);
    fclose(file);

    int ntests = 1;
    for (int i = 0; i < file_size; i++)
    {
        if (buffer[i] == '\n' || buffer[i] == EOF)
        {
            ntests++;
        }
    }

    int* symb_in_line = (int*) malloc(ntests * sizeof(int));
    calc_symb_line(symb_in_line, file_size, buffer);

    int shift = 0;
    for (int i = 0; i < ntests; i++)
    {
        sscanf((buffer + shift), "%lf %lf %lf %lf %lf %d",
              &((tests + i)->a),
              &((tests + i)->b),
              &((tests + i)->c),
              &((tests + i)->x1),
              &((tests + i)->x2),
              (int*)&((tests + i)->roots));

        shift += symb_in_line[i];
    }

    int counter_tests = 0;
    int passed_tests = 0;

    for (int i = 0; i < ntests; i++) 
    {
        UnitTest* test = &tests[i];
        run_test(test, &counter_tests, &passed_tests);
    }

    printf("Tests: %d\n"
           "Passed tests: %d\n", 
           counter_tests, passed_tests);
    free(tests);
    free(buffer);
    free(symb_in_line);
}

void run_test(UnitTest* test, int* counter_tests, int* counter_passed_tests) 
{
    assert(test);
    assert(counter_tests);
    assert(counter_passed_tests);

    *counter_tests += 1;
    printf("%d) ", *counter_tests);

    bool correct_test = test_solve_quadratic(test);

    if (correct_test) 
    { 
        *counter_passed_tests += 1; 
        printf("All right\n");
    }
}

bool test_solve_quadratic(UnitTest* test) 
{
    double a = test->a;
    double b = test->b;
    double c = test->c;
    double x1_expected = test->x1;
    double x2_expected = test->x2;
    RootsNum roots_expected = test->roots;
    
    double x1 = 0;
    double x2 = 0;
    RootsNum roots = solve_quadratic(a, b, c, &x1, &x2);

    return is_test_correct(x1, x1_expected, x2, x2_expected, roots, roots_expected);
}

bool is_test_correct(double x1, double x1_expected, double x2, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    if (is_roots_equal(x1, x2, x1_expected, x2_expected) && (int) roots == (int) roots_expected)
    {
        return true;
    }
    check_test_fail(x1, x2, x1_expected, x2_expected, roots, roots_expected);
    return false;
}

void check_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected)
{
    printf("Test failed\n");
    if (!is_equal(x1, x1_expected))
    {
        printf("x1 = %f != x1_expected = %f\n", x1, x1_expected);
    }

    if (!is_equal(x2, x2_expected))
    {
        printf("x2 = %f != x2_expected = %f\n", x2, x2_expected);
    }

    if (!is_equal(roots, roots_expected))
    {
        printf("Number of roots != Expected number of roots\n");
    }
}

bool is_roots_equal(double x1, double x2, double x1_expected, double x2_expected) 
{
    return ((is_equal(x1, x1_expected) && is_equal(x2, x2_expected)) || 
            (is_equal(x2, x1_expected) && is_equal(x1, x2_expected)));
}

