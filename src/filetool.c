#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/common.h"
#include "include/file_operations.h"
#include "include/getargs.h"

int get_usage(char *prog_name)
{
    printf("Usage: %s [options]\n", prog_name);
    printf("\t-f, --filename <path/to/file>\n");
    printf("\t\tfile to use tool on\n");
    printf("\t-a, --append <string>\n");
    printf("\t\tstring to append to file, requires use of --filename option\n");
    printf("\t-s, --search <string>\n");
    printf("\t\tstring to search for, requires use of --filename option\n");
    printf("\t-r, --replace <string>\n");
    printf("\t\tstring to replace in file, requires use of --filename and --search options\n");
    printf("\t-d, --delete\n");
    printf("\t\tdelete file, requires use of --filename option\n");
    printf("\t-i, --info\n");
    printf("\t\tget info on file, requires use of --filename option\n");
    printf("\t-h, --help\n");
    return 0;
}

int main(int argc, char *argv[])
{
    int retval = 0;
    prog_args_t arguments = {0};
    getargs(argc, argv, &arguments);

    if (!arguments.filename && !arguments.is_help)
    {
        printf("Must use either filename and help option.\n");
        get_usage(argv[0]);
        retval = 1;
        goto exit_prog;
    }

    if (arguments.filename && arguments.is_help)
    {
        printf("Cannot use filename and help option together.\n");
        get_usage(argv[0]);
        retval = 1;
        goto exit_prog;
    }

    if (arguments.filename && !(arguments.append || arguments.search || arguments.is_delete || arguments.is_info))
    {
        printf("Must use one of the following: --append, --search, --delete, --info.\n");
        get_usage(argv[0]);
        retval = 1;
        goto exit_prog;
    }

    if (arguments.filename && ((arguments.append ? true : false) + (arguments.search ? true : false) +
                                   arguments.is_delete + arguments.is_info !=
                               1))
    {
        printf("Cannot use more than one of the following at once: --append, --search, --delete, --info.\n");
        get_usage(argv[0]);
        retval = 1;
        goto exit_prog;
    }

    if (arguments.search)
    {
        file_search();
        if (arguments.replace)
        {
            file_replace();
        }
    }

    if (arguments.append)
    {
        file_append();
    }

    if (arguments.is_delete)
    {
        file_delete();
    }

    if (arguments.is_info)
    {
        file_info();
    }

    if (arguments.is_help)
    {
        get_usage(argv[0]);
    }

exit_prog:
    return retval;
}

/* End of file */