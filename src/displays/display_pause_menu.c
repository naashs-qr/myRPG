/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void display_pause_menu2(csfml_t *csfml)
{
    if (csfml->interface.pause.state_pause == 1) {
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.pause.music, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.pause.sound, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.pause.retour, NULL);
        if (csfml->interface.pause.state_music == 1) {
            sfRenderWindow_drawSprite(csfml->var.window,
            csfml->interface.pause.check1.sprite, NULL);
        }
        if (csfml->interface.pause.state_sound == 1) {
            sfRenderWindow_drawSprite(csfml->var.window,
            csfml->interface.pause.check2.sprite, NULL);
        }
    }
}

void display_pause_menu(csfml_t *csfml)
{
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.pause.pause_menu.sprite, NULL);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.pause.arrow.sprite, NULL);
    if (csfml->interface.pause.state_pause == 0) {
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.pause.resume, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.pause.option, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.pause.menu, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.pause.quit, NULL);
    }
    display_pause_menu2(csfml);
}