/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** object.c
*/

#include "../include/bonus_dante.h"

void create_buttons_array(buttons_t *buttons)
{
    button_t *all = buttons->all;
    sfVector2f back_size = {110, 110};
    int pos_x = (WID - 470) / 2;

    buttons->size = 0;
    add_button(buttons, (sfVector2f){pos_x, 400}, play_button);
    add_graphics("assets/play_off.png", "assets/play_hover.png", &all[0]);
    add_button(buttons, (sfVector2f){pos_x, 600}, quit_button);
    add_graphics("assets/exit_off.png", "assets/exit_hover.png", &all[1]);
    add_button(buttons, (sfVector2f){50, 50}, back_button);
    sfRectangleShape_setSize(buttons->all[buttons->size - 1].rect, back_size);
    add_graphics("assets/back_off.png", "assets/back_hover.png", &all[2]);
    add_button(buttons, (sfVector2f){1300, 50}, switch_button);
    add_graphics("assets/switch_off.png", "assets/switch_hover.png", &all[3]);
}

sfRectangleShape *create_rect(sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    sfRectangleShape_setOutlineThickness(rect, 1.0);
    sfRectangleShape_setFillColor(rect, sfBlack);
    return (rect);
}

void add_graphics(char *inactive, char *hover, button_t *button)
{
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);

    button->inactive = sfTexture_createFromFile(inactive, NULL);
    button->hover = sfTexture_createFromFile(hover, NULL);
    button->sprite = sfSprite_create();
    sfSprite_setPosition(button->sprite, pos);
    sfSprite_setTexture(button->sprite, button->inactive, sfTrue);
}

void add_button(buttons_t *buttons, sfVector2f pos, void (*ptr)(var_t *var))
{
    button_t button;
    sfVector2f size = (sfVector2f){470, 155};

    button.rect = create_rect(pos, size);
    button.ptr = ptr;
    buttons->all[buttons->size] = button;
    buttons->size += 1;
}