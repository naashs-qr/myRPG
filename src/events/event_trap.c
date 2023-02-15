/*
** EPITECH PROJECT, 2020
** event_utils.c
** File description:
** all utils events
*/

#include "rpg.h"

void dialog_trap1(csfml_t *csfml)
{
    char ***dialog = get_dialog("assets/dialog/trap1.txt");
    csfml->interface.menu = 5;
    csfml->interface.chatbox.dialog = dialog[0];
    sfText_setString(csfml->interface.chatbox.text, csfml->interface.chatbox.dialog[0]);
    csfml->interface.chatbox.count_dialog = 0;
    csfml->player.speed.x = 0;
}

void dialog_trap2(csfml_t *csfml)
{
    char ***dialog = get_dialog("assets/dialog/trap2.txt");
    csfml->interface.menu = 5;
    csfml->interface.chatbox.dialog = dialog[0];
    sfText_setString(csfml->interface.chatbox.text, csfml->interface.chatbox.dialog[0]);
    csfml->interface.chatbox.count_dialog = 0;
    csfml->player.speed.x = 0;
}

int manage_trap(csfml_t *csfml, mobs_t *mobs, int j)
{
    if (csfml->event.state[j] == 2) {
        if (csfml->event.nb_room[j] == csfml->map.transit.room) {
            dialog_trap1(csfml);
            csfml->event.state[j] = 1;
            csfml->player.stat.access_player = 0;
        }
    }
    else if (csfml->event.state[j] == 1) {
        if (csfml->event.nb_mobs[j] == 0) {
            dialog_trap2(csfml);
            csfml->event.state[j] = 0;
            csfml->player.stat.access_player = csfml->player.stat.access_player_save;
        }
    }
    return (0);
}

int event_trap(csfml_t *csfml, mobs_t *mobs)
{
    int i;
    for (i = 0; i < 2; i++)
        manage_trap(csfml, mobs, i);
    return (0);
}
