/*
** EPITECH PROJECT, 2021
** defender
** File description:
** collision
*/

#include "rpg.h"

void check_collision_mob(csfml_t *csfml, mobs_t *mob)
{
    sfFloatRect temp = mob->stats.hitbox;
    temp.left += mob->speed.x;
    if (check_collision(csfml, (sfVector2f){mob->speed.x, 0},
        mob->stats.hitbox) == 1)
        mob->speed.x = 0;
    else
        temp.left -= mob->speed.x;
    temp.top += mob->speed.y;
    if (check_collision(csfml, (sfVector2f){0, mob->speed.y},
        mob->stats.hitbox) == 1)
        mob->speed.y = 0;
}
