/*
** EPITECH PROJECT, 2024
** setenv, unsetenv, env, getenv
** File description:
** ok
*/

#include "../include/my.h"

char *my_getenv(const char *name)
{
    extern char **environ;
    size_t lenght = my_strlen(name);

    for (char **env = environ; *env != NULL; ++env) {
        if (my_strncmp(*env, name, lenght) == 0 && (*env)[lenght] == '=') {
            return &(*env)[lenght + 1];
        }
    }
    return NULL;
}

int find_var(const char *name)
{
    for (int i = 0; environ[i] != NULL; ++i) {
        if (my_strncmp(environ[i], name, my_strlen(name)) == 0 &&
        environ[i][my_strlen(name)] == '=') {
            return i;
        }
    }
    return -1;
}

int update_var(const char *name, const char *value, int index)
{
    char *new_var = malloc(my_strlen(name) + my_strlen(value) + 2);

    if (new_var == NULL)
        return -1;
    cpy_cat(new_var, name, value);
    free(environ[index]);
    environ[index] = new_var;
    return 0;
}

int add_new_var(const char *name, const char *value)
{
    char *new_var = malloc(my_strlen(name) + my_strlen(value) + 2);
    char **new_env;
    int count;

    if (new_var == NULL)
        return -1;
    cpy_cat(new_var, name, value);
    count = 0;
    while (environ[count] != NULL)
        ++count;
    new_env = malloc((count + 2) * sizeof(char *));
    if (new_env == NULL) {
        free(new_var);
        return -1;
    }
    for (int i = 0; i < count; ++i)
        new_env[i] = environ[i];
    new_env[count] = new_var;
    new_env[count + 1] = NULL;
    environ = new_env;
}

int my_setenv(const char *name, const char *value, int overwrite)
{
    int index;

    if (name == NULL || name[0] == '\0' || my_strchr(name, '=') != NULL)
        return -1;
    if (value == NULL)
        value = "";
    index = find_var(name);
    if (index != -1) {
        if (!overwrite)
            return 0;
        return update_var(name, value, index);
    }
    return add_new_var(name, value);
}
