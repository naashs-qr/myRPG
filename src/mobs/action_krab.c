/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void init_bullet_krab2(bullet_mobs_t *bullet, mobs_t *mob, sfVector2f pos)
{
    int nb = rand()%2;
    bullet->dmg = mob->stats.damg;
    bullet->hitbox.height = 16;
    bullet->hitbox.width = 16;
    bullet->hitbox.top = pos.y;
    bullet->hitbox.left = pos.x;
    bullet->speed_line.x = 20;
    bullet->speed_line.y = 20;
    bullet->speed_diag.x = 15;
    if (nb == 1)
        bullet->speed_diag.x *= -1;
    bullet->speed_diag.y = 15;
    bullet->grav = 1;
    bullet->rect.height = 58;
    bullet->rect.width = 58;
    bullet->rect.top = 174.0;
    bullet->rect.left = 0.0;
}

void init_bullet_krab(sfTexture *texture, player_t *player, mobs_t *mob)
{
    short i;

    for (i = 0; i <= 20 && mob->bullet[i].on == 1; i++);
    if (i == 20) return;
    sfVector2f pos = sfSprite_getPosition(mob->sprite);
    init_bullet_krab2(&mob->bullet[i], mob, pos);
    sfSprite_setPosition(mob->bullet[i].sprite, (sfVector2f)
    {mob->bullet[i].hitbox.left, mob->bullet[i].hitbox.top});
    sfSprite_setTexture(mob->bullet[i].sprite, texture, 0);
    sfSprite_setTextureRect(mob->bullet[i].sprite, mob->bullet[i].rect);
    mob->bullet[i].diry = 1;
    mob->bullet[i].dirx = 1;
    mob->bullet[i].on = 1;
}

void fct_krab_mvt(sfTexture *texture, player_t *player, mobs_t *mob)
{
    int k = rand() % 2;
    if (mob->act != MVT) sfClock_restart(mob->clock);
    if (k == 0)
        mob->speed.x = mob->stats.sped;
    else
        mob->speed.x = -mob->stats.sped;
    mob->act = MVT;
    if (sfTime_asSeconds(sfClock_getElapsedTime(mob->clock)) > 1) {
        sfClock_restart(mob->clock);
        mob->act = IDLE;
    }
}

void fct_krab_atk(sfTexture *texture, player_t *player, mobs_t *mob)
{
    if (mob->act != ATK) {
        sfClock_restart(mob->clock);
        mob->count_animate_mob = 0;
        init_bullet_krab(texture, player, mob);
    }
    mob->speed.x = 0;
    mob->act = ATK;
    if (mob->count_frame >= mob->stats.anim[ATK] &&
        mob->count_animate_mob % mob->stats.vani == 0) {
        mob->act = IDLE;
        sfClock_restart(mob->clock);
    }
}