/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void init_bullet_insect2(bullet_mobs_t *bullet, mobs_t *mob, sfVector2f pos)
{
    bullet->hitbox.height = 6;
    bullet->hitbox.width = 48;
    bullet->hitbox.top = pos.y + mob->stats.rect.height;
    bullet->hitbox.left = pos.x;
    bullet->speed_line.x = 20;
    bullet->speed_line.y = 0;
    bullet->speed_diag.x = 0;
    bullet->speed_diag.y = 0;
    bullet->grav = 1;
    bullet->rect.height = 58;
    bullet->rect.width = 58;
    bullet->rect.top = 174.0;
    bullet->rect.left = 0.0;
}

void init_bullet_insect(sfTexture *texture, player_t *player, mobs_t *mob)
{
    short i;

    for (i = 0; i <= 20 && mob->bullet[i].on == 1; i++);
    if (i == 20) return;
    sfVector2f pos = sfSprite_getPosition(mob->sprite);
    mob->bullet[i].dmg = mob->stats.damg;
    init_bullet_insect2(&mob->bullet[i], mob, pos);
    sfSprite_setPosition(mob->bullet[i].sprite,
    (sfVector2f){mob->bullet[i].hitbox.left, mob->bullet[i].hitbox.top});
    sfSprite_setTexture(mob->bullet[i].sprite, texture, 0);
    sfSprite_setTextureRect(mob->bullet[i].sprite, mob->bullet[i].rect);
    sfSprite_setScale(mob->bullet[i].sprite, (sfVector2f){3, 3});
    mob->bullet[i].diry = 0;
    mob->bullet[i].dirx = 1;
    mob->bullet[i].on = 1;
}

void fct_insect_atk(sfTexture *texture, player_t *player, mobs_t *mob)
{
    if (mob->act != ATK) {
        sfClock_restart(mob->clock);
        init_bullet_insect(texture, player, mob);
    }
    mob->act = ATK;
    mob->speed.x = 0;
    if (mob->count_frame >= mob->stats.anim[ATK] &&
        mob->count_animate_mob % mob->stats.vani == 0) {
        mob->act = IDLE;
        sfClock_restart(mob->clock);
    }
}

void fct_insect_mvt(sfTexture *texture, player_t *player, mobs_t *mob)
{
    int x = player->box.left - mob->stats.hitbox.left;

    mob->act = MVT;
    if (x < 0 && mob->act != IDLE) {
        mob->speed.x = -mob->stats.sped;
    }
    else if (x > 0 && mob->act != IDLE) {
        mob->speed.x = mob->stats.sped;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(mob->clock)) > 1.5) {
        mob->act = IDLE;
        sfClock_restart(mob->clock);
    }
}