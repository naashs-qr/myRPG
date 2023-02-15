/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void energy(csfml_t *csfml)
{
    sfVector2f vect = sfView_getCenter(csfml->var.view);
    vect.x -= 900.0;
    vect.y -= 500.0;
    sfSprite_setPosition(csfml->interface.ui.hp.sprite, vect);
    vect.y += 50.0;
    char *str = get_hp_number(csfml, csfml->player.stat.hp,
    csfml->player.stat.hp_max);
    sfText_setString(csfml->interface.ui.hp_number, str);
    sfText_setPosition(csfml->interface.ui.hp_number, vect);
    vect.y -= 50.0;
    vect.x += 97.0;
    sfSprite_setPosition(csfml->interface.ui.hp_bar.sprite, vect);
    float life;
    float nb1 = (float) (csfml->player.stat.hp);
    float nb2 = (float) (csfml->player.stat.hp_max);
    life = (float) (nb1 / nb2);
    csfml->interface.ui.hp_bar.rect.width = 73 * life;
    sfSprite_setTextureRect(csfml->interface.ui.hp_bar.sprite,
        csfml->interface.ui.hp_bar.rect);
}

void animate_bullet(csfml_t *csfml, bullet_t *bullet)
{
    bullet->stats.anim += 1;
    if (bullet->stats.anim % 5 == 0)
    {
        if (bullet->stats.rect.left == 0.0 ||
            bullet->stats.rect.left == 200.0)
            bullet->stats.rect.left += 100.0;
        else
            bullet->stats.rect.left -= 100.0;
    }
    sfSprite_setTextureRect(bullet->sprite, bullet->stats.rect);
}

void move_bullet(csfml_t *csfml, bullet_t *bullet)
{
    sfFloatRect temp = bullet->stats.hitbox;
    sfVector2f move;
    animate_bullet(csfml, bullet);
    if (bullet->diry == 0)
        move = (sfVector2f)
            {bullet->stats.speed_line.x *bullet->dirx, 0};
    else
        move = (sfVector2f) {bullet->stats.speed_diag.x *
            bullet->dirx, bullet->stats.speed_diag.y *
        bullet->diry};
    temp.left += move.x;
    temp.top += move.y;
    if (verif_break_collision(csfml, temp, bullet->stats.dig, &csfml->player)
        || verif_block_collision(csfml, temp)) {
        if (csfml->interface.starting_menu.state_sound == 1)
            sfSound_play(csfml->music.explosion);
        bullet->on = 0; }
    sfSprite_move(bullet->sprite, move);
    bullet->stats.hitbox.left += move.x;
    bullet->stats.hitbox.top += move.y;
}

void manage_missile(csfml_t *csfml)
{
    for (int i = 0; i < 10; i++) {
        if (csfml->player.bullet[i].on == 1) {
            move_bullet(csfml, &csfml->player.bullet[i]);
        }
    }
}

void set_shoot(csfml_t *csfml, float x, bullet_t *shoot)
{
    sfVector2f pos;
    if (x == 1.0) {
        pos = sfSprite_getPosition(csfml->player.obj.sprite);
        pos.x += 90.0;
        if (csfml->player.obj.rect.top == 440.0) pos.y -= 40.0;
        else pos.y += 60.0;
        sfSprite_setPosition(shoot->sprite, pos);
        shoot->stats.hitbox.top = pos.y;
        shoot->stats.hitbox.left = pos.x;}
    else {
        pos = sfSprite_getPosition(csfml->player.obj.sprite);
        pos.x -= 90.0;
        if (csfml->player.obj.rect.top == 440.0) pos.y -= 40.0;
        else pos.y += 60.0;
        sfSprite_setPosition(shoot->sprite, pos);
        sfSprite_setScale(shoot->sprite, (sfVector2f) {-1.0, 1.0});
        shoot->stats.hitbox.top = pos.y;
        shoot->stats.hitbox.left = pos.x;
    }
}
