#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

typedef struct prog_args_t
{
    char *filename;
    char *append;
    char *search;
    char *replace;
    bool is_info;
    bool is_delete;
    bool is_help;
} prog_args;

#endif // COMMON_H