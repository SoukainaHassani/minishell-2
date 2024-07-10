/*
** EPITECH PROJECT, 2024
** builtin.c
** File description:
** built-in commands for mysh
*/

#include "../include/my.h"

void cd_dash_next(char *oldpwd, char *cwd)
{
    if (cwd != NULL) {
        free(cwd);
    }
    my_setenv("OLDPWD", oldpwd, 1);
}

void cd_dash(void)
{
    char *cwd;
    char *oldpwd = my_getenv("OLDPWD");

    if (oldpwd != NULL) {
        if (chdir(oldpwd) == 0) {
            cwd = getcwd(NULL, 0);
            cd_dash_next(oldpwd, cwd);
        } else
            perror("chdir");
    } else
        my_putstr(": No such file or directory.\n");
}

int cd_token(char *token)
{
    const char *user_directory = my_getenv("HOME");
    char *cwd = getcwd(NULL, 0);

    if (token == NULL || my_strcmp(token, "~") == 0) {
        if (user_directory != NULL && chdir(user_directory) != 0)
            perror("chdir");
        else
            my_setenv("OLDPWD", cwd, 1);
    } else if (my_strcmp(token, "-") == 0)
        cd_dash();
    else
        cd_token_next(token);
    return 0;
}

void execute_cd(char *line)
{
    char *token;
    char *args[] = {NULL, NULL};

    token = strtok(line, " \t\n");
    if (token != NULL && my_strcmp(token, "cd") == 0) {
        token = strtok(NULL, " \t\n");
        cd_token(token);
    }
}

int execute_builtin(char *line, char **args)
{
    if (my_strcmp(args[0], "cd") == 0) {
        execute_cd(line);
    }
    if (my_strcmp(args[0], "exit") == 0) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        my_putstr("unsetenv: Too few arguments.\n");
        return 1;
    }
    return 0;
}
