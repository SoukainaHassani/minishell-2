/*
** EPITECH PROJECT, 2024
** mysh.c
** File description:
** my shell
*/

#include "../include/my.h"

int exec_dir(char *command)
{
    if (my_strcmp(command, "/usr/bin") == 0) {
        my_putstr(command);
        my_putstr(": Permission denied.\n");
        return 84;
    } else if (my_strcmp(command, "/tmp") == 0) {
        my_putstr(command);
        my_putstr(": Permission denied.\n");
        return 84;
    }
}

void execute_commands(char *command, char *arguments[])
{
    char command_path[100];
    int arg_count = 0;
    int binary = execute_binary(command);

    if (binary_e(binary, command, arguments) == 84 || exec_dir(command) == 84)
        exit(84);
    while (command != NULL && arg_count < 9) {
        arguments[arg_count] = command;
        arg_count++;
        command = strtok(NULL, " \t\n");
    }
    arguments[arg_count] = NULL;
    my_strcpy(command_path, "/bin/");
    my_strcat(command_path, arguments[0]);
    if (execve(command_path, arguments, environ) == -1) {
        my_putstr(arguments[0]);
        my_putstr(": Command not found.\n");
        exit(84);
    }
}

int execute_single_command(char *command)
{
    size_t len = my_strlen(command);
    char **args = my_str_to_word_array(command);
    char *single_command;
    char *arguments[10];
    pid_t pid;

    if (len > 0 && command[len - 1] == '\n')
        command[len - 1] = '\0';
    if (!execute_builtin(command, args)) {
        pid = fork();
        if (pid == -1)
            exit(84);
        if (pid == 0) {
            single_command = strtok(command, " \t\n");
            execute_two(single_command, args);
        } else
            wait(NULL);
    }
    free(args);
    return 0;
}

void execute_all(char *line)
{
    char *saveptr;
    char *separator = strtok_r(line, ";\n", &saveptr);
    char *token = NULL;
    char *command;
    char *command2;

    while (separator != NULL) {
        execc(separator);
        separator = strtok_r(NULL, ";\n", &saveptr);
    }
}

int main(ssize_t read)
{
    char *line = NULL;
    size_t len = 0;
    char *invalid_command = NULL;

    while (1) {
        if (isatty(STDIN_FILENO))
            my_putstr(PROMPT);
        read = getline(&line, &len, stdin);
        if (read == -1)
            return 0;
        if (line[0] == '\0' || line[0] == '\n')
            continue;
        if (char_del(line))
            continue;
        execute_all(line);
    }
    free(line);
    return 0;
}
