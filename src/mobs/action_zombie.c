/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void fct_zombie_idle(sfTexture *texture, player_t *player, mobs_t *mob)
{
    mob->speed.x = 0;

    if (mob->count_frame >= mob->stats.anim[IDLE] &&
        mob->count_animate_mob % mob->stats.vani == 0) {
        mob->act = MVT;
        mob->count_animate_mob = 0;
        mob->count_frame = 0;
        sfClock_restart(mob->clock);
    }
}

void fct_zombie_dead(sfTexture *texture, player_t *player, mobs_t *mob)
{
    float sec = sfTime_asSeconds(sfClock_getElapsedTime(mob->clock));

    mob->speed.x = 0;
    if (sec > 1) {
        mob->act = IDLE;
        mob->stats.life = 120;
        mob->count_animate_mob = 0;
        mob->count_frame = 0;
        sfClock_restart(mob->clock);
    }
}

void fct_zombie_mvt(sfTexture *texture, player_t *player, mobs_t *mob)
{
    mob->speed.x = 0;

    if (sfTime_asSeconds(sfClock_getElapsedTime(mob->clock)) >= 1.5) {
        mob->act = ATK;
        sfClock_restart(mob->clock);
    }
}

void fct_zombie_atk(sfTexture *texture, player_t *player, mobs_t *mob)
{
    int x = player->box.left - mob->stats.hitbox.left;

    if (x < 0)
        mob->speed.x = -mob->stats.sped;
    else if (x > 0)
        mob->speed.x = mob->stats.sped;
    if (sfTime_asSeconds(sfClock_getElapsedTime(mob->clock)) >= 1) {
        mob->act = MVT;
        sfClock_restart(mob->clock);
    }
}