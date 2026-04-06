#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

typedef struct prog_args_t
{
    char *filename;
    bool is_filename;
    char *append;
    bool is_append;
    char *search;
    bool is_search;
    char *replace;
    bool is_replace;
    bool is_info;
    bool is_delete;
    bool is_help;
} prog_args;

#endif // COMMON_H