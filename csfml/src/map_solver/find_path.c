/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** find_path.c
*/

#include "../../include/bonus_dante.h"

void check_path(bonus_t *d, coords_t *new, int *found)
{
    if (d->temp.x < 0 || d->temp.x >= d->height)
        return;
    if (d->temp.y < 0 || d->temp.y >= d->width)
        return;
    if (d->solved_map[d->temp.x][d->temp.y] == '*') {
        if ((*found) == 0) {
            d->solved_map[d->temp.x][d->temp.y] = 'o';
            new->x = d->temp.x;
            new->y = d->temp.y;
        }
        (*found) += 1;
    }
}

int end_conditions(bonus_t *dante, int found, coords_t *coords, coords_t *new)
{
    if (!found) {
        dante->solved_map[coords->x][coords->y] = '2';
        return (0);
    }
    if (new->x == dante->height - 1 && new->y == dante->width - 1) {
        dante->solved_map[new->x][new->y] = 'o';
        free(coords);
        return (1);
    }
    if (found > 0) {
        push_front_path(&dante->path, coords);
        push_front_path(&dante->path, new);
    }
    return (2);
}

int find_end(bonus_t *d)
{
    coords_t new_coords;
    coords_t *cell;
    int found_path = 0;
    int check_return = 0;

    while (d->path) {
        found_path = 0;
        cell = pop_front_path(&d->path);
        for (int i = 0; i < 4; i++) {
            d->temp.x = cell->x + d->dir_coords[i].x;
            d->temp.y = cell->y + d->dir_coords[i].y;
            check_path(d, &new_coords, &found_path);
        }
        check_return = end_conditions(d, found_path, cell, &new_coords);
        if (check_return == 1)
            return (1);
        free(cell);
    }
    return (0);
}