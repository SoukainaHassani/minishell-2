/*
** EPITECH PROJECT, 2024
** functions.c
** File description:
** functions for mysh2
*/

#include "../include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    my_putchar(str[i]);
    i = i + 1;
    }
}

int my_strcmp(const char *str_one, const char *str_two)
{
    if (str_one == NULL || str_two == NULL)
        return 84;
    while (*str_one != '\0' && *str_two != '\0' && *str_one == *str_two) {
        str_one++;
        str_two++;
    }
    if (*str_one == *str_two) {
        return 0;
    } else if (*str_one < *str_two) {
        return -1;
    } else {
        return 1;
    }
}

int my_strlen(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        count++;
    }
    return count;
}

char *my_strrchr(const char *s, int c)
{
    const char *last = NULL;

    while (*s != '\0') {
        if (*s == c) {
            last = s;
        }
        s++;
    }
    return (char *)last;
}
