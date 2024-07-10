/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header file mysh2
*/

#ifndef MY_H_
    #define MY_H_
    #define LENGHT 500
    #define PROMPT "$> "

extern char **environ;

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <signal.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include "dirent.h"
    #include <errno.h>
    #include <ctype.h>

int my_putstr(char const *str);
int my_putchar(char c);
int my_strcmp(char const *string_one, char const *string_two);
int my_strlen(char const *str);
char *my_strrchr(const char *s, int c);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
char *my_strchr(const char *str, int c);
char *my_strstr(const char *h, const char *n);
char **my_str_to_word_array(char const *str);

void execute_cd(char *line);
int cd_token(char *line);
int cd_token_next(const char *dir);
void cd_dash(void);
void cd_dash_next(char *oldpwd, char *cwd);

void execute_commands(char *command, char *arguments[]);
int execute_single_command(char *command);
void execute_all(char *line);
void execute_command_chain(char *line, char *delimiter);
int execute_builtin(char *line, char **args);
int piping(char *command, char *command2);
void execute_pipe_commands(char *command, char *arguments[]);

char *my_getenv(const char *name);

int my_setenv(const char *name, const char *value, int overwrite);
int update_var(const char *name, const char *value, int index);
int add_new_var(const char *name, const char *value);
int find_var(const char *name);

size_t environ_size(void);
int unset_env(const char *name);
void cpy_cat(char *new_var, const char *name, const char *value);

int execc(char *separator);

int right_redir(char *command, const char *filename);
char *delete_space(const char *filename);
int right_double_redir(char *command, const char *filename);

int execute_binary(char *command);
int binary_e(int binary, char *command, char *arguments[]);

int char_del(const char *line);
void execute_two(char *single_command, char **args);

#endif
