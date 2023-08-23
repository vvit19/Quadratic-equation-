enum RootsNum {
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
}; 

bool test_solve_quadratic(double a, double b, double c, double x1_expected, double x2_expected, 
                          RootsNum res_expected);
void run_all_tests();
void run_test(struct UnitTest* test, int* counter_tests, int* counter_passed_tests);
void check_test_fail(double x1, double x2, double x1_expected, double x2_expected, 
                     RootsNum roots, RootsNum roots_expected);
bool are_roots_equal(double x1, double x2, double x1_expected, double x2_expected);
RootsNum solve_quadratic(double a, double b, double c, double* x_1, double* x_2);
RootsNum solve_linear(double a, double b, double* x_1);
void read_coeff(double* coeff, char ch);
double discriminant_calculation(double a, double b, double c);
bool is_equal(double a, double b);
bool is_zero(double a);
void clean_buffer();
void output_solutions(RootsNum roots, double x_1, double x_2);
