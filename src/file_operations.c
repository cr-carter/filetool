#define _POSIX_C_SOURCE 200809L // Needed for lstat

#include <grp.h>    // get GID
#include <pwd.h>    // get UID
#include <stdio.h>  // FILE, sterror
#include <stdlib.h> // rand
#include <string.h>
#include <sys/stat.h> // get_file_info

#include "include/file_operations.h"

#define TEMP_FILENAME_LEN 50

int search_in_file(const char *p_filename, const char *p_pattern)
{
    int func_retval = -1;
    FILE *file_fp = fopen(p_filename, "r");

    if (file_fp == NULL)
    {
        printf("Unable to search %s\n", p_filename);
        goto exit_func;
    }

    char const *pos = 0; // position in line
    int line = 1;
    int byte_count = 0; // will return as int, location in file
    char file_str[255] = {0};

    // fgets alternative, dynamic memory
    while (fgets(file_str, 255, file_fp))
    {
        pos = strstr(file_str, p_pattern);

        if (pos)
        {
            byte_count += pos - file_str;
            printf("Found string %s at position %td on line %i\n", p_pattern, pos - file_str, line);
            func_retval = byte_count;
            break;
        }

        byte_count += strlen(file_str);
        line++;
    }

    if (!pos)
    {
        printf("\"%s\" not found in file %s\n", p_pattern, p_filename);
    }

    fclose(file_fp);

exit_func:
    return func_retval;
}

int replace_string_in_file(const char *p_filename, const char *p_pattern, int position, const char *p_replacement)
{
    int func_retval = -1;
    FILE *file_fp = fopen(p_filename, "r");
    if (file_fp == NULL)
    {
        goto exit_func;
    }

    char temp_filename[TEMP_FILENAME_LEN] = {0};
    sprintf(temp_filename, "temp%i%i.txt", rand(), rand());

    FILE *temp_fp = fopen(temp_filename, "w");

    // write from file_fp to temp_fp
    for (int i = 0; i < position; i++)
    {
        putc(fgetc(file_fp), temp_fp);
    }

    // save from end of search pattern to send of file
    fseek(file_fp, position + strlen(p_pattern), SEEK_SET);

    // dynamic memory
    char rest_of_file[4096] = {0};
    fread(rest_of_file, sizeof(rest_of_file), sizeof(*rest_of_file), file_fp);

    fprintf(temp_fp, "%s%s", p_replacement, rest_of_file);

    fclose(temp_fp);
    fclose(file_fp);
    remove(p_filename);
    rename(temp_filename, p_filename);

    func_retval = 0;

exit_func:
    return func_retval;
}

int append_file(const char *p_filename, const char *p_append_str)
{
    int func_retval = 0;
    FILE *file_fp = fopen(p_filename, "a");
    if (file_fp == NULL)
    {
        func_retval = 1;
        goto end_func;
    }
    fprintf(file_fp, "%s\n", p_append_str);
    fclose(file_fp);

end_func:
    return func_retval;
}

int delete_file(const char *p_filename)
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

int get_file_info(const char *p_filename)
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