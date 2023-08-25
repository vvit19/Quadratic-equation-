#ifndef UTILS_H_
#define UTILS_H_

#include <cstdio>

bool is_equal(double a, double b);
bool is_zero(double a);
void clean_buffer();
int calc_file_size(FILE* file);
int read_file(FILE* file, char* buffer, int max_file_size);
void calc_symb_line(int* symb_in_line, int file_size, char* buffer);

#endif