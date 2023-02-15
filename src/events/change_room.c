/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void change_blocs(tilemap_t *map, room_t *script)
{
    tile_t *tile = map->tile;
    int x = 0;
    int y = 0;

    change_blocs2(map, script);
    for (int i = 0; script->map[i] != '\0'; i++) {
        if (script->map[i] == '\n') {
            x = 0;
            y++;
        } else if (script->map[i] == '.') x++;
        else {
            tilecraft(tile, script->map[i], x, y);
            tile = tile->next;
            x++; }
    }
    for (; tile; tile = tile->next)
        tilecraft(tile, '.', 0, 0);
    get_special_tiles(map, script);
}

void reset_tile(tilemap_t *map)
{
    tile_t *tmp;

    for (tmp = map->doors; tmp; tmp = tmp->n_door) {
        tmp->hitbox.height /= 3;
        tmp->hitbox.width /= 3;
        tmp->hitbox.left -= BLOCX;
    }
    for (tmp = map->layer[1]; tmp; tmp = tmp->n_layer) {
        if (tmp->type == UP_SPIKE) {
        sfSprite_setScale(tmp->sprite, (sfVector2f) {1, 1});
        sfSprite_move(tmp->sprite, (sfVector2f) {0, -BLOCY});
        }
    }
}

void reset_shots(player_t *player)
{
    for (int i = 0; i < 10; i++)
        player->bullet[i].on = 0;
}

void init_this_room(tilemap_t *map, room_t *script, csfml_t *csfml)
{
    reset_tile(map);
    reset_shots(&csfml->player);
    change_blocs(map, script);
    set_background(csfml);
    if (script->ent >= 0 && map->all_entities[script->ent].state != -1)
        map->entities = &map->all_entities[script->ent];
    else
        map->entities = NULL;
    transform_mobs(map, script);
    map->boss = &map->all_boss[0];
}