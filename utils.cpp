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

int get_file_size(FILE* file)
{
    assert(file);

    fseek(file, 0, SEEK_END);
    return ftell(file);
}

int read_file(FILE* file, char* buffer, int max_file_size)
{
    assert(file);
    assert(buffer);
    
    fseek(file, 0, SEEK_SET);
    return fread(buffer, sizeof(char), max_file_size, file);
}

void get_line_size(int* symb_in_line, int file_size, char* buffer)
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

int calc_nlines(char* array, int array_size) 
{
    int nlines = 0;
    for (int i = 0; i < array_size; i++)
    {
        if (array[i] == '\n')
        {
            nlines++;
        }
    }
    return nlines;
}