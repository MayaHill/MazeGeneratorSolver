/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "../include/my.h"

void create_empty_map(solver_t *dante)
{
    dante->height = my_strlen_array(dante->map);
    dante->width = strlen(dante->map[0]);
    dante->coords.x = 0;
    dante->coords.y = 0;
    for (int i = 0; i < 4; i++) {
        dante->dir_coords[i].x = 0;
        dante->dir_coords[i].y = 0;
    }
    dante->dir_coords[2].x = 1;
    dante->dir_coords[3].x = -1;
    dante->dir_coords[0].y = -1;
    dante->dir_coords[1].y = 1;
    create_solver_paths(dante);
}

void free_map_solver(solver_t *dante)
{
    for (int i = 0; dante->map[i]; i++)
        free(dante->map[i]);
    free(dante->map);
    if (dante->path)
        destroy_paths(&dante->path);
}

int no_solution(solver_t *dante)
{
    printf("no solution found");
    free_map_solver(dante);
    return (84);
}

int main(int argc, char **argv)
{
    char *buff = NULL;
    solver_t dante;

    if (argc != 2)
        return (84);
    buff = read_file(argv[1]);
    if (check_map(&dante, buff) == 84)
        return (84);
    create_empty_map(&dante);
    if (dante.map[0][0] == 'X')
        return (no_solution(&dante));
    if (dante.map[dante.height - 1][dante.width - 1] == 'X')
        return (no_solution(&dante));
    dante.map[0][0] = 'o';
    if (find_end(&dante) != 1)
        return (no_solution(&dante));
    dante.map[0][0] = 'o';
    print_map(&dante);
    free_map_solver(&dante);
    return (0);
}