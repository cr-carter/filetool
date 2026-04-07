/*
 * @file file_operations.h
 * @author Chase Carter
 * @brief Declare functions in file_operations.c
 */

#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

/*
 * @brief Searches for string in file.
 *
 * @param *p_filename name of file to search in
 * @param *p_pattern string to search for
 *
 * @returns func_retval the position of string in file, or -1 if not found
 */
int search_in_file(const char *p_filename, const char *p_pattern);

/*
 * @brief Replaces first instance of pattern in file with replacement
 *
 * @param *p_filename name of file to search in
 * @param *p_pattern string to replace
 * @param position byte position of pattern within file
 * @param *p_replacement string to write into file
 *
 * @returns func_retval 0 if successfully replaced
 */
int replace_string_in_file(const char *p_filename, const char *p_pattern, int position, const char *p_replacement);

/*
 * @brief Append string to file
 *
 * @param *p_filename name of file to append
 * @param *p_append_str string to append to file
 *
 * @returns func_retval 0 if successfully appended
 */
int append_file(const char *p_filename, const char *p_append_str);

/*
 * @brief Deletes file
 *
 * @param *p_filename name of file to append
 *
 * @returns func_retval 0 if successfully deleted
 */
int delete_file(const char *p_filename);

/*
 * @brief Prints file info (filetype, size, user, group)
 *
 * @param *p_filename name of file to get info on
 *
 * @returns func_retval 0 if successfully obtained information
 */
int get_file_info(const char *p_filename);

#endif // FILE_OPERATIONS_H