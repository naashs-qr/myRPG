/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void event_input_menu_pause_bis2(csfml_t *csfml)
{
    if (csfml->interface.pause.pos == 0) {
        if (csfml->interface.pause.state_music == 1)
            csfml->interface.pause.state_music = 0;
        else
            csfml->interface.pause.state_music = 1;
    }
    if (csfml->interface.pause.pos == 1) {
        if (csfml->interface.pause.state_sound == 1)
            csfml->interface.pause.state_sound = 0;
        else
            csfml->interface.pause.state_sound = 1;
        csfml->interface.starting_menu.state_sound =
        csfml->interface.pause.state_sound;
    }
    if (csfml->interface.pause.pos == 2) {
        csfml->interface.pause.state_pause = 0;
    }
    csfml->interface.pause.cooldown = 10;
}

void event_input_menu_pause2(csfml_t *csfml)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        csfml->interface.menu = 0;
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (csfml->interface.pause.pos != 2)
            csfml->interface.pause.pos += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (csfml->interface.pause.pos != 0)
            csfml->interface.pause.pos -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) &&
    csfml->interface.pause.cooldown == 0) {
        event_input_menu_pause_bis2(csfml);
    }
}

void event_input_menu_pause_bis(csfml_t *csfml)
{
    if (csfml->interface.pause.pos == 0)
        csfml->interface.menu = 0;
    if (csfml->interface.pause.pos == 1)
        csfml->interface.pause.state_pause = 1;
    if (csfml->interface.pause.pos == 2) {
        csfml->var.scene = 0;
        csfml->interface.menu = 0;
        sfView_reset(csfml->var.view, (sfFloatRect) {0, 0, 1920, 1080});
        csfml->var.view_rect.left = 0;
        csfml->var.view_rect.top = 0;
        csfml->var.state_starting_menu = 0;
    }
    if (csfml->interface.pause.pos == 3) {
        sfRenderWindow_close(csfml->var.window);
        csfml->var.wind = 1;
        csfml->interface.menu = 0;
    }
    csfml->interface.pause.cooldown = 10;
}

void event_input_menu_pause(csfml_t *csfml)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        csfml->interface.menu = 0;
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (csfml->interface.pause.pos != 3)
            csfml->interface.pause.pos += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (csfml->interface.pause.pos != 0)
            csfml->interface.pause.pos -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) &&
    csfml->interface.pause.cooldown == 0) {
        event_input_menu_pause_bis(csfml);
    }
}

void event_pause_menu(csfml_t *csfml)
{
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        if (csfml->interface.pause.state_pause == 0)
            event_input_menu_pause(csfml);
        else
            event_input_menu_pause2(csfml);
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
            csfml->interface.menu = 2;
        }
    }
}