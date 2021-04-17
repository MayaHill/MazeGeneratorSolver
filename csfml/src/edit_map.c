/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** object.c
*/

#include "../include/bonus_dante.h"

void reset_map_positions(bonus_t *d)
{
    tile_t *tile = &d->tiles.tiles[0];
    sfVector2f diff = {tile->pos.x, tile->pos.y};

    diff.x -= d->max.y * 32;
    diff.y -= d->max.x* 32;
    for (int i = 0; i < d->tiles.size_t; i++) {
        tile = &d->tiles.tiles[i];
        tile->pos.x -= diff.x;
        tile->pos.y -= diff.y;
        sfSprite_setPosition(tile->sprite, tile->pos);
    }
    for (int i = 0; i < d->s_tiles.size_t; i++) {
        tile = &d->s_tiles.tiles[i];
        tile->pos.x -= diff.x;
        tile->pos.y -= diff.y;
        sfSprite_setPosition(tile->sprite, tile->pos);
    }
}

void show_map(sfRenderWindow *win, map_t *map)
{
    tile_t *t = NULL;
    int m = -64;
    int w = 1952;
    int h = 1112;

    for (int i = 0; i < map->size_t; i++) {
        t = &map->tiles[i];
        if (t->pos.x >= m && t->pos.y >= m && t->pos.x <= w && t->pos.y <= h)
            sfRenderWindow_drawSprite(win, map->tiles[i].sprite, NULL);
    }
}

void destroy_map(map_t *map)
{
    for (int i = 0; i < map->size_t; i++) {
        sfTexture_destroy(map->tiles[i].texture);
        sfSprite_destroy(map->tiles[i].sprite);
    }
}