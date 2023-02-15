/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void fct_rien(sfTexture *texture, player_t *player, mobs_t *mob)
{
    return;
    player->speed.x = 0;
    mob = NULL;
}

void fct_trap_atk(sfTexture *texture, player_t *player, mobs_t *mob)
{
    int x = player->box.left - mob->stats.hitbox.left;

    mob->act = IDLE;
    if (x >= -500 && x <= 500) {
        mob->act = MVT;
        if (mob->count_frame >= mob->stats.anim[ATK] &&
            mob->count_animate_mob % mob->stats.vani == 0) {
            mob->act = IDLE;
            sfClock_restart(mob->clock);
        }
    }

}