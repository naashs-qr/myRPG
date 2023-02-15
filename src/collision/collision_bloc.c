/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

int verif_break_collision(
csfml_t *csfml, sfFloatRect box, short dig, player_t *player)
{
    tile_t *list = csfml->map.breakable;
    short access = player->stat.access_player;
    sfFloatRect temp;
    while (list != NULL) {
        temp = list->hitbox;
        if (list->on && dig &&
            sfFloatRect_intersects(&box, &temp, NULL) == sfTrue) {
            list->on = 0;
            return (1); }
        list = list->n_break;
    }
    list = csfml->map.doors;
    while (list != NULL) {
        temp = list->hitbox;
        if (list->on && access >= list->type &&
            sfFloatRect_intersects(&box, &temp, NULL) == sfTrue) {
            list->on = 0;
            return (1); }
        list = list->n_door;
    }
    return (0);
}