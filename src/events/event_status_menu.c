/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void event_input_menu_status_bis2(csfml_t *csfml)
{
    int tab[3] = {csfml->player.stat.lvl_hp,
    csfml->player.stat.lvl_dammage_missile,
    csfml->player.stat.lvl_cap_missile};
    if (tab[csfml->interface.status.pos] < 5) {
        tab[csfml->interface.status.pos] += 1;
        csfml->player.stat.pt_comp -= 1;
        csfml->player.stat.lvl_hp = tab[0];
        csfml->player.stat.lvl_dammage_missile = tab[1];
        csfml->player.stat.lvl_cap_missile = tab[2];
    }
}

void event_input_menu_status2(csfml_t *csfml)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && csfml->var.cooldown_status == 0) {
        if (csfml->interface.status.pos2 == 1 &&
        (csfml->interface.status.pos >= 0 && csfml->interface.status.pos < 4)) {
            if (csfml->player.stat.bonus_state[csfml->interface.status.pos]
            == 1) {
                csfml->interface.status.type_beam =
                csfml->interface.status.pos + 1; } }
        else if (csfml->interface.status.pos2 == 2 &&
        csfml->player.stat.pt_comp != 0) {
            event_input_menu_status_bis2(csfml);
        }
        csfml->var.cooldown_status = 5;
    }
    if (csfml->var.cooldown_status > 0) csfml->var.cooldown_status -= 1;
}

void event_input_menu_status(csfml_t *csfml)
{
    if (sfKeyboard_isKeyPressed(sfKeyTab) || sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (csfml->var.cooldown_menu == 0)
            csfml->interface.menu = 0;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        if (csfml->interface.status.pos2 == 1 && csfml->interface.status.pos != 7)
            csfml->interface.status.pos += 1;
        if (csfml->interface.status.pos2 == 2 && csfml->interface.status.pos != 2)
            csfml->interface.status.pos += 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && csfml->interface.status.pos != 0)
        csfml->interface.status.pos -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && csfml->interface.status.pos != 7)
        csfml->interface.status.pos2 = 1;
    if (sfKeyboard_isKeyPressed(sfKeyRight) && csfml->interface.status.pos < 3)
        csfml->interface.status.pos2 = 2;
    event_input_menu_status2(csfml);
}

void event_status_menu(csfml_t *csfml)
{
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
    event_input_menu_status(csfml);
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
            csfml->interface.menu = 2;
        }
    }
}