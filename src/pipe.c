/*
** EPITECH PROJECT, 2024
** pipe.c
** File description:
** handle pipe
*/

#include "../include/my.h"

int create_pipe(int pfd[])
{
    if (pipe(pfd) == -1)
        return 84;
    return 0;
}

int exec_first_cmd(char *single_cmd, char **args, int pfd[])
{
    int pid = fork();

    if (pid == -1)
        return 84;
    if (pid == 0) {
        close(pfd[0]);
        dup2(pfd[1], STDOUT_FILENO);
        close(pfd[1]);
        execute_pipe_commands(single_cmd, args);
        exit(0);
    }
    return pid;
}

int exec_sec_cmd(char *single_cmd2, char **args2, int pfd[])
{
    int pid = fork();

    if (pid == -1)
        return 84;
    if (pid == 0) {
        close(pfd[1]);
        dup2(pfd[0], STDIN_FILENO);
        close(pfd[0]);
        execute_pipe_commands(single_cmd2, args2);
        exit(0);
    }
    return pid;
}

void wait_for_children(int pid1, int pid2)
{
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}

int piping(char *command, char *command2)
{
    char **args = my_str_to_word_array(command);
    char **args2 = my_str_to_word_array(command2);
    char *single_cmd = args[0];
    char *single_cmd2 = args2[0];
    int pfd[2];
    int pid1;
    int pid2;

    if (create_pipe(pfd) == 84)
        return 84;
    pid1 = exec_first_cmd(single_cmd, args, pfd);
    if (pid1 == 84)
        return 84;
    pid2 = exec_sec_cmd(single_cmd2, args2, pfd);
    if (pid2 == 84)
        return 84;
    close(pfd[0]);
    close(pfd[1]);
    wait_for_children(pid1, pid2);
    return 0;
}
