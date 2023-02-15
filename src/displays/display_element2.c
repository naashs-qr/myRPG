/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void display_mobs(variable_t *var, mobs_t *mobs)
{
    bullet_mobs_t *tmp2;

    for (mobs_t *tmp = mobs; tmp != NULL && tmp->stats.type != RIEN; tmp = tmp->next) {
        if (tmp->state) {
            sfRenderWindow_drawSprite(var->window, tmp->sprite, NULL);
            tmp2 = tmp->bullet;
            for (register short i = 0; i < 20; i++) {
                if (tmp2[i].on == 1)  {
                    sfRenderWindow_drawSprite(var->window, tmp2->sprite, NULL);
                }
            }
        }
    }
}

void display_doors2(
variable_t *var, tilemap_t *map, sfIntRect rect, sfVector2f pos)
{
    sfSprite_setTextureRect(map->door_sp.gate, rect);
    sfSprite_setScale(map->door_sp.gate, (sfVector2f) {3, 3});
    sfSprite_setPosition(map->door_sp.gate, pos);
    sfRenderWindow_drawSprite(var->window, map->door_sp.gate, NULL);
    sfSprite_setScale(map->door_sp.gate, (sfVector2f) {-3, 3});
    pos.x += 3 * BLOCX + 11 * 6;
    sfSprite_setPosition(map->door_sp.gate, pos);
    sfRenderWindow_drawSprite(var->window, map->door_sp.gate, NULL);
}

void display_doors(variable_t *var, tilemap_t *map)
{
    sfVector2f pos;
    sfIntRect rect;

    for (tile_t *tmp = map->doors; tmp != NULL; tmp = tmp->n_door) {
        pos = (sfVector2f) {tmp->hitbox.left, tmp->hitbox.top};
        sfSprite_setPosition(map->door_sp.door, pos);
        sfRenderWindow_drawSprite(var->window, map->door_sp.door, NULL);
        if (tmp->on) {
            rect = (sfIntRect) {0, 0, 13, 105};
            if (tmp->type == GREEN) rect.top = 105;
            if (tmp->type == RED) rect.top = 210;
            if (map->door_sp.anim_count == 1) rect.left = 13;
            pos.x -= 11 * 3;
            display_doors2(var, map, rect, pos); }
    }
    map->door_sp.frame_count++;
    if (map->door_sp.frame_count >= 15) {
        map->door_sp.anim_count++;
        map->door_sp.frame_count = 0;
        if (map->door_sp.anim_count >= 2)
            map->door_sp.anim_count = 0; }
}

void display_map_fg(variable_t *var, tilemap_t *map)
{
    for (tile_t *tmp = map->layer[2]; tmp != NULL; tmp = tmp->n_layer)
        sfRenderWindow_drawSprite(var->window, tmp->sprite, NULL);
    display_doors(var, map);
}