/*
** EPITECH PROJECT, 2021
** init_button.c
** File description:
** init all buttons
*/

#include "rpg.h"

int init_button(button_t *button, sfVector2f position, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    if (!button->rect) return (84);
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    return (0);
}