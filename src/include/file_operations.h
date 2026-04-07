#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

int file_search(const char *p_filenamed, const char *p_search);

int file_replace(const char *p_filename, const char *p_search, const char *p_replace);

int file_append(const char *p_filename, const char *p_append_str);

int file_delete(const char *p_filename);

int file_info(const char *p_filename);

#endif // FILE_OPERATIONS_H