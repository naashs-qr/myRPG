/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void animate_base(boss_t *boss)
{
    sfIntRect rect = boss->rect;
    sfVector2f scale = boss->scale;

    rect.left = rect.width * boss->anim_count;
    rect.top = rect.height * boss->act;
    scale.x *= boss->dir;
    sfSprite_setTextureRect(boss->sprite, rect);
    sfSprite_setScale(boss->sprite, scale);
    sfSprite_setPosition(boss->sprite, boss->pos);
}

void animate_atk(boss_t *boss)
{
    sfIntRect rect = boss->rect;
    sfVector2f scale = boss->scale;
    sfVector2f pos = boss->pos;

    if (boss->state_count == 0)
        rect.left = rect.width * boss->anim_count;
    else if (boss->state_count == 9) {
        rect.left =
            (boss->anim[boss->act] - 1 - boss->anim_count) * rect.width;
        sfSprite_setRotation(boss->sprite, 0);
    }
    else {
        rect.left = (boss->anim[boss->act] - 1) * rect.width;
        sfSprite_setOrigin(boss->sprite,
            (sfVector2f) {rect.width / 2, rect.height / 2});
        sfSprite_rotate(boss->sprite, -15);
        pos.x = pos.x - boss->stats.hitbox.width / 2;
        pos.y = pos.y - boss->stats.hitbox.height / 2;
    }
    rect.top = rect.height * boss->act;
    scale.x *= boss->dir;
    sfSprite_setTextureRect(boss->sprite, rect);
    sfSprite_setScale(boss->sprite, scale);
    sfSprite_setPosition(boss->sprite, boss->pos);
}

void animate_boss1(boss_t *boss)
{
    if (boss->act != ATK) {
        animate_base(boss);
    }
    if (boss->act == ATK) {
        animate_atk(boss);
    }
    boss->frame_count++;
    if (boss->frame_count >= 8) {
        boss->anim_count++;
        boss->frame_count = 0;
    }
    if (boss->anim_count >= boss->anim[boss->act]) {
        boss->state_count++;
        boss->anim_count = 0;
    }
}
