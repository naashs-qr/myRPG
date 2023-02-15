/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"


bool groundcraft(tile_t *tile, enum bloc_type type, sfIntRect rect)
{
    tile->type = type;
    tile->on = 1;
    tile->n_stop = NULL;
    tile->n_layer = NULL;
    tile->n_door = NULL;
    tile->n_break = NULL;
    sfSprite_setTextureRect(tile->sprite, rect);
    return(1);
}

bool doorcraft(tile_t *tile, char c)
{
    groundcraft(tile, GROUND, (sfIntRect) {138, 216, 138, 108});
    tile->hitbox.height *= 3;
    tile->hitbox.width *= 3;
    tile->hitbox.left -= BLOCX;
    if (c == 'v')
        tile->type = GREEN;
    if (c == 'r')
        tile->type = RED;
    return (1);
}

bool layercraft(tile_t *tile, char c)
{
    tile->touch = 0;
    if (c == 'P')
        return (groundcraft(tile, PATH, (sfIntRect) {0, 324, 138, 108}));
    if (c == 'U')
        return (groundcraft(tile, DEBR, (sfIntRect) {414, 324, 138, 108}));
    if (c == 'V')
        return (groundcraft(tile, VENT, (sfIntRect) {0, 432, 138, 108}));
    if (c == 'R')
        return (groundcraft(tile, ROCK, (sfIntRect) {276, 432, 138, 108}));
    if (c == 'S')
        return (groundcraft(tile, SPAWN, (sfIntRect) {0, 108, 138, 108}));
    if (c == 'Y') {
        groundcraft(tile, UP_SPIKE, (sfIntRect) {276, 216, 138, 107});
        sfSprite_setScale(tile->sprite, (sfVector2f) {1, -1});
        sfSprite_move(tile->sprite, (sfVector2f) {0, BLOCY});
        return (1);
    }
    if (c == 'y')
        return (groundcraft(tile, DO_SPIKE, (sfIntRect) {276, 216, 138, 108}));
    return (0);
}

bool bgcraft(tile_t *tile, char c)
{
    tile->touch = -1;
    if (c == 'I') 
        return (groundcraft(tile, EDGE, (sfIntRect) {0, 0, 138, 108}));
    if (c == 'a') 
        return (groundcraft(tile, BG1, (sfIntRect) {0, 432, 138, 108}));
    if (c == 'f') 
        return (groundcraft(tile, BG_G, (sfIntRect) {414, 216, 138, 108}));
    if (c == 'z') 
        return (groundcraft(tile, BG_Z, (sfIntRect) {276, 540, 138, 108}));
    if (c == 'T')
        return (groundcraft(tile, TRAVEL, (sfIntRect) {138, 108, 138, 108}));
    return (0);
}

bool fgcraft(tile_t *tile, char c)
{
    tile->touch = 1;
    if (c == 'C') 
        return (groundcraft(tile, CASTL, (sfIntRect) {138, 108, 138, 108}));
    if (c == 'G' || c == 'r' || c == 'v')
        return (doorcraft(tile, c));
    if (c == 'F') 
        return (groundcraft(tile, GRILLE, (sfIntRect) {414, 216, 138, 108}));
    if (c == 'Z') 
        return (groundcraft(tile, FG_Z, (sfIntRect) {276, 540, 138, 108}));
    return (0);
}

void tilecraft(tile_t *tile, char c, int x, int y)
{
    sfVector2f pos = {x * 1920 / 14, y * 108};

    sfSprite_setPosition(tile->sprite, pos);
    tile->hitbox =
        (sfFloatRect) {pos.x, pos.y, tile->hitbox.width, tile->hitbox.height};
    if (c == '.') {
        groundcraft(tile, VOID, (sfIntRect) {0, 0, 138, 108});
        tile->touch = 2;
        return;
    }
    if (layercraft(tile, c)) return;
    if (fgcraft(tile, c)) return;
    if (bgcraft(tile, c)) return;
}