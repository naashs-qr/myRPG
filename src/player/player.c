/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void manage_animation_right(csfml_t *csfml)
{
    sfSprite_setScale(csfml->player.obj.sprite, (sfVector2f) {1, 1});
    if (csfml->player.obj.rect.left >= 2200.0) {
        if (csfml->player.airborne == 0) {
            csfml->player.obj.rect.left = 0.0;
        }
        csfml->var.count_animate_player = 10;
    }
    else if (csfml->var.count_animate_player != 0) {
        if (csfml->var.count_animate_player % 3 == 0 &&
        csfml->player.airborne == 0)
            csfml->player.obj.rect.left += 200.0;
    }
    if (csfml->player.obj.rect.left > 2001.0 && csfml->player.airborne == 0) {
        if (csfml->interface.starting_menu.state_sound == 1)
            sfSound_play(csfml->music.footstep);
        csfml->player.obj.rect.left = 200.0;
    }
}

void manage_animation_left(csfml_t *csfml)
{
    sfSprite_setScale(csfml->player.obj.sprite, (sfVector2f) {-1, 1});
    if (csfml->player.obj.rect.left >= 2200.0) {
        if (csfml->player.airborne == 0) {
            csfml->player.obj.rect.left = 0.0;
        }
        csfml->var.count_animate_player = 10;
    }
    else if (csfml->var.count_animate_player != 0) {
        if (csfml->var.count_animate_player % 3 == 0 &&
        csfml->player.airborne == 0)
            csfml->player.obj.rect.left += 200.0;
    }
    if (csfml->player.obj.rect.left > 2001.0 && csfml->player.airborne == 0) {
        if (csfml->interface.starting_menu.state_sound == 1)
            sfSound_play(csfml->music.footstep);
        csfml->player.obj.rect.left = 200.0;
    }
}

void manage_animation_player(csfml_t *csfml)
{
    if (csfml->var.input == 1 && csfml->var.count_animate_ball == 0)
        manage_animation_right(csfml);
    else if (csfml->var.input == 1 && csfml->var.count_animate_ball != 0)
        manage_animation_right_ball(csfml);
    if (csfml->var.input == 2 && csfml->var.count_animate_ball == 0)
        manage_animation_left(csfml);
    else if (csfml->var.input == 2 && csfml->var.count_animate_ball != 0)
        manage_animation_left_ball(csfml);
    if (csfml->var.input == 0 && csfml->var.count_animate_ball == 0 &&
    csfml->var.count_animate_jump == 0) {
        if (csfml->player.airborne == 0)
            csfml->player.obj.rect.left = 0;
    }
    else if (csfml->var.input == 0 && csfml->var.count_animate_ball > 15) {
        csfml->player.obj.rect.left = 5200.0;
    }
    if (csfml->var.count_animate_player != 0)
        csfml->var.count_animate_player += 1;
    sfSprite_setTextureRect(csfml->player.obj.sprite, csfml->player.obj.rect);
}

void manage_player2(csfml_t *csfml)
{
    if (check_collision(csfml, (sfVector2f)
    {0, csfml->player.speed.y}, csfml->player.box) == 0) {
        sfSprite_move(csfml->player.obj.sprite,
        (sfVector2f) {0, csfml->player.speed.y});
        csfml->player.box.top += csfml->player.speed.y;
    } else csfml->player.speed.y = 0;
    if (check_collision(csfml, (sfVector2f)
    {csfml->player.speed.x, 0}, csfml->player.box) == 0) {
        sfSprite_move(csfml->player.obj.sprite,
        (sfVector2f) {csfml->player.speed.x, 0});
        csfml->player.box.left += csfml->player.speed.x; }
    else csfml->player.speed.x = 0;
    if ((csfml->var.input == 1 && csfml->player.speed.x < 0) ||
    (csfml->var.input == 2 && csfml->player.speed.x > 0) ||
    (csfml->var.input != 1 && csfml->var.input != 2)) {
        if (csfml->player.airborne == 0)
            csfml->player.speed.x = 0;
    }
}

void manage_player(csfml_t *csfml)
{
    manage_animation_player(csfml);
    manage_jump(csfml);
    if (csfml->var.count_animate_ball == 0)
        hang(csfml);
    ball(csfml);
    manage_speed_x(csfml);
    if (csfml->var.count_animate_ball == 0 && csfml->player.stat.bonus_state[0] == 1)
        manage_charge_anim(csfml);
    manage_stat_player(csfml);
    if (csfml->var.cooldown_switch > 0) csfml->var.cooldown_switch -= 1;
    csfml->player.speed.y += csfml->player.speed_env.y;
    csfml->player.speed.x += csfml->player.speed_env.x;
    manage_player2(csfml);
}