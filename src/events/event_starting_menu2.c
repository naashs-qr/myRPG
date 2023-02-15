/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void event_mouse_click_menu(sfMouseButtonEvent event, csfml_t *csfml)
{
    csfml->var.state_starting_menu = 1;
}

void event_input_menu_starting2_bis_cheat(csfml_t *csfml)
{
    sfMusic_stop(csfml->music.menu);
    if (csfml->interface.starting_menu.state_music == 1) {
        sfMusic_play(csfml->music.game);
        sfMusic_setLoop(csfml->music.game, sfTrue);
    }
    if (csfml->interface.scene.state_cine1 == 1) {
        csfml->var.scene = 1;
        csfml->interface.scene.state_cine1 = 0;
    }
    else {
        csfml->var.scene = 2;
        init_player(csfml);
        init_this_room(&csfml->map, &csfml->room[0], csfml);
        sfView_move(csfml->var.view, (sfVector2f) {BLOCX, BLOCY});
        csfml->var.view_rect.left += BLOCX;
        csfml->var.view_rect.top += BLOCY;
    }
    load_save_cheat(csfml);
    csfml->interface.starting_menu.pos = 0;
}

void event_input_menu_starting2_bis1(csfml_t *csfml)
{
    if (csfml->interface.scene.state_cine1 == 1) {
        csfml->var.scene = 1;
        csfml->interface.scene.state_cine1 = 0;
    }
    else {
        csfml->var.scene = 2;
        init_player(csfml);
        init_this_room(&csfml->map, &csfml->room[0], csfml);
        sfView_move(csfml->var.view, (sfVector2f) {BLOCX, BLOCY});
        csfml->var.view_rect.left += BLOCX;
        csfml->var.view_rect.top += BLOCY;
    }
    load_save(csfml);
    csfml->interface.starting_menu.pos = 0;
}

void event_input_menu_starting2_bis2(csfml_t *csfml)
{
    if (csfml->interface.scene.state_cine1 == 1) {
        csfml->var.scene = 1;
        csfml->interface.scene.state_cine1 = 0;
    }
    else {
        csfml->var.scene = 2;
        init_player(csfml);
        init_this_room(&csfml->map, &csfml->room[0], csfml);
        sfView_move(csfml->var.view, (sfVector2f) {BLOCX, BLOCY});
        csfml->var.view_rect.left += BLOCX;
        csfml->var.view_rect.top += BLOCY;
        reset_save(csfml);
    }
    csfml->interface.starting_menu.pos = 0;
}

void event_input_menu_starting2_bis(csfml_t *csfml)
{
    if (csfml->interface.starting_menu.pos == 0) {
        event_input_menu_starting2_bis1(csfml);
    }
    if (csfml->interface.starting_menu.pos == 1) {
        event_input_menu_starting2_bis2(csfml);
    }
    if (csfml->interface.starting_menu.pos == 2)
        csfml->var.state_starting_menu = 1;
    else {
        sfMusic_stop(csfml->music.menu);
        if (csfml->interface.starting_menu.state_music == 1) {
            sfMusic_play(csfml->music.game);
            sfMusic_setLoop(csfml->music.game, sfTrue);
        }
    }
}

void event_input_menu_starting2(csfml_t *csfml)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (csfml->interface.starting_menu.pos != 2)
            csfml->interface.starting_menu.pos += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        if (csfml->interface.starting_menu.pos != 0)
            csfml->interface.starting_menu.pos -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && csfml->interface.starting_menu.cooldown == 0) {
        event_input_menu_starting2_bis(csfml);
        csfml->interface.starting_menu.cooldown = 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyX)) {
        event_input_menu_starting2_bis_cheat(csfml);
        csfml->interface.starting_menu.cooldown = 10;
    }
}