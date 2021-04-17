/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** error.c
*/

#include "../include/my.h"

int get_nb(char *str)
{
    if (str == NULL)
        return (-1);
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (-1);
    return (atoi(str));
}

int check_errors(int argc, char **argv)
{
    if (argc <= 2 || argc >= 5)
        return (84);
    if (argc == 4 && strcmp(argv[3], "perfect") != 0)
        return (84);
    if (get_nb(argv[1]) == -1)
        return (84);
    if (get_nb(argv[2]) == -1)
        return (84);
    return (0);
}