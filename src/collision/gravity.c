/*
** EPITECH PROJECT, 2021
** defender
** File description:
** gravity
*/

#include "rpg.h"

int pos_ground(csfml_t *csfml, sfFloatRect box)
{
    box.top += 2.0;
    tile_t *list = csfml->map.layer[1];
    sfFloatRect temp;
    for (list = csfml->map.spike; list && !csfml->player.hurt.color.a;
        list = list->n_spike) {
        temp = list->hitbox;
        if (sfFloatRect_intersects(&box, &temp, NULL) == sfTrue) {
            take_spike_dmg(csfml, &csfml->player, temp);
            box.left = csfml->player.box.left + csfml->player.speed.x;
            box.top = csfml->player.box.top + csfml->player.speed.y;
            return (0); } }
    list = csfml->map.layer[1];
    while (list != NULL) {
        temp = list->hitbox;
        if (list->on && sfFloatRect_intersects(&box, &temp, NULL) == sfTrue)
            return (0);
        list = list->n_layer; }
    sfSprite_move(csfml->player.obj.sprite, (sfVector2f) {0.0, 2.0});
    csfml->player.box.top += 2.0;
    pos_ground(csfml, csfml->player.box);
    return (0);
}

int gravity_player(csfml_t *csfml)
{
    sfFloatRect box = csfml->player.box;
    box.top += 30.0;
    tile_t *list = csfml->map.layer[1];

    while (list != NULL) {
        sfFloatRect temp = list->hitbox;
        if (list->on && sfFloatRect_intersects(&box, &temp, NULL) == sfTrue) {
            csfml->player.speed_env.y = 0;
            csfml->player.speed.y = 0;
            return (0);
        }
        list = list->n_layer;
    }
    if ((int) csfml->player.speed_env.y == 0)
        csfml->player.speed_env.y = 1;
    csfml->player.speed_env.y += 0.01;
    return (1);
}

int gravity_mobs2(csfml_t *csfml, sfFloatRect box)
{
    box.top += 1.0;
    tile_t *list = csfml->map.layer[1];

    while (list != NULL) {
        sfFloatRect temp = list->hitbox;
        if (list->on && sfFloatRect_intersects(&box, &temp, NULL) == sfTrue)
            return (0);
        list = list->next;
    }
    return (1);
}

void gravity_mobs(csfml_t *csfml)
{
    mobs_t *mob = csfml->map.mobs;

    for (; mob && mob->stats.type != RIEN; mob = mob->next) {
        if (gravity_mobs2(csfml, mob->stats.hitbox) == 1 &&
        mob->stats.grav == 1)
            mob->speed.y += 0.5;
        else if (gravity_mobs2(
        csfml, mob->stats.hitbox) == 1 && mob->stats.grav == 0)
            mob->speed.y -= 0.5;
    }
}

void gravity_strenght(csfml_t *csfml)
{
    sfFloatRect box = csfml->player.box;
    csfml->player.airborne = gravity_player(csfml);
    gravity_mobs(csfml);
    if (csfml->player.airborne == 0)
        pos_ground(csfml, box);
}