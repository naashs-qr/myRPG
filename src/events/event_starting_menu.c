/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void event_input_menu_starting_bis(csfml_t *csfml)
{
    if (csfml->interface.starting_menu.pos == 0) {
        csfml->var.state_starting_menu = 2;
    }
    if (csfml->interface.starting_menu.pos == 1)
        csfml->var.state_starting_menu = 3;
    if (csfml->interface.starting_menu.pos == 2) {
        how_to_play(csfml);
    }
    if (csfml->interface.starting_menu.pos == 3) {
        sfRenderWindow_close(csfml->var.window);
        csfml->var.wind = 1;
        csfml->interface.menu = 0;
    }
}

void event_input_menu_starting(csfml_t *csfml)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (csfml->interface.starting_menu.pos != 3)
            csfml->interface.starting_menu.pos += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (csfml->interface.starting_menu.pos != 0)
            csfml->interface.starting_menu.pos -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) &&
    csfml->interface.starting_menu.cooldown == 0)
    {
        event_input_menu_starting_bis(csfml);
        csfml->interface.starting_menu.cooldown = 10;
    }
}

void event_input_menu_starting3_bis(csfml_t *csfml)
{
    if (csfml->interface.starting_menu.pos == 0) {
        if (csfml->interface.starting_menu.state_music == 0)
            csfml->interface.starting_menu.state_music = 1;
        else
            csfml->interface.starting_menu.state_music = 0;
        csfml->interface.pause.state_music =
        csfml->interface.starting_menu.state_music; }
    if (csfml->interface.starting_menu.pos == 1) {
        if (csfml->interface.starting_menu.state_eric == 0)
            csfml->interface.starting_menu.state_eric = 1;
        else
            csfml->interface.starting_menu.state_eric = 0; }
    if (csfml->interface.starting_menu.pos == 2) {
        if (csfml->interface.starting_menu.state_sound == 0)
            csfml->interface.starting_menu.state_sound = 1;
        else
            csfml->interface.starting_menu.state_sound = 0;
        csfml->interface.pause.state_sound =
        csfml->interface.starting_menu.state_sound;}
    if (csfml->interface.starting_menu.pos == 3)
        csfml->var.state_starting_menu = 1;
}

void event_input_menu_starting3(csfml_t *csfml)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (csfml->interface.starting_menu.pos != 3)
            csfml->interface.starting_menu.pos += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (csfml->interface.starting_menu.pos != 0)
            csfml->interface.starting_menu.pos -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) &&
    csfml->interface.starting_menu.cooldown == 0)
    {
        event_input_menu_starting3_bis(csfml);
        csfml->interface.starting_menu.cooldown = 10;
    }
}

void event_starting_menu(csfml_t *csfml)
{
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        if (csfml->var.state_starting_menu == 3)
            event_input_menu_starting3(csfml);
        if (csfml->var.state_starting_menu == 2)
            event_input_menu_starting2(csfml);
        if (csfml->var.state_starting_menu == 1)
            event_input_menu_starting(csfml);
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
        }
        if (ev.type == sfEvtMouseButtonPressed &&
        csfml->var.state_starting_menu == 0)
            event_mouse_click_menu(ev.mouseButton, csfml);
    }
}