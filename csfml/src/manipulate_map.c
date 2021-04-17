/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** get_map_coords.c
*/

#include "../include/bonus_dante.h"

int *return_index(char **map, int x, char c, int *coords)
{
    for (int y = 0; map[x][y]; y++)
        if (map[x][y] == c) {
            coords[0] = x;
            coords[1] = y;
            return (coords);
        }
    return (coords);
}

int *get_index(char **map, char c)
{
    int *coords = malloc(sizeof(int) * 2);

    coords[0] = 0;
    coords[1] = 0;
    for (int x = 0; map[x]; x++)
        coords = return_index(map, x, c, coords);
    return (coords);
}

char **duplicate_map(char **map)
{
    int len = my_strlen_array(map);
    char **dup_map = malloc(sizeof(char *) * (len + 1));

    dup_map[len] = NULL;
    for (int i = 0; map[i]; i++)
        dup_map[i] = strdup(map[i]);
    return (dup_map);
}

int walkable(char c)
{
    if (c == '#' || c == 'X')
        return (0);
    if (c == 'O' || c == ' ')
        return (1);
    return (2);
}