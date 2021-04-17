/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** print_map.c
*/

#include "../include/my.h"

void change_char(char *c)
{
    if (*c == '2')
        *c = '*';
}

void print_map(solver_t *dante)
{
    for (int i = 0; dante->map[i]; i++)
        for (int j = 0; dante->map[i][j]; j++)
            change_char(&dante->map[i][j]);
    for (int i = 0; dante->map[i]; i++) {
        if (i != 0)
            write(1, "\n", 1);
        write(1, dante->map[i], dante->width);
    }
}