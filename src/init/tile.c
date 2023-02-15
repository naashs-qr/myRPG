/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init tile
*/

#include "rpg.h"

void create_tile2(tile_t *tile)
{
    tile->next = NULL;
    tile->n_stop = NULL;
    tile->n_door = NULL;
    tile->n_layer = NULL;
    tile->n_break = NULL;
    tile->n_spike = NULL;
}

tile_t *create_tile(sfTexture *blocs)
{
    tile_t *tile = malloc(sizeof(tile_t));
    int width = 1920 / 14;
    int height = 1080 / 10;
    //sfVector2f scale = {0.81, 0.64};

    if (!tile) return (NULL);
    tile->type = VOID;
    tile->on = 1;
    tile->hitbox = (sfFloatRect) {0, 0, width, height};
    tile->sprite = sfSprite_create();
    if (!tile->sprite) return (NULL);
    sfSprite_setTexture(tile->sprite, blocs, sfFalse);
    sfSprite_setTextureRect(tile->sprite,
        (sfIntRect) {0, 0, 138, 108});
    //sfSprite_setScale(tile->sprite, scale);
    create_tile2(tile);
    return (tile);
}

void add_tile(tile_t *tile, sfTexture *blocs)
{
    tile_t *new = create_tile(blocs);
    tile_t *tmp;

    if (!new) {
        tile = NULL;
        return;
    }
    tmp = tile;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
}

tile_t *init_tile(sfTexture *texture)
{
    tile_t *res = create_tile(texture);

    for (int j = 1; j < 840 && res; j++) {
            add_tile(res, texture);
    }
    return (res);
}