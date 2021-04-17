/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** object.c
*/

#include "../include/bonus_dante.h"

void display_buttons(sfRenderWindow *win, buttons_t *buttons, var_t var)
{
    if (var.play == 0) {
        sfRenderWindow_drawSprite(win, buttons->all[0].sprite, NULL);
        sfRenderWindow_drawSprite(win, buttons->all[1].sprite, NULL);
    } else {
        sfRenderWindow_drawSprite(win, buttons->all[2].sprite, NULL);
        sfRenderWindow_drawSprite(win, buttons->all[3].sprite, NULL);
    }
}

void destroy_buttons(buttons_t *buttons)
{
    for (int i = 0; i < buttons->size; i++) {
        sfRectangleShape_destroy(buttons->all[i].rect);
        sfTexture_destroy(buttons->all[i].hover);
        sfTexture_destroy(buttons->all[i].inactive);
        sfSprite_destroy(buttons->all[i].sprite);
    }
}