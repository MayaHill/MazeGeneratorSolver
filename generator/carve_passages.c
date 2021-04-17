/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** carve_passages.c
*/

#include "../include/my.h"

void update_coords(dante_t *dante, int new_x, int new_y, int *poss)
{
    if (new_x >= 0 && new_x < dante->height && new_y >= 0) {
        if (new_y < dante->width && dante->map[new_x][new_y] == 'X') {
            dante->poss_coords[*poss].x = new_x;
            dante->poss_coords[*poss].y = new_y;
            (*poss) += 1;
        }
    }
}

void carve_in_rand_dir(int poss, int x, int y, dante_t *dante)
{
    int rand_dir = rand() % poss;
    coords_t new;

    new.x = dante->poss_coords[rand_dir].x;
    new.y = dante->poss_coords[rand_dir].y;
    dante->map[new.x][new.y] = '*';
    dante->map[(new.x + x) / 2][(new.y + y) / 2] = '*';
    push_front_path(&dante->path, &new);
}

void carve_passages(dante_t *dante)
{
    coords_t *cell;
    int new_x = 0;
    int new_y = 0;
    int poss = 0;

    while (dante->path) {
        poss = 0;
        cell = pop_front_path(&dante->path);
        for (int i = 0; i < 4; i++) {
            new_x = cell->x + dante->dir_coords[dante->dirs[i]].x;
            new_y = cell->y + dante->dir_coords[dante->dirs[i]].y;
            update_coords(dante, new_x, new_y, &poss);
        }
        if (poss > 0) {
            push_front_path(&dante->path, cell);
            carve_in_rand_dir(poss, cell->x, cell->y, dante);
        }
        free(cell);
    }
}