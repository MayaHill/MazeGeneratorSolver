/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** object.c
*/

#include "../include/bonus_dante.h"

void add_tile(tile_t *tile, char type)
{
    tile->rect = (sfIntRect){0, 0, 32, 32};
    tile->sprite = sfSprite_create();
    if (type == 'X') {
        tile->texture = sfTexture_createFromFile("assets/wall.png", NULL);
        tile->type = WALL;
    }
    if (type == 'P') {
        tile->texture = sfTexture_createFromFile("assets/player.png", NULL);
        tile->type = PLAYER;
    }
    if (type == '*') {
        tile->texture = sfTexture_createFromFile("assets/grass.png", NULL);
        tile->type = FLOOR;
    }
    if (type == 'o') {
        tile->texture = sfTexture_createFromFile("assets/path.png", NULL);
        tile->type = FLOOR;
    }
    sfSprite_setTextureRect(tile->sprite, tile->rect);
    sfSprite_setTexture(tile->sprite, tile->texture, sfFalse);
}

void add_elem(map_t *tiles, char type, int x, int y)
{
    tile_t tile;

    if (type != 'P' && type != 'X' && type != '*' && type != 'o')
        return;
    tile.pos = (sfVector2f){y * 32, x * 32};
    add_tile(&tile, type);
    sfSprite_setPosition(tile.sprite, tile.pos);
    tiles->tiles[tiles->size_t] = tile;
    tiles->size_t += 1;
}

void add_last_tiles(bonus_t *d, map_t *tiles)
{
    tile_t *last_tile = &tiles->tiles[0];

    last_tile->texture = sfTexture_createFromFile("assets/end_path.png", NULL);
    sfSprite_setTexture(last_tile->sprite, last_tile->texture, sfFalse);
    last_tile = &tiles->tiles[tiles->size_t - 1];
    last_tile->texture = sfTexture_createFromFile("assets/end_path.png", NULL);
    sfSprite_setTexture(last_tile->sprite, last_tile->texture, sfFalse);
}

void init_map(bonus_t *d, char **map, map_t *tiles)
{
    d->max.x = 0;
    if (my_strlen_array(map) < 33)
        d->max.x = (HEI / 32 - my_strlen_array(map)) / 2;
    d->max.y = 0;
    if (strlen(map[0]) < 60)
        d->max.y = (WID / 32 - strlen(map[0])) / 2;
    tiles->size_t = 0;
    for (int x = 0; map[x]; x++)
        for (int y = 0; map[x][y]; y++)
            add_elem(tiles, map[x][y], x + d->max.x, y + d->max.y);
    add_last_tiles(d, tiles);
}