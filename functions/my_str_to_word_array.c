/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** str to word(s) array
*/

#include "../include/my.h"

int my_isalnum(int nb)
{
    return (nb >= '0' && nb <= '9') || (nb >= 'A' && nb <= 'Z') ||
    (nb >= 'a' && nb <= 'z') || (nb == '-') || (nb == '/');
}

static int dup_str(char **output, size_t out_i, const char *str, size_t str_i)
{
    output[out_i] = my_strdup(str + str_i);
    return my_strlen(str + str_i);
}

char **my_str_to_word_array(const char *str)
{
    char **result = NULL;
    size_t count = 0;
    size_t sub = 0;
    char *temp = my_strdup(str);

    for (int i = 0; str[i]; i++)
        if (my_isalnum(str[i]) && !my_isalnum(str[i + 1]))
            count++;
    result = malloc(sizeof(char *) * (count + 1));
    for (int i = 0; str[i]; i++)
        temp[i] -= temp[i] * (my_isalnum(temp[i]) == 0);
    for (int i = 0; str[i]; i++) {
        if (!temp[i])
            continue;
        i += dup_str(result, sub, temp, i) - 1;
        sub++;
    }
    result[count] = NULL;
    free(temp);
    return result;
}
