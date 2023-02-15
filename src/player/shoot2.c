/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

sfVector2f get_pos_canon(csfml_t *csfml)
{
    sfVector2f pos = sfSprite_getPosition(csfml->player.obj.sprite);
    sfVector2f scale = sfSprite_getScale(csfml->player.obj.sprite);
    if (scale.x == 1.0)
        pos.x += 15.0;
    else
        pos.x -= 120.0;
    if (csfml->player.obj.rect.top == 0.0) {
        pos.y += 50.0;
    }
    else if (csfml->player.obj.rect.top == 220.0)
        pos.y += 24.0;
    else if (csfml->player.obj.rect.top == 440.0) {
        pos.y -= 50.0;
    }
    return (pos);
}

void manage_charge_anim(csfml_t *csfml)
{
    sfColor charge = (sfColor) {255.0, 110.0, 110.0, 255.0};
    if (csfml->var.count_charge > 10 && csfml->player.select_shot != 3 &&
        csfml->var.hang_state != 1) {
        sfVector2f pos = get_pos_canon(csfml);
        sfSprite_setPosition(csfml->player.charge_anim.sprite, pos);
        if (csfml->var.count_charge == 11 &&
            csfml->interface.starting_menu.state_sound == 1)
            sfSound_play(csfml->music.charge);
        if (csfml->player.charge_anim.rect.left < 150.0)
            csfml->player.charge_anim.rect.left += 32.0;
        else
            csfml->player.charge_anim.rect.left = 0.0;
        sfSprite_setTextureRect(csfml->player.charge_anim.sprite,
            csfml->player.charge_anim.rect);
        sfSprite_setColor(csfml->player.obj.sprite, charge);
    }
    if (csfml->var.count_charge == 0 && csfml->var.count_animate_jump == 0)
        sfSprite_setColor(csfml->player.obj.sprite,
            (sfColor) {255.0, 255.0, 255.0, 255.0});
}

void get_direction_shoot(csfml_t *csfml, float x, bullet_t *shoot)
{
    float rot = 0.0;
    if (csfml->player.obj.rect.top == 0.0) {
        shoot->diry = 1;
        rot = 45.0; }
    else if (csfml->player.obj.rect.top == 220.0)
        shoot->diry = 0;
    else if (csfml->player.obj.rect.top == 440.0) {
        shoot->diry = -1;
        rot = -45.0; }
    shoot->dirx = 1;
    if (x == -1.0) {
        shoot->dirx *= -1;
        if (rot != 0.0)
            rot = rot * -1; }
    sfSprite_setRotation(shoot->sprite, rot);
    sfVector2f pos = sfSprite_getPosition(shoot->sprite);
    shoot->stats.hitbox.top = pos.y;
    shoot->stats.hitbox.left = pos.x;
}