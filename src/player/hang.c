/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** jump
*/

#include "rpg.h"

int check_hang(csfml_t *csfml, sfVector2f scale)
{
    sfVector2f move2 = {0, -BLOCY};
    sfVector2f move = {0.0, 0.0};
    sfFloatRect temp_ball;
    sfFloatRect pos;
    sfFloatRect box = csfml->player.box;

    box.left += csfml->player.speed.x;
    box.top += csfml->player.speed.y;
    if (csfml->player.speed.y <= 0 || csfml->player.speed.x == 0) return (0);
    if (check_collision(csfml,
        (sfVector2f) {csfml->player.speed.x, 0}, csfml->player.box) == 0)
        return (0);
    else pos = pos_wall(csfml, box);
    if (check_collision(csfml, (sfVector2f) {0, 2 * BLOCY},
    csfml->player.box) == 1) return (0);
    if (csfml->player.speed.x < 0) move2.x -= BLOCX;
    else move2.x += BLOCX;
    temp_ball = (sfFloatRect) {pos.left, pos.top - 100.0, 100.0, 50.0};
    if (check_collision(csfml, move, temp_ball) == 1) return (0);
    return (1);
}

void hang(csfml_t *csfml)
{
    sfVector2f scale = sfSprite_getScale(csfml->player.obj.sprite);

    if (check_hang(csfml, scale) == 1 && csfml->var.cooldown_hang == 0)
    {
        csfml->var.hang_state = 1;
        sfSprite_setColor(csfml->player.obj.sprite,
        (sfColor) {255.0, 255.0, 255.0, 255.0});
        csfml->player.obj.rect.left = 4800.0;
        csfml->var.count_animate_jump = 0;
        set_pos_hang(csfml, scale);
    }
}

int pos_ground2(csfml_t *csfml, sfFloatRect box)
{
    box.top -= 2.0;
    tile_t *list = csfml->map.layer[1];

    while (list != NULL) {
        sfFloatRect temp = list->hitbox;
        if (list->on != 0 &&
        sfFloatRect_intersects(&box, &temp, NULL) == sfTrue) {
            sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {0.0, -2.0});
            csfml->player.box.top += -2.0;
            pos_ground2(csfml, csfml->player.box);
            return (0);
        }
        list = list->n_layer;
    }
    sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {0.0, -10.0});
    csfml->player.box.top += -10.0;
    return (0);
}

void climb(csfml_t *csfml)
{
    sfVector2f scale = sfSprite_getScale(csfml->player.obj.sprite);
    csfml->player.obj.rect.left = 5000.0;
    sfSprite_move(csfml->player.obj.sprite, csfml->player.hang_move);
    csfml->player.box.left += csfml->player.hang_move.x;
    csfml->player.box.top += csfml->player.hang_move.y;
    if (scale.x == -1) {
        sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {-100.0, 0.0});
        csfml->player.box.left += -100.0; }
    else {
        sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {100.0, 0.0});
        csfml->player.box.left += 100.0; }
    csfml->var.hang_state = 0;
    csfml->var.count_animate_ball = 1;
    csfml->var.cooldown_hang = 1;
    csfml->var.cooldown_ball = 5;
    csfml->var.input = 0;
    csfml->player.box.height -= 100.0;
    csfml->player.box.top += 100.0;
    pos_ground2(csfml, csfml->player.box);
    sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {0.0, 10.0});
}

void hang_mode(csfml_t *csfml)
{
    csfml->player.obj.rect.left = 4800.0;
    csfml->player.state_salto = 0;
    if (csfml->var.input == 5 && csfml->player.stat.bonus_state[7] == 1)
        climb(csfml);
    if (csfml->var.input == 6) {
        csfml->var.hang_state = 0;
        csfml->var.input_jump = 0;
        csfml->var.cooldown_hang = 1;
        sfSprite_move(csfml->player.obj.sprite, csfml->player.hang_move);
        csfml->player.box.left += csfml->player.hang_move.x;
        csfml->player.box.top += csfml->player.hang_move.y;
    }
}