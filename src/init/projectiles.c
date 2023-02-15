/*
** EPITECH PROJECT, 2021
** init_vector.c
** File description:
** init all vectors
*/

#include "rpg.h"

int init_beam1_var(stat_shoot_t *shoot)
{
    shoot->texture = sfTexture_createFromFile(
        "assets/player/charge_beam2.png", NULL);
    if (!shoot->texture) return (84);
    shoot->anim = 1;
    shoot->anim2 = 1;
    shoot->charge = 1;
    shoot->dmg = 10;
    shoot->dmg_max = 20;
    shoot->dig = 0;
    shoot->speed_line = (sfVector2f) {22, 0};
    shoot->speed_diag = (sfVector2f) {15.5, 15.5};
    shoot->rect = (sfIntRect) {0, 0, 100, 70};
    shoot->hitbox = (sfFloatRect) {0, 0, 100, 70};
    return (0);
}

int init_beam2_var(stat_shoot_t *shoot)
{
    shoot->texture = sfTexture_createFromFile(
        "assets/player/plasma_beam2.png", NULL);
    if (!shoot->texture) return (84);
    shoot->anim = 1;
    shoot->charge = 1;
    shoot->dmg = 15;
    shoot->dmg_max = 30;
    shoot->dig = 0;
    shoot->speed_line = (sfVector2f) {22, 0};
    shoot->speed_diag = (sfVector2f) {15.5, 15.5};
    shoot->rect = (sfIntRect) {0, 0, 100, 70};
    shoot->hitbox = (sfFloatRect) {0, 0, 100, 70};
    return (0);
}

int init_beam3_var(stat_shoot_t *shoot)
{
    shoot->texture = sfTexture_createFromFile(
        "assets/player/ice_beam2.png", NULL);
    if (!shoot->texture) return (84);
    shoot->anim = 1;
    shoot->charge = 1;
    shoot->dmg = 20;
    shoot->dmg_max = 40;
    shoot->dig = 0;
    shoot->speed_line = (sfVector2f) {22, 0};
    shoot->speed_diag = (sfVector2f) {15.5, 15.5};
    shoot->rect = (sfIntRect) {0, 0, 100, 70};
    shoot->hitbox = (sfFloatRect) {0, 0, 100, 70};
    return (0);
}

int init_missil_var(stat_shoot_t *shoot)
{
    shoot->texture = sfTexture_createFromFile(
        "assets/player/shoot2.png", NULL);
    if (!shoot->texture) return (84);
    shoot->anim = 1;
    shoot->charge = 0;
    shoot->dmg = 30;
    shoot->dmg_max = 30;
    shoot->dig = 1;
    shoot->speed_line = (sfVector2f) {22, 0};
    shoot->speed_diag = (sfVector2f) {15.5, 15.5};
    shoot->rect = (sfIntRect) {0, 0, 100, 70};
    shoot->hitbox = (sfFloatRect) {0, 0, 100, 70};
    return (0);
}

int init_var_shoot(variable_t *var)
{
    if(init_beam1_var(&var->shoot[0]) == 84) return (84);
    if(init_beam2_var(&var->shoot[1]) == 84) return (84);
    if(init_beam3_var(&var->shoot[2]) == 84) return (84);
    if(init_missil_var(&var->shoot[3]) == 84) return (84);
    return (0);
}