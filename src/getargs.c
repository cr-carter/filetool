#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* File scope flags, all default to 0*/
static int f_filename = 0;
static int f_append = 0;
static int f_search = 0;
static int f_replace = 0;
static int f_info = 0;
static int f_delete = 0;
static int f_help = 0;

int getargs(int argc, char *argv[])
{
    int opt;

    while (1)
    {
        int option_index = 0;
        static struct option long_options[] = {{"filename", required_argument, &f_filename, 'f'},
                                               {"append", required_argument, &f_append, 'a'},
                                               {"search", required_argument, &f_search, 's'},
                                               {"replace", required_argument, &f_replace, 'r'},
                                               {"info", no_argument, &f_info, 'i'},
                                               {"delete", no_argument, &f_delete, 'd'},
                                               {"help", no_argument, &f_help, 'h'},
                                               {NULL, 0, NULL, 0}};

        opt = getopt_long(argc, argv, "-:f:a:s:r:idh", long_options, &option_index);
        if (opt == -1)
            break;

        switch (opt)
        {
        case 0:
            printf("long option %s", long_options[option_index].name);
            if (optarg)
            {
                printf(" with arg %s", optarg);
            }
            printf("\n");
            break;
        case 1:
            printf("regular argument '%s'\n", optarg);
            break;
        case 'f':
            printf("Option f has arg: %s\n", optarg);
            f_filename = 102;
            break;
        case 'a':
            printf("Option a has arg: %s\n", optarg);
            f_append = 97;
            break;
        case 's':
            printf("Option s has arg: %s\n", optarg);
            f_search = 115;
            break;
        case 'r':
            printf("Option r has arg: %s\n", optarg);
            f_replace = 114;
            break;
        case 'i':
            printf("Option i was provided\n");
            f_info = 105;
            break;
        case 'd':
            printf("Option d was provided\n");
            f_delete = 100;
            break;
        case 'h':
            printf("Option h was provided\n");
            f_help = 104;
            break;
        case '?':
            printf("Unkown option: %c\n", optopt);
            break;
        case ':':
            printf("Missing arg for %c\n", optopt);
            break;
        default:
            printf("?? getopt returned character code 0%o ??\n", opt);
        }
    }

    if (optind < argc)
    {
        printf("Non-option args: ");
        while (optind < argc)
        {
            printf("%s ", argv[optind++]);
        }
        printf("\n");
    }

    printf("f_filename: %i\n", f_filename);
    printf("  f_append: %i\n", f_append);
    printf("  f_search: %i\n", f_search);
    printf(" f_replace: %i\n", f_replace);
    printf("    f_info: %i\n", f_info);
    printf("  f_delete: %i\n", f_delete);
    printf("    f_help: %i\n", f_help);
}