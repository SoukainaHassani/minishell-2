/*
** EPITECH PROJECT, 2024
** pipe2.c
** File description:
** execute pipe
*/

#include "../include/my.h"

void execute_pipe_commands(char *command, char *arguments[])
{
    char *invalid_command;
    char command_path[100];
    int arg_count = 0;
    int i = 0;

    while (arguments[i] != NULL && arg_count < 9) {
        arg_count++;
        i++;
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
