/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void act_mob(csfml_t *csfml, mobs_t *mob)
{
    sfTime time =  sfClock_getElapsedTime(mob->clock);
    float sec = sfTime_asSeconds(time);

    if (sec > 1.5) {
        if (mob->act == MVT)
            mob->mvt(csfml->map.text_mob[mob->stats.type], &csfml->player, mob);
        if (mob->act == ATK)
            mob->atk(csfml->map.text_mob[mob->stats.type], &csfml->player, mob);
        if (mob->act == IDLE)
            mob->idle(csfml->map.text_mob[mob->stats.type],
            &csfml->player, mob);
        if (mob->act == DEAD)
            mob->dead(csfml->map.text_mob[mob->stats.type],
            &csfml->player, mob);
    }
}

void animate_mob(csfml_t *csfml, mobs_t *mob)
{
    short anim = mob->stats.anim[mob->act];

    mob->stats.rect.top = mob->act * mob->stats.rect.height;
    if (mob->stats.vani && mob->count_animate_mob % mob->stats.vani == 0) {
        mob->stats.rect.left += mob->stats.rect.width;
        if (mob->count_frame >= anim) {
            mob->stats.rect.left = 0;
            mob->count_frame = 0;
        }
        sfSprite_setTextureRect(mob->sprite, mob->stats.rect);
        mob->count_frame++;
    }
    mob->count_animate_mob++;
}

void manage_mobs(csfml_t *csfml)
{
    mobs_t *tmp = csfml->map.mobs;

    for (; tmp && tmp->stats.type != RIEN; tmp = tmp->next) {
        if (tmp->state) {
            scale_mob(csfml, tmp);
            act_mob(csfml, tmp);
            if (tmp->stats.type == KRAB || tmp->stats.type == INSECT)
                manage_bullet(csfml, tmp);
            animate_mob(csfml, tmp);
            check_collision_mob(csfml, tmp);
            sfSprite_move(tmp->sprite, tmp->speed);
            tmp->stats.hitbox.top += tmp->speed.y;
            tmp->stats.hitbox.left += tmp->speed.x;
        }
    }
}