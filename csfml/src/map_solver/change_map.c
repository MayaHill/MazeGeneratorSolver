/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** change_map.c
*/

#include "../../include/bonus_dante.h"

void change_char(char *c)
{
    if (*c == '2')
        *c = '*';
}

void change_map(bonus_t *dante)
{
    for (int i = 0; dante->solved_map[i]; i++)
        for (int j = 0; dante->solved_map[i][j]; j++)
            change_char(&dante->solved_map[i][j]);
}