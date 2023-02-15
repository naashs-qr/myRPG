/*
** EPITECH PROJECT, 2021
** init_var.c
** File description:
** init
*/

#include "rpg.h"

int init_var3(variable_t *var)
{
    var->count_animate_bombe = 0;
    var->double_jump = 0;
    var->cooldown_ball = 0;
    var->cooldown_double_jump = 0;
    var->hang_state = 0;
    var->count_recup_stat = 500;
    var->state_starting_menu = 0;
    var->cooldown_status = 0;
    var->count_animate_ball = 0;
    var->input_shoot = 0;
    var->input_aim = 0;
    var->count_animate_jump = 0;
    var->count_animate_player = 10;
    var->tp = 0;
    var->view_rect = (sfFloatRect) {0, 0, 1920, 1080};
    return (0);
}

int init_var2(variable_t *var)
{
    var->wind = 0;
    var->scene = 0;
    var->count_cinematik1 = 1;
    var->count_charge = 0;
    var->count_cinematik2 = 1;
    var->count_cinematik3 = 1;
    var->count_climb = 0;
    var->cooldown_switch = 0;
    var->cooldown_menu = 0;
    var->cooldown_shoot = 0;
    var->input = 0;
    var->input_jump = 0;
    var->save_shoot = 0;
    var->state_shoot = 0;
    init_var3(var);
    return (0);
}

int init_var(variable_t *var)
{
    sfVideoMode video = {1900, 1080, 32};
    var->clock = sfClock_create();
    if (!var->clock) return (84);
    var->window = sfRenderWindow_create(video,
        "Window", sfDefaultStyle, NULL);
    if (!var->window) return (84);
    var->font = sfFont_createFromFile("assets/police/arial.ttf");
    if (!var->font) return (84);
    var->font2 = sfFont_createFromFile("assets/police/police1.ttf");
    if (!var->font2) return (84);
    init_var2(var);
    var->view = sfView_createFromRect(var->view_rect);
    if (!var->view) return (84);
    if (init_var_shoot(var) == 84) return (84);
    return (0);
}