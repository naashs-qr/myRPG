/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void fct_move_charge(sfTexture *texture, player_t *player, mobs_t *mob)
{
    int x = player->box.left - mob->stats.hitbox.left;

    if (mob->act == IDLE) {
        if (x < 0)
            mob->speed.x = -mob->stats.sped;
        else if (x > 0)
            mob->speed.x = mob->stats.sped;
        mob->act = MVT;
        sfClock_restart(mob->clock);
    }
    if ((x < 0 && mob->speed.x >= 0) || (x > 0 && mob->speed.x <= 0)) {
        mob->act = IDLE;
        mob->speed.x = 0;
    }
}

void fct_charge_atk(sfTexture *texture, player_t *player, mobs_t *mob)
{
    int x = player->box.left - mob->stats.hitbox.left;

    if (mob->act == IDLE) {
        if (x < 0)
            mob->speed.x = -10;
        else
            mob->speed.x = 10;
        mob->speed.y -= 10;
        mob->act = MVT;
        sfClock_restart(mob->clock);
    }
    if (mob->speed.y == 0) {
        mob->speed.x = 0;
        mob->act = IDLE;
    }
}