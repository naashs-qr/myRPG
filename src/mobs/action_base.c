/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void fct_idle_base(sfTexture *texture, player_t *player, mobs_t *mob)
{
    short k = rand() % 2;

    if (mob->act == IDLE && mob->count_frame < mob->stats.anim[0])
        mob->speed.x = 0;
    else {
        sfClock_restart(mob->clock);
        if ((k == 1) ^ (mob->act == ATK))
            mob->atk(texture, player, mob);
        else if ((k == 0) ^ (mob->act == MVT))
            mob->mvt(texture, player, mob);
    }
}

void fct_dead_base(sfTexture *texture, player_t *player, mobs_t *mob)
{
    mob->speed.x = 0;
    if (mob->count_frame >= mob->stats.anim[DEAD] &&
        mob->count_animate_mob % mob->stats.vani == 0) {
        mob->state = 0;
    }
}