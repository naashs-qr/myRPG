/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void display_map(variable_t *var, tilemap_t *map)
{
    sfRenderWindow_drawSprite(var->window, map->bg1, NULL);
    sfRenderWindow_drawSprite(var->window, map->bg2, NULL);
    sfRenderWindow_drawSprite(var->window, map->bg3, NULL);
    sfRenderWindow_drawSprite(var->window, map->bg4, NULL);
    sfRenderWindow_drawSprite(var->window, map->bg5, NULL);
    sfRenderWindow_drawSprite(var->window, map->bg6, NULL);
    for (tile_t *tmp = map->layer[0]; tmp != NULL; tmp = tmp->n_layer)
        sfRenderWindow_drawSprite(var->window, tmp->sprite, NULL);
    for (entity_t *tmp = map->entities; tmp; tmp = tmp->next)
        if (tmp->state != -1)
            sfRenderWindow_drawSprite(var->window, tmp->sprite, NULL);
    for (tile_t *tmp = map->layer[1]; tmp != NULL; tmp = tmp->n_layer)
        if (tmp->on)
            sfRenderWindow_drawSprite(var->window, tmp->sprite, NULL);
}

void display_bullet(variable_t *var, player_t *player)
{
    int i;
    for (i = 0; i < 10; i++)
        if (player->bullet[i].on == 1)
            sfRenderWindow_drawSprite(var->window,
                player->bullet[i].sprite, NULL);
    for (i = 0; i < 3; i++)
        if (player->bomb[i].on == 1)
            sfRenderWindow_drawSprite(var->window,
                player->bomb[i].sprite, NULL);
}

void display_ui(csfml_t *csfml)
{
    if (csfml->player.count_display_xp > 1)
        sfRenderWindow_drawText(csfml->var.window, csfml->player.xp_won, NULL);
    if (csfml->player.state_interact == 1)
        sfRenderWindow_drawText(csfml->var.window,
        csfml->player.interact, NULL);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.ui.hp_bar.sprite, NULL);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.ui.hp.sprite, NULL);
    sfSprite *tab[4] = {csfml->interface.ui.icon_charge.sprite,
    csfml->interface.ui.icon_plasma.sprite,
    csfml->interface.ui.icon_ice.sprite,
    csfml->interface.ui.icon_missile.sprite};
    sfRenderWindow_drawSprite(csfml->var.window,
    tab[csfml->player.select_shot], NULL);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.ui.missile.sprite, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.ui.cap_missile, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.ui.hp_number, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.ui.selected, NULL);
    if (csfml->interface.end == 1)
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.time, NULL);
}

int display_element2(csfml_t *csfml)
{
    if (csfml->player.hurt.color.a > 0)
        sfRenderWindow_drawSprite(
            csfml->var.window, csfml->player.hurt.sprite, NULL);
    if (csfml->player.state_salto == 1) {
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->player.salto.sprite, NULL);
    }
    if (csfml->var.count_charge > 10 &&
    csfml->var.count_animate_ball == 0 &&
    csfml->player.select_shot != 3
    && csfml->var.hang_state != 1) {
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->player.charge_anim.sprite, NULL);
    }
    display_ui(csfml);
    return (0);
}

int display_element(csfml_t *csfml)
{
    sfRenderWindow_clear(csfml->var.window, sfBlack);
    sfRenderWindow_setView(csfml->var.window, csfml->var.view);
    display_map(&csfml->var, &csfml->map);
    sfRenderWindow_drawSprite(
        csfml->var.window, csfml->player.obj.sprite, NULL);
    display_bullet(&csfml->var, &csfml->player);
    display_map_fg(&csfml->var, &csfml->map);
    display_mobs(&csfml->var, csfml->map.mobs);
    display_element2(csfml);
    return (0);
}