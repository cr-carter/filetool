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
    int retval = EXIT_SUCCESS;
    prog_args_t arguments = {0};
    getargs(argc, argv, &arguments);

    if (!arguments.filename && !arguments.is_help)
    {
        fprintf(stderr, "Usage: %s [options]\n", argv[0]);
        retval = EXIT_FAILURE;
        goto exit_prog;
    }

    if (arguments.filename && arguments.is_help)
    {
        fprintf(stderr, "Usage: %s [options]\n", argv[0]);
        retval = EXIT_FAILURE;
        goto exit_prog;
    }

    if (arguments.filename && !(arguments.append || arguments.search || arguments.is_delete || arguments.is_info))
    {
        fprintf(stderr, "Usage: %s [options]\n", argv[0]);
        retval = EXIT_FAILURE;
        goto exit_prog;
    }

    if (arguments.filename && ((arguments.append ? true : false) + (arguments.search ? true : false) +
                                   arguments.is_delete + arguments.is_info !=
                               1))
    {
        fprintf(stderr, "Usage: %s [options]\n", argv[0]);
        retval = EXIT_FAILURE;
        goto exit_prog;
    }

    if (arguments.search)
    {
        file_search();
        if (arguments.replace)
        {
            // FILE *file_fp = fopen(arguments.filename, "w");
            file_replace();
        }
    }

    if (arguments.append)
    {
        // FILE *file_fp = fopen(arguments.filename, "a");
        file_append();
    }

    if (arguments.is_delete)
    {
        int delete_failed = file_delete(arguments.filename);
        if (delete_failed)
        {
            retval = 1;
            goto exit_prog;
        }
    }

    if (arguments.is_info)
    {

        file_info(arguments.filename);
    }

    if (arguments.is_help)
    {
        get_usage(argv[0]);
    }

exit_prog:
    return retval;
}

/* End of file */