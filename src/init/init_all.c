/*
** EPITECH PROJECT, 2021
** init.c
** File description:
** all init
*/

#include "rpg.h"

int init_all(csfml_t *csfml)
{
    if (init_var(&csfml->var) == 84) return (84);
    init_vector(&csfml->vector);
    if (init_script(csfml) == 84) return (84);
    if (init_map(&csfml->map) == 84) return (84);
    if (init_all_entities(csfml, &csfml->map) == 84) return (84);
    if (init_bosses(csfml, &csfml->map) == 84) return (84);
    if (init_player(csfml) == 84) return (84);
    if (init_interface(csfml) == 84) return (84);
    if (init_music(csfml) == 84) return (84);
    init_event(csfml);
    csfml->scene = 0;
    sfRenderWindow_setFramerateLimit(csfml->var.window, 60);
    return (0);
}