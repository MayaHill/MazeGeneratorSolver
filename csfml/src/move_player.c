/*
** EPITECH PROJECT, 2020
** Bonus Dante_Star
** File description:
** move_player.c
*/

#include "../include/bonus_dante.h"

void shift_map(bonus_t *d, int x, int y)
{
    tile_t *tile = NULL;
    sfVector2f tile_pos = d->tiles.tiles[0].pos;
    int speed = 16;

    if ((int)round(tile_pos.x) % 32 || (int)round(tile_pos.y) % 32) {
        d->player.coords.x += x;
        d->player.coords.y += y;
    }
    for (int i = 0; i < d->tiles.size_t; i++) {
        tile = &d->tiles.tiles[i];
        tile->pos.x += -1 * y * speed;
        tile->pos.y += -1 * x * speed;
        sfSprite_setPosition(tile->sprite, tile->pos);
    }
    for (int i = 0; i < d->s_tiles.size_t; i++) {
        tile = &d->s_tiles.tiles[i];
        tile->pos.x += -1 * y * speed;
        tile->pos.y += -1 * x * speed;
        sfSprite_setPosition(tile->sprite, tile->pos);
    }
}

void shift_player(bonus_t *d, int x, int y)
{
    sfVector2f player = d->player.p.pos;
    int speed = 16;

    if ((int)round(player.x) % 32 || (int)round(player.y) % 32) {
        d->player.coords.x += x;
        d->player.coords.y += y;
    }
    d->player.p.pos.x += y * speed;
    d->player.p.pos.y += x * speed;
    sfSprite_setPosition(d->player.p.sprite, d->player.p.pos);
}

int check_if_valid_move(bonus_t * d, int x, int y)
{
    sfVector2i player = d->player.coords;

    if (player.x + x < 0 || player.y + y < 0)
        return (84);
    if (player.x + x > d->width - 1 || player.y + y > d->height - 1)
        return (84);
    if (d->map[player.x + x][player.y + y] == 'X')
        return (84);
    return (0);
}

void move_player(bonus_t *d, int x, int y)
{
    sfVector2i player = d->player.coords;
    sfVector2i map_max = {16, 30};

    if (check_if_valid_move(d, x, y) == 84)
        return;
    if (map_max.x > d->height / 2)
        map_max.x = d->height / 2;
    if (map_max.y > d->width / 2)
        map_max.y = d->width / 2;
    if (x != 0 && player.x >= 16 && d->height - player.x > map_max.x)
        shift_map(d, x, y);
    else if (y != 0 && player.y > 30 && d->width - player.y > map_max.y)
        shift_map(d, x, y);
    else
        shift_player(d, x, y);
}

void update_player(bonus_t *d)
{
    if (d->player.state == LEFT)
        move_player(d, 0, -1);
    if (d->player.state == RIGHT)
        move_player(d, 0, 1);
    if (d->player.state == UP)
        move_player(d, -1, 0);
    if (d->player.state == DOWN)
        move_player(d, 1, 0);
}