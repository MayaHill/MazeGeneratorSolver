/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** generator.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct dante_s {
    int width;
    int height;
    char **map;
    int dirs[4];
    coords_t dir_coords[4];
    coords_t poss_coords[4];
    path_t *path;
    bool perfect;
} dante_t;

int check_errors(int argc, char **argv);

void create_paths(dante_t *dante);

void destroy_paths(path_t **paths);

void carve_passages(dante_t *dante);

void create_empty_gen_map(dante_t *dante);

void create_labyrinth(dante_t *dante);