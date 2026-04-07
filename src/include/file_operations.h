#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

int search_in_file(const char *p_filenamed, const char *p_pattern);

int replace_string_in_file(const char *p_filename, const char *p_pattern, int position, const char *p_replacement);

int append_file(const char *p_filename, const char *p_append_str);

int delete_file(const char *p_filename);

int get_file_info(const char *p_filename);

#endif // FILE_OPERATIONS_H