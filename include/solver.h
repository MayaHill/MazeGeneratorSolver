/*
** EPITECH PROJECT, 2020
** Dante Star
** File description:
** solver.h
*/

typedef struct solver_s {
    int width;
    int height;
    char **map;
    coords_t dir_coords[4];
    coords_t coords;
    coords_t temp;
    path_t *path;
} solver_t;

int my_strlen_array(char **array);

char *read_file(char *filepath);

int find_end(solver_t *d);

void print_map(solver_t *dante);

int check_map(solver_t *dante, char *buff);

void free_map_solver(solver_t *dante);