/*
** EPITECH PROJECT, 2024
** binary.c
** File description:
** binaries
*/

#include "../include/my.h"

int execute_binary(char *command)
{
    struct stat file_status;

    if (stat(command, &file_status) == -1) {
        return -1;
    } else if (S_ISREG(file_status.st_mode) &&
    (file_status.st_mode & S_IXUSR)) {
        return 1;
    }
}

int binary_execve(char *command, char *arguments[])
{
    if (execve(command, arguments, environ) < 0) {
        if (errno == ENOEXEC) {
            my_putstr(command);
            my_putstr(": Exec format error. Wrong Architecture.\n");
            return 84;
        }
    }
}

int binary_e(int binary, char *command, char *arguments[])
{
    if (binary == 1) {
        if (binary_execve(command, arguments) == 84)
            return 84;
    }
}
