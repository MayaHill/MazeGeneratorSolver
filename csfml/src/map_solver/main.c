/*
** EPITECH PROJECT, 2020
** pushswap
** File description:
** main
*/

#include "../../include/bonus_dante.h"

void create_empty_map(bonus_t *dante)
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
    dante->path = malloc(sizeof(path_t));
    dante->path->c.x = 0;
    dante->path->c.y = 0;
    dante->path->next = NULL;
}

void no_solution(bonus_t *dante)
{
    printf("no solution found");
    for (int i = 0; dante->solved_map[i]; i++)
        free(dante->solved_map[i]);
    free(dante->solved_map);
    dante->solved_map = NULL;
    if (dante->path)
        destroy_paths(&dante->path);
}

void solve_map(bonus_t *dante)
{
    create_empty_map(dante);
    if (dante->solved_map[0][0] == 'X')
        return (no_solution(dante));
    if (dante->solved_map[dante->height - 1][dante->width - 1] == 'X')
        return (no_solution(dante));
    dante->solved_map[0][0] = 'o';
    if (find_end(dante) != 1)
        return (no_solution(dante));
    dante->solved_map[0][0] = 'o';
    change_map(dante);
    if (dante->path)
        destroy_paths(&dante->path);
}