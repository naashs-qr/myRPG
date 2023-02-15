/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** jump
*/

#include "rpg.h"

void ball2(csfml_t *csfml)
{
    if (csfml->var.cooldown_ball != 0)
        csfml->var.cooldown_ball -= 1;
    if (csfml->var.input == 4 && csfml->player.airborne == 0 &&
    csfml->var.count_animate_ball != 0) {
        sfFloatRect temp = csfml->player.box;
        temp.height += 100.0;
        temp.top -= 100.0;
        if (verif_block_collision(csfml, temp) == 0) {
            csfml->player.obj.rect.left = 0.0;
            csfml->var.count_animate_ball = 0;
            csfml->var.input = 0;
            csfml->player.box.height += 100.0;
            csfml->player.box.top -= 100.0;
            sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {0.0, -10.0});
        }
    }
}

void ball(csfml_t *csfml)
{
    if (csfml->var.input == 4 && csfml->player.airborne == 0
    && csfml->var.count_animate_ball == 0 &&
    csfml->player.stat.bonus_state[7] == 1) {
        csfml->var.count_animate_ball = 1;
        csfml->player.obj.rect.left = 5000.0;
        csfml->var.cooldown_ball = 5;
        csfml->var.input = 0;
        csfml->player.box.height -= 100.0;
        csfml->player.box.top += 100.0;
        sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {0.0, 10.0});
    }
    if (csfml->var.count_animate_ball != 0) {
        if (csfml->var.count_animate_ball == 15) {
            csfml->player.obj.rect.left = 5200.0;
        }
        csfml->var.count_animate_ball += 1;
    }
    sfSprite_setTextureRect(csfml->player.obj.sprite, csfml->player.obj.rect);
    ball2(csfml);
}

void manage_animation_right_ball(csfml_t *csfml)
{
    sfSprite_setScale(csfml->player.obj.sprite, (sfVector2f) {1, 1});
    if (csfml->player.obj.rect.left < 5000.0) {
        csfml->var.count_animate_player = 10;
    }
    else if (csfml->var.count_animate_player != 0) {
        if (csfml->var.count_animate_player % 3 == 0) {
            csfml->player.obj.rect.left += 200.0;
        }
    }
    if (csfml->player.obj.rect.left > 5650.0)
        csfml->player.obj.rect.left = 5200.0;
}

void manage_animation_left_ball(csfml_t *csfml)
{
    sfSprite_setScale(csfml->player.obj.sprite, (sfVector2f) {-1, 1});
    if (csfml->player.obj.rect.left < 5000.0) {
        csfml->var.count_animate_player = 10;
    }
    else if (csfml->var.count_animate_player != 0) {
        if (csfml->var.count_animate_player % 3 == 0) {
            csfml->player.obj.rect.left += 200.0;
        }
    }
    if (csfml->player.obj.rect.left > 5650.0)
        csfml->player.obj.rect.left = 5200.0;
}