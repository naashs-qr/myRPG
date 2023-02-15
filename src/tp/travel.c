/*
** EPITECH PROJECT, 2021
** defender
** File description:
** collision
*/

#include "rpg.h"

void change_way(travel_t *travel, tile_t *tile, char *way)
{
    travel->tile = tile;
    if (way) {
        travel->door = my_getnbr(way) - 1;
        travel->room = my_getnbr(&way[2]) - 1;
    } else {
        travel->door = -1;
        travel->room = -1;
    }
}

void tp(csfml_t *csfml, travel_t *entry)
{
    sfVector2f view = sfView_getCenter(csfml->var.view);
    sfVector2f view_move = {0, 0};
    tile_t *tmp = csfml->map.doors;
    csfml->map.transit.room = entry->room;
    csfml->map.transit.door = entry->door;
    if (view.x - csfml->player.box.left < 0)
        view_move.x = 1920 + BLOCX + 30;
    else
        view_move.x = - (1920 + BLOCX + 30);
    csfml->map.transit.movex = view_move.x / 60;
    csfml->map.transit.in = (sfVector2f)
        {entry->tile->hitbox.left, entry->tile->hitbox.top};
    for (; tmp; tmp = tmp->n_door)
        if (sfFloatRect_intersects(&tmp->hitbox, &csfml->player.box, NULL))
            csfml->map.transit.door_tile = tmp;
}

void manage_travel(csfml_t *csfml, player_t *player, travel_t *travel)
{
    travel_t *tmp = csfml->map.travel;
    int i = 0;

    for (; tmp && tmp->tile && !sfFloatRect_intersects(&player->box,
        &tmp->tile->hitbox, NULL); i++, tmp = tmp->next);
    if (!tmp || !tmp->tile) return;
    tp(csfml, tmp);
    csfml->var.tp = 1;
    csfml->map.transit.state = 1;
}