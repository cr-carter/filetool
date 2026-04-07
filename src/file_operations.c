#define _POSIX_C_SOURCE 200809L

#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "include/file_operations.h"

int file_search(const char *p_filename, const char *p_search)
{
    int func_retval = -1;
    FILE *file_fp = fopen(p_filename, "r");

    if (file_fp == NULL)
    {
        printf("Unable to search %s\n", p_filename);
        goto exit_func;
    }

    char const *pos = 0;
    int line = 1;
    int byte_count = 0;
    char file_str[255] = {0};

    while (fgets(file_str, 255, file_fp))
    {
        pos = strstr(file_str, p_search);

        if (pos)
        {
            byte_count += pos - file_str;
            printf("Found string %s at position %td on line %i\n", p_search, pos - file_str, line);
            func_retval = byte_count;
            break;
        }

        byte_count += strlen(file_str);
        line++;
    }

    if (!pos)
    {
        printf("\"%s\" not found in file %s\n", p_search, p_filename);
    }

    fclose(file_fp);

exit_func:
    return func_retval;
}

int file_replace(const char *p_filename, const char *p_search, int position, const char *p_replace)
{
    int func_retval = -1;
    FILE *file_fp = fopen(p_filename, "r+");
    if (file_fp == NULL)
    {
        goto exit_func;
    }
    fseek(file_fp, position + strlen(p_search), SEEK_SET);

    char rest_of_file[4096] = {0};
    fread(rest_of_file, sizeof(rest_of_file), sizeof(*rest_of_file), file_fp);

    fseek(file_fp, position, SEEK_SET);
    fprintf(file_fp, "%s%s", p_replace, rest_of_file);
    fclose(file_fp);
exit_func:
    return func_retval;
}

int file_append(const char *p_filename, const char *p_append_str)
{
    FILE *file_fp = fopen(p_filename, "a");
    fprintf(file_fp, "%s\n", p_append_str);
    fclose(file_fp);
    return 0;
}

int file_delete(const char *p_filename)
{
    if (remove(p_filename) == 0)
    {
        printf("File %s deleted.\n", p_filename);
        return 0;
    }
    else
    {
        fprintf(stderr, "Unable to delete %s\n", p_filename);
        return 1;
    }
}

int file_info(const char *p_filename)
{
    int func_retval = 0;
    struct stat buffer = {0};

    if (lstat(p_filename, &buffer) == -1)
    {
        func_retval = 1;
        goto exit_func;
    }

    if (S_ISBLK(buffer.st_mode))
    {
        printf("Block device\n");
    }
    else if (S_ISCHR(buffer.st_mode))
    {
        printf("Character device\n");
    }
    else if (S_ISDIR(buffer.st_mode))
    {
        printf("Directory\n");
    }
    else if (S_ISFIFO(buffer.st_mode))
    {
        printf("FIFO/pipe\n");
    }
    else if (S_ISLNK(buffer.st_mode))
    {
        printf("Symlink\n");
    }
    else if (S_ISREG(buffer.st_mode))
    {
        printf("Regular file\n");
    }
    else
    {
        printf("Unknown\n");
    }

    printf("Size: %ld bytes\n", buffer.st_size);

    gid_t gid = buffer.st_gid;
    uid_t uid = buffer.st_uid;
    struct group *grp = getgrgid(gid);
    struct passwd *usr = getpwuid(uid);

    if (usr->pw_name)
    {
        printf("User: %s\n", usr->pw_name);
    }
    else
    {
        printf("User: (unknown)\n");
    }

    if (grp->gr_name)
    {
        printf("Group: %s\n", grp->gr_name);
    }
    else
    {
        printf("Group: (unknown)\n");
    }

exit_func:
    return func_retval;
}