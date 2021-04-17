/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** create_components.c
*/

#include "../include/bonus_dante.h"

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    char *name = "Labyrinth Solver";

    window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

void destroy_window(window_t *win, bonus_t *dante)
{
    sfText_destroy(win->text);
    destroy_map(&dante->tiles);
    destroy_map(&dante->s_tiles);
    destroy_buttons(&dante->tiles.buttons);
    framebuffer_destroy(win->buffer);
    sfRenderWindow_destroy(win->window);
    sfClock_destroy(win->clock);
}

sfText *create_text(sfText *text, sfVector2f pos, sfFont *font)
{
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 24);
    sfText_setPosition(text, pos);
    return (text);

}

void draw_text(window_t *win, char *str)
{
    sfText_setString(win->text, str);
    sfRenderWindow_drawText(win->window, win->text, NULL);
}