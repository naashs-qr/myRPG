/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** jump
*/

#include "rpg.h"

void salto_dammage(csfml_t *csfml, sfFloatRect box)
{
    mobs_t *tmp;

    for (tmp = csfml->map.mobs; tmp && tmp->stats.type != RIEN; tmp = tmp->next)
        if (tmp->state &&
        sfFloatRect_intersects(&tmp->stats.hitbox, &box, NULL)) {
            tmp->stats.life -= 40;
            if (tmp->stats.life <= 0) {
                csfml->player.stat.xp += 15;
                tmp->state = 0;
            }
        }
}

void manage_jump_animate2(csfml_t *csfml)
{
    if (csfml->player.stat.bonus_state[6] == 1) {
        sfVector2f pos = sfSprite_getPosition(csfml->player.obj.sprite);
        pos.x -= 100.0;
        sfSprite_setPosition(csfml->player.salto.sprite, pos);
        csfml->player.state_salto = 1;
        sfColor charge = (sfColor) {255.0, 255.0, 100.0, 255.0};
        sfSprite_setColor(csfml->player.obj.sprite, charge);
    }
    if (csfml->var.count_animate_jump == 20) {
        salto_dammage(csfml, csfml->player.box);
        if (csfml->player.salto.rect.left == 0.0)
            csfml->player.salto.rect.left += 100.0;
        else
            csfml->player.salto.rect.left -= 100.0;
        sfSprite_setTextureRect(csfml->player.salto.sprite,
        csfml->player.salto.rect);
    }
}

void manage_jump_animate(csfml_t *csfml)
{
    csfml->var.count_animate_jump += 1;
    if (csfml->var.count_animate_jump % 1 == 0 &&
    csfml->player.obj.rect.left < 4700.0)
        csfml->player.obj.rect.left += 200.0;
    if (csfml->player.obj.rect.left > 4700.0)
        csfml->player.obj.rect.left = 3200.0;
    manage_jump_animate2(csfml);
}

void manage_jump2(csfml_t *csfml)
{
    if (csfml->player.airborne == 1 && csfml->var.count_animate_jump == 0 &&
    csfml->var.count_animate_ball == 0)
        csfml->player.obj.rect.left = 2200.0;
    if (csfml->var.cooldown_double_jump > 0)
        csfml->var.cooldown_double_jump -= 1;
    if (csfml->player.airborne == 0) {
        csfml->var.count_animate_jump = 0;
        csfml->var.cooldown_hang = 0;
    }
    if (csfml->var.count_animate_jump != 0 &&
    csfml->var.count_animate_ball == 0)
        manage_jump_animate(csfml);
}

void manage_jump(csfml_t *csfml)
{
    csfml->player.state_salto = 0;
    if (csfml->var.input_jump == 1 && csfml->player.airborne == 1
    && csfml->var.double_jump == 0 && csfml->player.speed.y >= 0 &&
    csfml->var.cooldown_double_jump == 0 &&
    csfml->player.stat.bonus_state[5] == 1) {
        if (csfml->var.count_animate_ball == 0)
            jump(csfml);
        csfml->var.input_jump = 0;
        csfml->var.double_jump = 1;
        csfml->player.airborne = 1;
        csfml->var.cooldown_double_jump = 50;
    }
    if (csfml->var.input_jump == 1 && csfml->player.airborne == 0 &&
    csfml->var.cooldown_double_jump == 0) {
        csfml->player.speed.y -= 32;
        csfml->var.input_jump = 0;
        csfml->var.double_jump = 0;
        csfml->player.airborne = 1;
        csfml->var.cooldown_double_jump = 15; }
    manage_jump2(csfml);
}