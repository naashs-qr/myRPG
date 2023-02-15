/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void trap_setup(csfml_t *csfml)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        if (csfml->event.state[i] == 1)
            csfml->event.nb_mobs[i] -= 1;
    }
}

void calc_hit_mob(csfml_t *csfml, bullet_t *bullet, mobs_t *mobs)
{
    int dammage = bullet->dmg;

    mobs->stats.life -= dammage;
    if (mobs->stats.life <= 0 && mobs->act != DEAD) {
        trap_setup(csfml);
        csfml->player.stat.xp += 15;
        csfml->player.count_display_xp = 1;
        sfText_setString(csfml->player.xp_won, "+15 xp");
        mobs->speed.x = 0;
        mobs->speed.y = 0;
        mobs->act = DEAD;
        if (mobs->stats.type != ZOMBIE)
            mobs->state = 0;
        if (mobs->stats.type == KRAB || mobs->stats.type == INSECT) {
            for (short i = 0; i < 20; i++)
                mobs->bullet[i].on = 0;
        }
        sfClock_restart(mobs->clock);
    }
    if (csfml->interface.starting_menu.state_sound == 1)
        sfSound_play(csfml->music.explosion);
    bullet->on = 0;
}

void check_hit_mob(csfml_t *csfml, bullet_t *bullet, mobs_t *mobs)
{
    mobs_t *tmp;

    for (tmp = mobs; tmp && tmp->stats.type != RIEN; tmp = tmp->next)
        if (tmp->state &&
        sfFloatRect_intersects(&tmp->stats.hitbox, &bullet->stats.hitbox, NULL))
            calc_hit_mob(csfml, bullet, tmp);
}

void mobs_get_hit(csfml_t *csfml, mobs_t *mob, player_t *player)
{
    for (int i = 0; i < 10; i++) {
        if (player->bullet[i].on == 1)
            check_hit_mob(csfml, &player->bullet[i], mob);
    }
}