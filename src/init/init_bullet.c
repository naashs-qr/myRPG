/*
** EPITECH PROJECT, 2021
** init_bullet.c
** File description:
** init bullet
*/

#include "rpg.h"

int init_bomb(bomb_t *bomb, sfTexture *texture)
{
    bomb->sprite = sfSprite_create();
    sfSprite_setTexture(bomb->sprite, texture, 0);
    sfSprite_setOrigin(bomb->sprite, (sfVector2f) {35, 30});
    if (!bomb->sprite) return (84);
    bomb->radius = 170;
    bomb->center = (sfVector2f) {0, 0};
    bomb->rect = (sfIntRect) {0, 0, 70, 60};
    bomb->delay = 60;
    bomb->count = 0;
    bomb->dmg = 15;
    bomb->on = 0;
    sfSprite_setTextureRect(bomb->sprite, bomb->rect);
    return (0);
}

int init_bullet(bullet_t *bullet)
{
    bullet->sprite = sfSprite_create();
    bullet->boom = sfSprite_create();
    if (!bullet->boom || !bullet->boom) return (84);
    bullet->charge = 1;
    bullet->dmg = 0;
    bullet->on = 0;
    bullet->dirx = 0;
    bullet->diry = 0;
    return (0);
}