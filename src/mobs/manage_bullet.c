/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void anim_bullet3(csfml_t *csfml, bullet_mobs_t *bullet, mobs_t *mob)
{
    sfFloatRect box_bullet = bullet->hitbox;
    sfVector2f move;
    move = (sfVector2f){0, bullet->speed_line.y * bullet->diry};
    box_bullet.top += move.y;
    if (verif_block_collision(csfml, box_bullet) == 1)
        bullet->on = 0;
    sfSprite_move(bullet->sprite, move);
    bullet->hitbox.top += move.y;
}

void anim_bullet2(csfml_t *csfml, bullet_mobs_t *bullet, mobs_t *mob)
{
    sfFloatRect box_bullet = bullet->hitbox;
    sfVector2f move;
    if (mob->direct == -1)
        bullet->dirx = 1;
    else
        bullet->dirx = -1;
    move = (sfVector2f){bullet->speed_line.x * bullet->dirx, 0};
    box_bullet.left += move.x;
    if (verif_block_collision(csfml, box_bullet) == 1)
        bullet->on = 0;
    sfSprite_move(bullet->sprite, move);
    bullet->hitbox.left += move.x;
}

void anim_bullet(csfml_t *csfml, bullet_mobs_t *bullet, mobs_t *mob)
{
    sfFloatRect box_bullet = bullet->hitbox;
    sfVector2f move;
    
    if (bullet->dirx != 0 && bullet->diry == 0) {
        anim_bullet2(csfml, bullet, mob);
    } else if (bullet->diry != 0 && bullet->dirx == 0)
        anim_bullet3(csfml, bullet, mob);
    else {
        move = (sfVector2f){bullet->speed_diag.x *
        bullet->dirx, bullet->speed_diag.y * bullet->diry};
        box_bullet.top += move.y;
        box_bullet.left += move.x;
        if (verif_block_collision(csfml, box_bullet) == 1)
            bullet->on = 0;
        sfSprite_move(bullet->sprite, move);
        bullet->hitbox.top += move.y;
        bullet->hitbox.left += move.x;
    }
}

void manage_bullet(csfml_t *csfml, mobs_t *mob)
{
    for (short i = 0; i < 20; i++)
        if (mob->bullet[i].on == 1)
            anim_bullet(csfml, &mob->bullet[i], mob);
}
