/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** check_map.c
*/

#include "../include/my.h"

int check_map_x(solver_t *dante, int x, size_t len)
{
    for (int y = 0; dante->map[y]; y++) {
        if (dante->map[x][y] != 'X' && dante->map[x][y] != '*') {
            free_map_solver(dante);
            return (84);
        } else if (len != strlen(dante->map[x])) {
            free_map_solver(dante);
            return (84);
        }
    }
    return (0);
}

int check_map(solver_t *dante, char *buff)
{
    size_t len = 0;

    if (buff == NULL)
        return (84);
    dante->map = my_str_to_word_array(buff, "\n");
    dante->path = NULL;
    free(buff);
    if (dante->map == NULL || dante->map[0] == NULL)
        return (84);
    len = strlen(dante->map[0]);
    for (int x = 0; dante->map[x]; x++)
        if (check_map_x(dante, x, len) == 84)
            return (84);
    return (0);
}