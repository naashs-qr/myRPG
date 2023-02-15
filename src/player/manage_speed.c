/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** bombe
*/

#include "rpg.h"

void manage_speed_env_x(csfml_t *csfml)
{
    if (csfml->player.speed_env.x != 0) {
        if (csfml->player.speed_env.x > 0)
            csfml->player.speed_env.x -= 3;
        else
            csfml->player.speed_env.x += 3;
        if (csfml->player.speed_env.x < 3 && csfml->player.speed_env.x > -3)
            csfml->player.speed_env.x = 0;
        if (csfml->player.speed_env.x > 30.0)
            csfml->player.speed_env.x = 30.0;
        if (csfml->player.speed_env.x < -30.0)
            csfml->player.speed_env.x = -30.0;
    }
}

void manage_speed_x(csfml_t *csfml)
{
    if (csfml->var.input == 1 && csfml->var.hang_state != 1 &&
    csfml->player.speed.x < 20) {
        if (csfml->player.speed.x <= 0)
            csfml->player.speed.x = 9;
        csfml->player.speed.x += 1.0;
    }
    else if (csfml->var.input == 2 &&
    csfml->var.hang_state != 1 && csfml->player.speed.x > -20) {
        if (csfml->player.speed.x >= 0)
            csfml->player.speed.x = -9;
        csfml->player.speed.x -= 1.0;
    }
    if (csfml->player.speed.x > 30.0)
        csfml->player.speed.x = 30.0;
    if (csfml->player.speed.x < -30.0)
        csfml->player.speed.x = -30.0;
    manage_speed_env_x(csfml);
}