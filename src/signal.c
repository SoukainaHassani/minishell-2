/*
** EPITECH PROJECT, 2024
** signal.c
** File description:
** signal handler
*/

#include "../include/my.h"

void handle_sigfre(int signum, char lettre, int nom)
{
    int signal;

    if (WIFSIGNALED(signum)) {
        signal = WTERMSIG(signum);
        if (signal == SIGFPE)
            my_putstr("Floating exeption (core dumped)\n");
            exit(136);
    }
}
