/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** update_game.c
*/

#include "../include/bonus_dante.h"

void destroy_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void update_game(window_t *win, bonus_t *d)
{
    update_player(d);
    sfRenderWindow_clear(win->window, sfBlack);
    if (d->tiles.var.play == 1)
        show_map(win->window, &d->tiles);
    else
        show_map(win->window, &d->s_tiles);
    sfRenderWindow_drawSprite(win->window, d->player.p.sprite, NULL);
    display_buttons(win->window, &d->tiles.buttons, d->tiles.var);
}

int game_won(bonus_t *d)
{
    sfVector2f player = d->player.p.pos;
    sfVector2f dest = d->tiles.tiles[d->tiles.size_t - 1].pos;

    if (player.x == dest.x && player.y == dest.y)
        return (1);
    return (0);
}

void update_window(window_t *win, bonus_t *d)
{
    if (game_won(d)) {
        sfRenderWindow_clear(win->window, sfBlack);
        display_buttons(win->window, &d->tiles.buttons, d->tiles.var);
        sfText_setPosition(win->text, (sfVector2f){800, 500});
        draw_text(win, "You win!");
    } else
        update_game(win, d);
    sfRenderWindow_display(win->window);
}

void update_menu(window_t *win, bonus_t *dante)
{
    sfRenderWindow_clear(win->window, sfBlack);
    show_map(win->window, &dante->tiles);
    display_buttons(win->window, &dante->tiles.buttons, dante->tiles.var);
    sfRenderWindow_display(win->window);
    if (dante->tiles.var.reset) {
        dante->tiles.var.reset = 1;
        reset_map_positions(dante);
        dante->player.coords = (sfVector2i){0, 0};
        dante->player.p.pos = dante->tiles.tiles[0].pos;
        sfSprite_setPosition(dante->player.p.sprite, dante->player.p.pos);
    }
    sfClock_restart(win->clock);
}