/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void scale_mob(csfml_t *csfml, mobs_t *mob)
{
    if (mob->speed.x > 0 && mob->direct > 0) {
        sfSprite_setScale(mob->sprite, (sfVector2f)
        {-mob->stats.scale, mob->stats.scale});
        sfSprite_move(mob->sprite, (sfVector2f){mob->stats.hitbox.width, 0});
        mob->direct = -1;
    } else if (mob->speed.x < 0 && mob->direct < 0) {
        sfSprite_setScale(mob->sprite, (sfVector2f)
        {mob->stats.scale, mob->stats.scale});
        sfSprite_move(mob->sprite, (sfVector2f){-mob->stats.hitbox.width, 0});
        mob->direct = 1;
    } else if (mob->speed.x == 0) {
        sfSprite_setScale(mob->sprite, (sfVector2f)
        {mob->stats.scale * mob->direct, mob->stats.scale});
        mob->direct = 1 * mob->direct;
    }
}