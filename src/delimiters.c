/*
** EPITECH PROJECT, 2024
** delimiters.c
** File description:
** handling delimiters
*/

#include "../include/my.h"

void execute_command_chain(char *line, char *delimiter)
{
    char *token;

    token = strtok(line, delimiter);
    while (token != NULL) {
        execute_single_command(token);
        token = strtok(NULL, delimiter);
    }
}
