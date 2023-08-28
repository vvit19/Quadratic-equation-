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
    int ch = 0;
    while ((ch = getchar()) != '\n') 
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

int read_file(FILE* file, char* buffer, int max_file_size)
{
    assert(max_file_size > 0);
    assert(file);
    assert(buffer);
    
    fseek(file, 0, SEEK_SET);
    int file_size = fread(buffer, sizeof(char), max_file_size, file);

    return file_size;
}

int calc_nlines(char* array, int array_size) 
{
    assert(array);

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

int calc_file_nlines(char* filename)
{
    assert(filename);

    FILE* file = fopen(filename, "r");
    assert(file);

    char* buffer = get_file_content(file);
    if (buffer == nullptr)
    {
        return -1;
    }

    int buffer_size = get_buffer_size(file, buffer);
    int nlines = calc_nlines(buffer, buffer_size);

    free(buffer);
    fclose(file);

    return nlines;
}

int get_buffer_size(FILE* file, char* buffer)
{
    assert(file);
    assert(buffer);

    int max_file_size = get_file_size(file);
    int buffer_size = read_file(file, buffer, max_file_size);
    
    return buffer_size;
}

char* get_file_content(FILE* file)
{
    assert(file);

    int max_file_size = get_file_size(file);
    
    char* buffer = (char*) calloc(max_file_size, sizeof(char));
    if (buffer == nullptr)
    {
        return nullptr;
    }

    read_file(file, buffer, max_file_size);

    return buffer;
}

int* get_lines_sizes(int ntests, FILE* file, char* buffer)
{
    assert(file);
    assert(buffer);

    int buffer_size = get_buffer_size(file, buffer);

    int* lines_sizes = (int*) calloc(ntests, sizeof(int));
    if (lines_sizes == nullptr)
    {
        return nullptr;
    }

    for (int i = 0, j = 0; i < buffer_size; i++)
    {
        lines_sizes[j]++;

        if (buffer[i] == '\n')
        {
            j++;
        }
    }

    return lines_sizes;
}