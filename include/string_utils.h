/*
** EPITECH PROJECT, 2024
** {Workshop} Programming Language
** File description:
** string_utils.h
*/

#ifndef __STRING_UTILS_H_
    #define __STRING_UTILS_H_

char **split(char const *string, char const *sep);
void destroy_split(char **self);
char *read_file(const char *filename);
char *strndup(char const *string, size_t length);

#endif /* !__STRING_UTILS_H_ */
