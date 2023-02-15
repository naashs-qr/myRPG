/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void copy_stat(bullet_t *bullet, stat_shoot_t *stat)
{
    bullet->stats.texture = stat->texture;
    bullet->stats.anim = stat->anim;
    bullet->stats.anim2 = stat->anim2;
    bullet->stats.charge = stat->charge;
    bullet->stats.dmg = stat->dmg;
    bullet->stats.dmg_max = stat->dmg_max;
    bullet->stats.dig = stat->dig;
    bullet->stats.speed_line = stat->speed_line;
    bullet->stats.speed_diag = stat->speed_diag;
    bullet->stats.rect = stat->rect;
    bullet->stats.hitbox = stat->hitbox;
}

void shoot_bis(csfml_t *csfml, sfVector2f scale, bullet_t *bullet, short k)
{
    float dmg[5] = {1.0, 1.2, 1.4, 1.6, 1.8};
    float charge = 1;
    player_t *play = &csfml->player;
    if (csfml->var.save_shoot > 30 && k != 3 &&
        play->stat.bonus_state[0] == 1) {
        bullet->stats.rect.left += 200.0;
        bullet->dmg = bullet->stats.dmg_max;
    }
    sfSprite_setTextureRect(bullet->sprite, bullet->stats.rect);
    sfSprite_setScale(bullet->sprite, (sfVector2f) {1.0, 1.0});
    set_shoot(csfml, scale.x, bullet);
    get_direction_shoot(csfml, scale.x, bullet);
    if (play->stat.bonus_state[k] == 1)
        charge = 1 + ((csfml->var.save_shoot / 5) / 10);
    bullet->dmg =
        bullet->stats.dmg * dmg[play->stat.lvl_dammage_missile -1] * charge;
    csfml->var.cooldown_shoot = 20;
    bullet->on = 1;
    if (csfml->interface.starting_menu.state_sound == 1)
        sfSound_play(csfml->music.beam);
}

void shoot(csfml_t *csfml)
{
    int i = 0;
    int k = csfml->player.select_shot;
    sfVector2f scale = sfSprite_getScale(csfml->player.obj.sprite);

    for (; i < 10 && csfml->player.bullet[i].on; i++);
    if (i == 10) return;

    if (k == 3) {
        if (csfml->player.stat.cap_missile == 0)
            return;
        else
            csfml->player.stat.cap_missile -= 1;
    }
    copy_stat(&csfml->player.bullet[i], &csfml->var.shoot[k]);
    sfSprite_setTexture(csfml->player.bullet[i].sprite,
        csfml->player.bullet[i].stats.texture, sfFalse);
    shoot_bis(csfml, scale, &csfml->player.bullet[i],
        csfml->player.stat.bonus_state[k]);
}

void aim(csfml_t *csfml)
{
    if (csfml->var.input_aim == 2)
        csfml->player.obj.rect.top = 0.0;
    if (csfml->var.input_aim == 3)
        csfml->player.obj.rect.top = 440.0;
    if (csfml->var.input_aim != 2 && csfml->var.input_aim != 3)
        csfml->player.obj.rect.top = 220.0;
}

void manage_shoot(csfml_t *csfml)
{
    if (csfml->var.count_animate_ball == 0) {
        aim(csfml);
        if (csfml->var.input_shoot != 0 && csfml->var.cooldown_shoot == 0) {
            shoot(csfml);
            csfml->var.input_shoot = 0;
            csfml->var.save_shoot = 0;
        }
    }
    else if (csfml->var.input_shoot == 1 && csfml->var.cooldown_shoot == 0 &&
        csfml->player.stat.bonus_state[4] == 1)
        bombe(csfml);
    if (csfml->var.cooldown_shoot != 0)
        csfml->var.cooldown_shoot -= 1;
    manage_missile(csfml);
    manage_bombe(csfml);
}