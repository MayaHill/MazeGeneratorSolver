/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** init_dante.c
*/

#include "../include/my.h"

void create_paths(dante_t *dante)
{
    dante->path = malloc(sizeof(path_t));
    dante->path->c.x = rand() % dante->height;
    dante->path->c.y = rand () % dante->width;
    dante->path->next = NULL;
}

void create_empty_gen_map(dante_t *dante)
{
    dante->map = malloc(sizeof(char *) * (dante->height + 1));
    dante->map[dante->height] = NULL;
    for (int i = 0; i < dante->height; i++) {
        dante->map[i] = malloc(sizeof(char) * (dante->width + 1));
        memset(dante->map[i], 'X', dante->width);
        dante->map[i][dante->width] = '\0';
    }
    for (int i = 0; i < 4; i++) {
        dante->dirs[i] = i;
        dante->dir_coords[i].x = 0;
        dante->dir_coords[i].y = 0;
    }
    dante->dir_coords[2].x = 2;
    dante->dir_coords[3].x = -2;
    dante->dir_coords[0].y = -2;
    dante->dir_coords[1].y = 2;
    create_paths(dante);
}

void create_labyrinth(dante_t *dante)
{
    dante->path->c.x = 0;
    dante->path->c.y = 0;
    dante->map[0][0] = '*';
    carve_passages(dante);
    dante->map[dante->height - 1][dante->width - 1] = '*';
    if (dante->map[dante->height - 2][dante->width - 1] == 'X')
        dante->map[dante->height - 1][dante->width - 2] = '*';
}