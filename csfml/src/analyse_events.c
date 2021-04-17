/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** analyse_events.c
*/

#include "../include/bonus_dante.h"

int button_is_clicked(button_t button, sfVector2f mouse_pos)
{
    sfVector2f b_pos = sfRectangleShape_getPosition(button.rect);
    sfVector2f b_size = sfRectangleShape_getSize(button.rect);

    if (mouse_pos.x >= b_pos.x && mouse_pos.x <= b_pos.x + b_size.x)
        if (mouse_pos.y >= b_pos.y && mouse_pos.y <= b_pos.y + b_size.y)
            return (1);
    return (0);
}

void check_buttons(sfRenderWindow *window, buttons_t *buttons, var_t *var)
{
    sfVector2i int_mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f mouse_pos = (sfVector2f){int_mouse_pos.x, int_mouse_pos.y};
    sfBool pressed = sfMouse_isButtonPressed(sfMouseLeft);
    button_t button;
    int hover = 0;

    for (int i = 0; i < buttons->size; i++) {
        button = buttons->all[i];
        hover = button_is_clicked(button, mouse_pos);
        if (pressed && hover) {
            button.ptr(var);
        } else if (hover) {
            sfSprite_setTexture(button.sprite, button.hover, sfTrue);
        } else {
            sfSprite_setTexture(button.sprite, button.inactive, sfTrue);
        }
    }
}

void analyse_events(window_t *win, bonus_t *d)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->window, &event)) {
        check_buttons(win->window, &d->tiles.buttons, &d->tiles.var);
        if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        if (event.type == sfEvtKeyReleased)
            d->player.state = IDLE;
        if (d->tiles.var.play && sfKeyboard_isKeyPressed(sfKeyUp))
            d->player.state = UP;
        if (d->tiles.var.play && sfKeyboard_isKeyPressed(sfKeyDown))
            d->player.state = DOWN;
        if (d->tiles.var.play && sfKeyboard_isKeyPressed(sfKeyLeft))
            d->player.state = LEFT;
        if (d->tiles.var.play && sfKeyboard_isKeyPressed(sfKeyRight))
            d->player.state = RIGHT;
    }
}