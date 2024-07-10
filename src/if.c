/*
** EPITECH PROJECT, 2024
** if.c
** File description:
** if
*/

#include "../include/my.h"

void execute_command(char *separator)
{
    char *command;
    char *command2;

    if (my_strstr(separator, "|")) {
        command = strtok(separator, "|");
        command2 = strtok(NULL, "|");
        piping(command, command2);
    } else {
        execute_single_command(separator);
    }
}

void redirect_command(char *separator)
{
    char *command;
    const char *filename;

    if (my_strstr(separator, ">>")) {
        command = strtok(separator, ">>");
        filename = strtok(NULL, ">>");
        right_double_redir(command, filename);
    } else if (my_strstr(separator, ">")) {
        command = strtok(separator, ">");
        filename = strtok(NULL, ">");
        right_redir(command, filename);
    }
}

int execc(char *separator)
{
    if (my_strstr(separator, ">") || my_strstr(separator, ">>"))
        redirect_command(separator);
    else
        execute_command(separator);
}
