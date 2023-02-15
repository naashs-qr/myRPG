/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void idle_boss1(player_t *player, boss_t *boss)
{
    float x;

    if (boss->state_count == 2) {
        boss->act = MVT;
        boss->state_count = 0;
        x = player->box.left + 50 - (boss->stats.hitbox.left + 130);
        if (x > 0 && boss->dir == 1) {
            boss->dir = -1;
            boss->stats.hitbox.left += boss->stats.hitbox.width;
        }
        else if (x < 0 && boss->dir == -1) {
            boss->dir = 1;
            boss->stats.hitbox.left += boss->stats.hitbox.width;
        }
    }
}

void mvt_boss1(player_t *player, boss_t *boss)
{
    float x;

    if (boss->state_count == 1) {
        boss->act = ATK;
        boss->state_count = 0;
        x = player->box.left + 50 - (boss->stats.hitbox.left + 130);
        if (x > 0 && boss->dir == 1) {
            boss->dir = -1;
            boss->stats.hitbox.left += boss->stats.hitbox.width;
        }
        else if (x < 0 && boss->dir == -1) {
            boss->dir = 1;
            boss->stats.hitbox.left += boss->stats.hitbox.width;
        }
    }
}

void atk_boss1(player_t *player, boss_t *boss)
{
    float x = player->box.left + 50 - (boss->stats.hitbox.left + 130);

    if (x > 0) {
        if (boss->dir == 1) {
            boss->dir = -1;
            boss->stats.hitbox.left += boss->stats.hitbox.width;
            boss->move.x = -1;
        }
        if (boss->move.x > -20)
            boss->move.x += -boss->stats.speed.x;
    }
    else if (x < 0) {
        if (boss->dir == -1) {
            boss->dir = 1;
            boss->stats.hitbox.left += boss->stats.hitbox.width;
            boss->move.x = 1;
        }
        if (boss->move.x < 20)
            boss->move.x += boss->stats.speed.x;
    }
    if (boss->state_count == 10) {
        sfSprite_setRotation(boss->sprite, 0);
        boss->act = IDLE;
        boss->state_count = 0;
        boss->move.x = 0;
    }
}

int init_boss1(csfml_t *csfml, boss_t *boss)
{
    boss->sprite = sfSprite_create();
    boss->texture = sfTexture_createFromFile("assets/boss/boss1.png", NULL);
    if (!boss->sprite || !boss->texture) return (84);
    sfSprite_setTexture(boss->sprite, boss->texture, sfFalse);
    boss->clock = sfClock_create();
    if (!boss->clock) return (84);
    boss->state = 1;
    boss->dir = 1;
    boss->touch = 1;
    boss->act = IDLE;
    boss->anim_count = 0;
    boss->frame_count = 0;
    boss->state_count = 0;
    boss->anim[0] = 4;
    boss->anim[1] = 5;
    boss->anim[2] = 5;
    boss->anim[3] = 0;
    boss->rect = (sfIntRect) {0, 0, 130, 130};
    boss->scale = (sfVector2f) {2, 2};
    boss->move = (sfVector2f) {0, 0};
    boss->pos = (sfVector2f) {5 * BLOCX, 7 * BLOCY};
    boss->stats.hp = 200;
    boss->stats.dmg_atk = 30;
    boss->stats.dmg_mvt = 20;
    boss->stats.dmg_shot = 0;
    boss->stats.speed = (sfVector2f) {-0.1 , 0};
    boss->stats.hitbox = (sfFloatRect)
        {boss->pos.x, boss->pos.y + 20, 260, 220};
    boss->idle = idle_boss1;
    boss->mvt = mvt_boss1;
    boss->atk = atk_boss1;
    boss->animate = animate_boss1;
    return (0);
}