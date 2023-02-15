/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void set_background(csfml_t *csfml)
{
    sfVector2f pos = sfView_getCenter(csfml->var.view);
    pos.y -= 300.0;
    pos.x -= 900.0;
    sfSprite_setPosition(csfml->map.bg1, pos);
    pos.y -= 1080;
    sfSprite_setPosition(csfml->map.bg3, pos);
    pos.y += 2160.0;
    sfSprite_setPosition(csfml->map.bg5, pos);
}

void get_special_tiles2(
tilemap_t *map, room_t *script, tile_t *tile, travel_t *tmp)
{
    if (tile->type == EDGE) {
        tile->n_stop = map->stop;
        map->stop = tile; }
    if (tile->type == GROUND || tile->type == GREEN || tile->type == RED) {
        tile->n_door = map->doors;
        map->doors = tile; }
    if (tile->type == DEBR || tile->type == PATH) {
        tile->n_break = map->breakable;
        map->breakable = tile;
    }
    if (tile->type == UP_SPIKE || tile->type == DO_SPIKE) {
        tile->n_spike = map->spike;
        map->spike = tile;
    }
}

void get_special_tiles(tilemap_t *map, room_t *script)
{
    tile_t *tile = map->tile;
    travel_t *tmp = map->travel;
    int i = 0;
    int lay;

    for (tile = map->tile; tile && tile->type != VOID; tile = tile->next) {
        get_special_tiles2(map, script, tile, tmp);
        if (tile->type == TRAVEL && script->way) {
            change_way(tmp, tile, script->way[i]);
            i++;
            tmp = tmp->next;
        }
        lay = tile->touch + 1;
        tile->n_layer = map->layer[lay];
        map->layer[lay] = tile;
    }
    for (; tmp; tmp = tmp->next) change_way(tmp, NULL, NULL);
}

void change_blocs2(tilemap_t *map, room_t *script)
{
    map->stop = NULL;
    map->doors = NULL;
    map->layer[0] = NULL;
    map->layer[1] = NULL;
    map->layer[2] = NULL;
    map->breakable = NULL;
    map->spike = NULL;
}
