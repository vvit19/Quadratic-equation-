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

int calc_file_size(FILE* file)
{
    fseek(file, 0, SEEK_END);
    return ftell(file);
}

int read_file(FILE* file, char* buffer, int max_file_size)
{
    fseek(file, 0, SEEK_SET);
    return fread(buffer, 1, max_file_size, file);
}

void calc_symb_line(int* symb_in_line, int file_size, char* buffer)
{
    symb_in_line[0] = 0;

    for (int i = 0, j = 0; i < file_size; i++)
    {
        symb_in_line[j]++;

        if (buffer[i] == '\n')
        {
            j++;
            symb_in_line[j] = 0;
        }
    }
}