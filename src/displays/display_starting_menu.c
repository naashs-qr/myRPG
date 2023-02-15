/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

int event_how_menu(csfml_t *csfml)
{
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            return (1);
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
            return (1);
        }
    }
    return (0);
}

void display_starting_menu3(csfml_t *csfml)
{
    if (csfml->var.state_starting_menu == 3) {
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.bg.sprite, NULL);
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.arrow.sprite, NULL);
        if (csfml->interface.starting_menu.state_eric == 1)
            sfRenderWindow_drawSprite(csfml->var.window,
            csfml->interface.starting_menu.check1.sprite, NULL);
        if (csfml->interface.starting_menu.state_music == 1)
            sfRenderWindow_drawSprite(csfml->var.window,
            csfml->interface.starting_menu.check2.sprite, NULL);
        if (csfml->interface.starting_menu.state_sound == 1)
            sfRenderWindow_drawSprite(csfml->var.window,
            csfml->interface.starting_menu.check3.sprite, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.eric, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.music, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.retour2, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.sound, NULL);
    }
}

void display_starting_menu2(csfml_t *csfml)
{
    if (csfml->var.state_starting_menu == 2) {
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.bg.sprite, NULL);
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.arrow.sprite, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.previous_save, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.new_game, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.retour, NULL);
    }
    display_starting_menu3(csfml);
}

void display_starting_menu(csfml_t *csfml)
{
    sfRenderWindow_clear(csfml->var.window, sfBlack);
    if (csfml->var.state_starting_menu == 0) {
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.main_menu.sprite, NULL);
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.alien.sprite, NULL); }
    if (csfml->var.state_starting_menu == 1) {
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.bg.sprite, NULL);
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.arrow.sprite, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.start_game, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.option, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.how_play, NULL);
        sfRenderWindow_drawText(csfml->var.window,
        csfml->interface.starting_menu.quit, NULL); }
    display_starting_menu2(csfml);
}