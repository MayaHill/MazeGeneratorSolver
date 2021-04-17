/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** main.c
*/

#include "../include/bonus_dante.h"

int end_loop(int status, char **map, char **dup_map)
{
    for (int i = 0; map[i]; i++) {
        free(map[i]);
        free(dup_map[i]);
    }
    free(map);
    free(dup_map);
    return (status);
}

void main_loop(window_t *win, bonus_t *d)
{
    sfClock *clock = sfClock_create();

    show_map(win->window, &d->tiles);
    while (!d->tiles.var.quit && sfRenderWindow_isOpen(win->window)) {
        analyse_events(win, d);
        if (d->tiles.var.play && get_seconds(clock) > 0.1) {
            update_window(win, d);
            sfClock_restart(clock);
        }
        if (d->tiles.var.play == 0 && get_seconds(clock) > 0.1) {
            update_menu(win, d);
            sfClock_restart(clock);
        }
    }
    sfClock_destroy(clock);
}

void init_dante(bonus_t *d)
{
    d->solved_map = duplicate_map(d->map);
    solve_map(d);
    if (d->solved_map == NULL) {
        printf("\nInvalid labyrinth\n");
        exit(84);
    }
    init_map(d, d->map, &d->tiles);
    init_map(d, d->solved_map, &d->s_tiles);
    d->tiles.var.quit = 0;
    d->tiles.var.play = 0;
    d->tiles.var.reset = 0;
    create_buttons_array(&d->tiles.buttons);
    d->player.p.pos = d->tiles.tiles[0].pos;
    d->player.coords = (sfVector2i){0, 0};
    add_tile(&d->player.p, 'P');
    sfSprite_setPosition(d->player.p.sprite, d->player.p.pos);
}

void init_tiles(bonus_t *dante)
{
    window_t win;
    sfFont *font = sfFont_createFromFile("assets/FFFFORWA.TTF");

    init_dante(dante);
    win.clock = sfClock_create();
    win.window = create_window();
    win.text = create_text(win.text, (sfVector2f){WID - 288, 32}, font);
    sfText_setFont(win.text, font);
    win.buffer = framebuffer_create(WID, HEI);
    main_loop(&win, dante);
    end_loop(0, dante->map, dante->solved_map);
    sfFont_destroy(font);
    destroy_window(&win, dante);
}
