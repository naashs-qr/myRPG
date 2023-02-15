/*
** EPITECH PROJECT, 2021
** init_vector.c
** File description:
** init all vectors
*/

#include "rpg.h"

void init_vector(vector_t *vector)
{
    vector->pos_player = create_vector(1920.0, 648.0);
    vector->rect_player = create_rect(0.0, 220.0, 200.0, 200.0);
    vector->rect_mobs_1 = create_rect(0.0, 0.0, 100.0, 100.0);
}

sfVector2f init_vector_for_mobs(vector_t *vector, short pos_mobs)
{
    if (pos_mobs == 0)
        vector->pos_mobs = create_vector(10.0, 10.0);
    else
        vector->pos_mobs = create_vector(1900.0, 648.0);
    return vector->pos_mobs;
}

