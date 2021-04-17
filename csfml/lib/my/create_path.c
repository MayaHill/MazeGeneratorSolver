/*
** EPITECH PROJECT, 2020
** My_Defense
** File description:
** create_path.c
*/

#include "../../include/my.h"

void destroy_paths(path_t **paths)
{
    path_t *temp;
    path_t *my_list = *paths;

    if (*paths == NULL)
        return;
    for (; my_list->next; my_list = temp) {
        temp = my_list->next;
        free(my_list);
    }
    free(my_list);
}

void push_back_path(path_t **paths, int x, int y)
{
    path_t *new_path = malloc(sizeof(path_t));
    path_t *temp = *paths;

    if (paths == NULL)
        return;
    while (temp->next != NULL)
        temp = temp->next;
    new_path->c.x = x;
    new_path->c.y = y;
    new_path->next = NULL;
    temp->next = new_path;
}

void push_front_path(path_t **paths, coords_t *coords)
{
    path_t *new_path = malloc(sizeof(path_t));

    new_path->c.x = coords->x;
    new_path->c.y = coords->y;
    new_path->next = (*paths);
    (*paths) = new_path;
}

coords_t *pop_front_path(path_t **paths)
{
    coords_t *coords = malloc(sizeof(coords_t));
    path_t *temp = *paths;

    (*paths) = (*paths)->next;
    coords->x = temp->c.x;
    coords->y = temp->c.y;
    free(temp);
    return (coords);
}