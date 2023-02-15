/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

int init_bosses(csfml_t *csfml, tilemap_t *map)
{
    if (init_boss1(csfml, &map->all_boss[0]) == 84) return (84);
    return (0);
}

void manage_boss(csfml_t *csfml, boss_t *boss)
{
    short act = boss->act;

    if (act == IDLE) boss->idle(&csfml->player, boss);
    if (act == MVT) boss->mvt(&csfml->player, boss);
    if (act == ATK) boss->atk(&csfml->player, boss);
    boss->animate(boss);
}