/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init map
*/

#include "rpg.h"

void init_transit(transit_t *transit)
{
    transit->movex = 0;
    transit->movey = 0;
    transit->count = 0;
    transit->room = 0;
    transit->door = 0;
    transit->state = 0;
    transit->in = (sfVector2f) {0, 0};
    transit->out = (sfVector2f) {0, 0};
    transit->door_tile = NULL;
}

int init_door_sp(door_sp_t *door)
{
    door->anim_count = 0;
    door->frame_count = 0;
    door->tex[0] = sfTexture_createFromFile(
        "assets/entities/doors.png", NULL);
    door->tex[1] = sfTexture_createFromFile(
        "assets/entities/gate.png", NULL);
    if (!door->tex[0] || !door->tex[1]) return (84);
    door->door = sfSprite_create();
    door->gate = sfSprite_create();
    if (!door->gate || !door->door) return (84);
    sfSprite_setTexture(door->door, door->tex[0], sfFalse);
    sfSprite_setTexture(door->gate, door->tex[1], sfFalse);
    sfSprite_setScale(door->door, (sfVector2f) {3, 3});
    sfSprite_setScale(door->gate, (sfVector2f) {3, 3});
    sfSprite_setTextureRect(door->gate, (sfIntRect) {0, 0, 16, 108});
    return (0);
}

int init_map3(tilemap_t *map)
{
    map->nb = NONE;
    map->stop = NULL;
    map->doors = NULL;
    map->entities = NULL;
    map->layer[0] = NULL;
    map->layer[1] = NULL;
    map->layer[2] = NULL;
    map->breakable = NULL;
    map->entities = NULL;
    map->boss = NULL;
    return (0);
}

int init_map2(tilemap_t *map)
{
    sfSprite_setScale(map->bg2, (sfVector2f) {-2, 1});
    sfSprite_setTexture(map->bg3, map->text_bg, sfFalse);
    sfSprite_setScale(map->bg3, (sfVector2f) {2, 1});
    sfSprite_setTexture(map->bg4, map->text_bg, sfFalse);
    sfSprite_setScale(map->bg4, (sfVector2f) {-2, 1});
    sfSprite_setTexture(map->bg5, map->text_bg, sfFalse);
    sfSprite_setScale(map->bg5, (sfVector2f) {2, 1});
    sfSprite_setTexture(map->bg6, map->text_bg, sfFalse);
    sfSprite_setScale(map->bg6, (sfVector2f) {-2, 1});
    for (int i = 0; i < 1; i++)
        if (!map->text_mob[i]) return (84);
    map->mobs = init_list_mobs();
    if (!map->mobs) return (84);
    map->tile = init_tile(map->tex_bloc);
    if (!map->tile) return (84);
    map->travel = init_way(44);
    if (!map->travel) return (84);
    if (init_door_sp(&map->door_sp) == 84) return (84);
    init_transit(&map->transit);
    init_map3(map);
    return (0);
}

int init_map(tilemap_t *map)
{
    map->tex_bloc = sfTexture_createFromFile("assets/blocks/blocs.png", NULL);
    map->text_mob[CHARGE] = sfTexture_createFromFile("assets/mobs/CHARGE.png", NULL);
    map->text_mob[JUMP] = sfTexture_createFromFile("assets/mobs/CHARGE.png", NULL);
    map->text_mob[TRAP] = sfTexture_createFromFile("assets/mobs/TRAP.png", NULL);
    map->text_mob[KRAB] = sfTexture_createFromFile("assets/mobs/KRAB.png", NULL);
    map->text_mob[INSECT] = sfTexture_createFromFile("assets/mobs/INSECT.png", NULL);
    map->text_mob[ZOMBIE] = sfTexture_createFromFile("assets/mobs/ZOMBIE.png", NULL);
    map->text_bg = sfTexture_createFromFile("assets/sky2.png", NULL);
    map->bg1 = sfSprite_create();
    map->bg2 = sfSprite_create();
    map->bg3 = sfSprite_create();
    map->bg4 = sfSprite_create();
    map->bg5 = sfSprite_create();
    map->bg6 = sfSprite_create();
    if (!map->text_bg || !map->bg1 || !map->bg2 || !map->bg3 || !map->bg4) return (84);
    sfSprite_setTexture(map->bg1, map->text_bg, sfFalse);
    sfSprite_setScale(map->bg1, (sfVector2f) {2, 1});
    sfSprite_setTexture(map->bg2, map->text_bg, sfFalse);
    init_map2(map);
    return (0);
}