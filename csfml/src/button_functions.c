/*
** EPITECH PROJECT, 2020
** Bonus_Dante_Star
** File description:
** button_functions.c
*/

#include "../include/bonus_dante.h"

void play_button(var_t *var)
{
    if (var->play == 0)
        var->play = 1;
}

void back_button(var_t *var)
{
    if (var->play) {
        var->reset = 1;
        var->play = 0;
    }
}

void switch_button(var_t *var)
{
    if (var->play == 1)
        var->play = 2;
    else if (var->play == 2)
        var->play = 1;
}

void quit_button(var_t *var)
{
    if (var->play == 0)
        var->quit = 1;
}