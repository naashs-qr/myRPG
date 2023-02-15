/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void manage_doors(csfml_t *csfml, tile_t *doors, player_t* player)
{
    tile_t *tmp = doors;

    for (; tmp; tmp = tmp->next)
        for (int i = 0; i < 10; i++)
            if (sfFloatRect_intersects(&player->bullet[i].stats.hitbox,
                &tmp->hitbox, NULL) && tmp->on) {
                tmp->on = 0;
                player->bullet[i].on = 0;
                }
    
}