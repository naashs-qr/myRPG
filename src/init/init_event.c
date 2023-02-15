/*
** EPITECH PROJECT, 2021
** init.c
** File description:
** all init
*/

#include "rpg.h"

void init_event(csfml_t *csfml)
{
    csfml->event.state[0] = 2;
    csfml->event.nb_room[0] = 29;
    csfml->event.state[1] = 2;
    csfml->event.nb_room[1] = 20;
    csfml->event.nb_mobs[0] = 3;
    csfml->event.nb_mobs[1] = 2;
}