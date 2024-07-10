/*
** EPITECH PROJECT, 2024
** functions two
** File description:
** second functions file for mysh2
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;

    if (n == 0) {
    return 0;
    }
    while (s1[a] != '\0' && s1[a] == s2[a] && a < n - 1) {
    a++;
    }
    return s1[a] - s2[a];
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0') {
        i++;
    }
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    char *str;
    int i;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    i = 0;
    while (src[i] != '\0') {
        str[i] = src[i];
        i = i + 1;
    }
    str[i] = '\0';
    return str;
}

int cd_token_next(const char *dir)
{
    char *cwd = getcwd(NULL, 0);

    if (chdir(dir) != 0) {
        my_putstr(dir);
        my_putstr(": Not a directory.\n");
    } else
        my_setenv("OLDPWD", cwd, 1);
    free(cwd);
}
