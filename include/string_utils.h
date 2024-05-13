/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** string_utils.h
*/

#ifndef __STRING_UTILS_H_
    #define __STRING_UTILS_H_

char **split(const char *string, const char *sep);
void destroy_split(char **self);
char *read_file(const char *filename);
char *strndup(const char *string, size_t length);

#endif /* !__STRING_UTILS_H_ */
