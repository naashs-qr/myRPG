/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** bombe
*/

#include "rpg.h"

void repulse_bombe(csfml_t *csfml, bomb_t *bombe)
{
    sfVector2f pos = sfSprite_getPosition(csfml->player.obj.sprite);
    pos.x += 40.0;
    pos.y += 150.0;
    float nb = distance_vector(pos, bombe->center);
    if (nb <= bombe->radius) {
        repulse_bombe2(csfml, bombe, pos);
    }
}

void bombe(csfml_t *csfml)
{
    int i = 0;
    for (; i < 3 && csfml->player.bomb[i].on; i++);
    if (i == 3) return;
    csfml->player.bomb[i].count = 160;
    sfVector2f pos = sfSprite_getPosition(csfml->player.obj.sprite);
    pos.y += 170.0;
    sfSprite_setPosition(csfml->player.bomb[i].sprite, pos);
    csfml->player.bomb[i].center = (sfVector2f) {pos.x, pos.y};
    csfml->var.cooldown_shoot = 10;
    csfml->player.bomb[i].on = 1;
    if (csfml->interface.starting_menu.state_sound == 1)
        sfSound_play(csfml->music.bombe);
}

void animate_bombe(csfml_t *csfml, bomb_t *bombe)
{
    if (bombe->count != 0)
        bombe->count -= 1;
    if (bombe->count == 0) {
        repulse_bombe(csfml, bombe);
        bombe->on = 0;
    }
    if (bombe->count % 20 == 0) {
        if (bombe->rect.left < 30) {
            bombe->rect.left += 70.0;
        }
        else if (bombe->rect.left > 10) {
            bombe->rect.left -= 70.0;
        }
    }
    if (bombe->count < 20 && bombe->count != 0)
        bombe->rect.left = 140.0;
    sfSprite_setTextureRect(bombe->sprite,
    bombe->rect);
}

void dammage_bombe(csfml_t *csfml, bomb_t *bombe)
{
    mobs_t *tmp = csfml->map.mobs;
    sfVector2f pos = bombe->center;
    pos.x -= 45.0;
    pos.y -= 30.0;
    sfFloatRect box = (sfFloatRect) {pos.x, pos.y, 70.0, 60.0};
    for (; tmp && tmp->stats.type != RIEN; tmp = tmp->next) {
        if (tmp->state && sfFloatRect_intersects(
            &tmp->stats.hitbox, &box, NULL)) {
            tmp->stats.life -= 20;
        }
    }
}

void manage_bombe(csfml_t *csfml)
{
    for (int i = 0; i < 3; i++) {
        if (csfml->player.bomb[i].on == 1) {
            animate_bombe(csfml, &csfml->player.bomb[i]);
            if (csfml->player.bomb[i].count == 15) {
                if (csfml->interface.starting_menu.state_sound == 1)
                    sfSound_play(csfml->music.explosion);
                dammage_bombe(csfml, &csfml->player.bomb[i]);
            }
        }
    }
}