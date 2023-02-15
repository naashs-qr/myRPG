/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** bombe
*/

#include "rpg.h"

float distance_vector(sfVector2f off, sfVector2f off2)
{
    float cb = ((off2.x - off.x) * (off2.x - off.x));
    float ab = ((off2.y - off.y) * (off2.y - off.y));
    float ca = sqrt(ab + cb);
    return (ca);
}

void repulse_bombe2(csfml_t *csfml, bomb_t *bombe, sfVector2f pos)
{
    float x = pos.x - bombe->center.x;
    if (x < 0) x = (170 + x) * -1;
    else x = (170 - x);
    if (x > 30) x = 30;
    if (x < -30) x = -30;
    csfml->player.speed_env.x += x;
    csfml->player.speed.x = 0;
    float y = pos.y - bombe->center.y;
    if (y < 0) y = (170 + y) * -1;
    else y = 170 - y;
    if (y > 30) y = 30;
    if (y < -30) y = -30;
    csfml->player.speed.y += y;
}