/*
** EPITECH PROJECT, 2024
** errors.c
** File description:
** handle error messages
*/

#include "../include/my.h"

void execute_two(char *single_command, char **args)
{
    if (single_command != NULL && single_command[0] != '\0')
        execute_commands(single_command, args);
    else
        exit(84);
}

int char_del(const char *line)
{
    if (line[0] == '|' || line[0] == ';') {
        my_putstr("Invalid null command.\n");
        return 1;
    }
    if (line[0] == '<' || line[0] == '>') {
        my_putstr("Missing name for redirect.\n");
        return 1;
    }
    return 0;
}
