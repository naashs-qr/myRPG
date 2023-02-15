/*
** EPITECH PROJECT, 2021
** defender
** File description:
** collision
*/

#include "rpg.h"

void take_spike_dmg(csfml_t *csfml, player_t *player, sfFloatRect spike)
{
    float x = player->box.left + 50 -
        (spike.left + spike.width / 2);

    player->stat.hp -= 10;
    if (x < 0)
        player->speed.x = -30;
    else
        player->speed.x = 30;
    player->speed.y = -20;
    player->hurt.color.a = 155;
    player->airborne = 1;
}

int verif_block_collision(csfml_t *csfml, sfFloatRect box)
{
    tile_t *list;
    sfFloatRect temp;

    for (list = csfml->map.spike; list && !csfml->player.hurt.color.a;
        list = list->n_spike) {
        temp = list->hitbox;
        if (sfFloatRect_intersects(&box, &temp, NULL) == sfTrue) {
            take_spike_dmg(csfml, &csfml->player, temp);
            box.left = csfml->player.box.left + csfml->player.speed.x;
            box.top = csfml->player.box.top + csfml->player.speed.y; }
    }
    for (list = csfml->map.layer[1]; list; list = list->n_layer) {
        temp = list->hitbox;
        if (list->on && sfFloatRect_intersects(&box, &temp, NULL) == sfTrue)
            return (1); }
    for (list = csfml->map.doors; list != NULL; list = list->n_door) {
        temp = list->hitbox;
        if (list->on && sfFloatRect_intersects(&box, &temp, NULL) == sfTrue)
            return (1); }
    return (0);
}

int check_collision(csfml_t *csfml, sfVector2f move, sfFloatRect temp)
{
    temp.top += move.y;
    temp.left += move.x;
    if (verif_block_collision(csfml, temp) == 1)
        return (1);
    return (0);
}

void check_collision_player(csfml_t *csfml)
{
    sfFloatRect temp = csfml->player.box;
    if ((int) csfml->player.speed.x != 0)
    {
        temp.left += csfml->player.speed.x;
        if (verif_block_collision(csfml, temp) == 1)
            csfml->player.speed.x = 0;
    }
}