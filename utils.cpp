#include "utils.h"
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstdlib>

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
    while (getchar() != '\n') 
        { }
}

int get_file_size(FILE* file)
{
    assert(file);
    
    fseek(file, 0, SEEK_END);
    int position = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    return position;
}

char* get_file_content(FILE* file, int* buffer_size)
{
    int max_file_size = get_file_size(file);

    char* buffer = (char*) calloc(max_file_size, sizeof(char));
    *buffer_size = fread(buffer, sizeof(char), max_file_size, file);

    return buffer;
}

int calc_file_nlines(FILE* file)
{
    assert(file);

    int buffer_size = 0;
    char* buffer = get_file_content(file, &buffer_size);
    if (buffer == nullptr)
    {
        return -1;
    }

    int nlines = 0;
    for (int i = 0; i < buffer_size; i++)
    {
        if (buffer[i] == '\n')
        {
            nlines++;
        }
    }

    free(buffer);
    return nlines;
}