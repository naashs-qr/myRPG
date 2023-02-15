/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** jump
*/

#include "rpg.h"

sfFloatRect pos_wall(csfml_t *csfml, sfFloatRect box)
{
    tile_t *list = csfml->map.layer[1];

    while (list != NULL) {
        sfFloatRect temp = list->hitbox;
        if (list->on != 0 && list->touch == 0 &&
        sfFloatRect_intersects(&box, &temp, NULL) == sfTrue)
            return (temp);
        list = list->n_layer;
    }
    return ((sfFloatRect) {-1, -1, -1, -1});
}

void set_pos_hang(csfml_t *csfml, sfVector2f scale)
{
    sfFloatRect box = csfml->player.box;
    sfVector2f move;
    sfFloatRect block;

    box.left += csfml->player.speed.x;
    box.top += csfml->player.speed.y;
    block = pos_wall(csfml, box);
    move.x = block.left - box.left;
    if (csfml->player.speed.x < 0) move.x += BLOCX / 2;
    move.y = block.top - box.top;
    sfSprite_move(csfml->player.obj.sprite, move);
    csfml->player.box.left += move.x;
    csfml->player.box.top += move.y;
    move.x = move.x * -1;
    move.y = move.y * -1;
    csfml->player.hang_move = move;
}

sfVector2f get_block_x(csfml_t *csfml, sfFloatRect box)
{
    box.left += csfml->player.speed.x;
    tile_t *list = csfml->map.layer[1];
    sfVector2f pos = {0.0, 0.0};
    sfVector2f scale = sfSprite_getScale(csfml->player.obj.sprite);

    while (list != NULL) {
        sfFloatRect temp = list->hitbox;
        sfSprite *sprite = list->sprite;
        if (sfFloatRect_intersects(&box, &temp, NULL) == sfTrue) {
            pos = sfSprite_getPosition(sprite);
            if (scale.x == -1.0) pos.x += BLOCX / 2;
            else pos.x -= BLOCX / 2;
            return (pos);
        }
        list = list->n_layer;
    }
    return (pos);
}

int pos_wall2(csfml_t *csfml, sfFloatRect box, float y)
{
    sfVector2f move;
    if (y == -1.0)
        move = create_vector(-2.0, 0.0);
    else
        move = create_vector(2.0, 0.0);
    box.left += move.x;
    tile_t *list = csfml->map.layer[1];
    while (list != NULL) {
        sfFloatRect temp = list->hitbox;
        if (list->touch == 0 &&
        sfFloatRect_intersects(&box, &temp, NULL) == sfTrue)
            return (0);
        list = list->n_layer;
    }
    sfSprite_move(csfml->player.obj.sprite, move);
    csfml->player.box.left += move.x;
    pos_wall2(csfml, csfml->player.box, y);
    return (0);
}

void jump(csfml_t *csfml)
{
    csfml->player.speed.y -= 40;
    csfml->var.count_animate_jump = 1;
    csfml->player.obj.rect.left = 3200.0;
}