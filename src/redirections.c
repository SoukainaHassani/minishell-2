/*
** EPITECH PROJECT, 2024
** redirections
** File description:
** red
*/

#include "../include/my.h"

char *delete_space(const char *filename)
{
    char *clean_filename = (char *)malloc(my_strlen(filename) + 1);
    int clean_index = 0;

    if (clean_filename == NULL)
        return NULL;
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] != ' ') {
            clean_filename[clean_index] = filename[i];
            clean_index++;
        }
    }
    clean_filename[clean_index] = '\0';
    return clean_filename;
}

void wait_then_close(pid_t pid, int fd)
{
    waitpid(pid, NULL, 0);
    close(fd);
}

int right_redir(char *command, const char *filename)
{
    char *clean_filename = delete_space(filename);
    char **arguments = my_str_to_word_array(command);
    pid_t pid;
    int fd = open(clean_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
        return 84;
    pid = fork();
    if (pid == -1)
        return 84;
    if (pid == 0) {
        if (dup2(fd, STDOUT_FILENO) == -1)
            return 84;
        close(fd);
        execute_commands(arguments[0], arguments);
        free(arguments);
        return 0;
    } else
        wait_then_close(pid, fd);
}

int right_double_redir(char *command, const char *filename)
{
    char *clean_filename = delete_space(filename);
    char **arguments = my_str_to_word_array(command);
    pid_t pid;
    int fd = open(clean_filename, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
        return 84;
    pid = fork();
    if (pid == -1)
        return 84;
    if (pid == 0) {
        if (dup2(fd, STDOUT_FILENO) == -1)
            return 84;
        close(fd);
        execute_commands(arguments[0], arguments);
        free(arguments);
        return 0;
    } else
        wait_then_close(pid, fd);
}
