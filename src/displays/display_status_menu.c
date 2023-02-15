/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void display_status_menu2(csfml_t *csfml)
{
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.double_jump_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.salto_electrical_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.cap_missile_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.dammage_missile_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.hp_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.lvl_hp_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.lvl_dammage_missile_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.lvl_cap_missile_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.pt_comp_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.lvl_player_txt, NULL);
}

void display_status_menu(csfml_t *csfml)
{
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.status.status_menu.sprite, NULL);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.status.arrow.sprite, NULL);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.status.check.sprite, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.beam_charge_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.beam_ice_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.beam_plasma_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.ball_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.bombe_txt, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.status.missile_txt, NULL);
    display_status_menu2(csfml);
}