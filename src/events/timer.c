/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void timer(csfml_t *csfml)
{
    sfVector2f vect = sfView_getCenter(csfml->var.view);
    char str[100];
    if (csfml->interface.count_time % 40 == 0 && csfml->interface.timer > 0)
        csfml->interface.timer -= 1;
    if (csfml->interface.timer <= 0)
        csfml->player.stat.hp = 0;
    csfml->interface.count_time += 1;
    itoa2(csfml->interface.timer, str);
    sfText_setString(csfml->interface.time, str);
    vect.x += 700.0;
    vect.y -= 520.0;
    sfText_setPosition(csfml->interface.time, vect);
}