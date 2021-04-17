/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** read_file.c
*/

#include "../include/my.h"

int my_strlen_array(char **array)
{
    int len = 0;

    for (; array[len]; len++);
    return (len);
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat s;
    char *buff = NULL;

    if (fd < 0)
        return (NULL);
    if (stat(filepath, &s) < 0)
        return (NULL);
    buff = malloc(s.st_size + 1);
    if (buff == NULL)
        return (NULL);
    buff[s.st_size] = 0;
    if (read(fd, buff, s.st_size) <= 0) {
        free(buff);
        return (NULL);
    }
    return (buff);
}