/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void calc_hit_player(csfml_t *csfml, bullet_mobs_t *bullet, player_t *player)
{
    float x = player->box.left + 50 -
        (bullet->hitbox.left +bullet->hitbox.width / 2);

    player->stat.hp -= bullet->dmg;
    if (x < 0)
        player->speed.x = -20;
    else
        player->speed.x = 20;
    player->speed.y = -10;
    player->hurt.color.a = 155;
    player->airborne = 1;
}

void take_contact_dmg(csfml_t *csfml, player_t *player, mobs_t *mob)
{
    float x = player->box.left + 50 -
        (mob->stats.hitbox.left + mob->stats.hitbox.width / 2);
    player->stat.hp -= mob->stats.damg;
    if (x < 0)
        player->speed.x = -30;
    else
        player->speed.x = 30;
    player->speed.y = -10;
    player->hurt.color.a = 155;
    player->airborne = 1;
}

void player_get_shot(csfml_t *csfml, mobs_t *mob, player_t *player)
{
    for (int i = 0; i < 20 && !player->hurt.color.a; i++)
        if (mob->bullet[i].on && sfFloatRect_intersects(
            &player->box, &mob->bullet[i].hitbox, NULL))
        calc_hit_player(csfml, &mob->bullet[i], player);
}

void player_get_hit(csfml_t *csfml, mobs_t *mob, player_t *play)
{
    mobs_t *tm = mob;

    for (; tm && tm->stats.type != RIEN && !play->hurt.color.a; tm = tm->next)
    {
        if (tm->state && sfFloatRect_intersects(&tm->stats.hitbox,
            &play->box, NULL) && tm->act != DEAD)
            take_contact_dmg(csfml, play, tm);
        else if (tm->state) {
            player_get_shot(csfml, tm, play);
        }
    }
}