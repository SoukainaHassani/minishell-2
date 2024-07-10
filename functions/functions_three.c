/*
** EPITECH PROJECT, 2024
** functions_three.c
** File description:
** third file
*/

#include "../include/my.h"

char *my_strchr(const char *str, int c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == (char)c) {
            return (char *)(str + i);
        }
    }
    return NULL;
}

void cpy_cat(char *new_var, const char *name, const char *value)
{
    my_strcpy(new_var, name);
    my_strcat(new_var, "=");
    my_strcat(new_var, value);
}

char *my_strstr(const char *h, const char *n)
{
    size_t len = my_strlen(n);

    while (*h != '\0') {
        if (my_strncmp(h, n, len) == 0)
            return (char *)h;
        h++;
    }
    return NULL;
}
