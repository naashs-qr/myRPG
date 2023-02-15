/*
** EPITECH PROJECT, 2021
** defender
** File description:
** object
*/

#include "rpg.h"

void manage_bg_x_up(csfml_t *csfml, int d)
{
    if (d == 1) {
        sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
        sfVector2f pos_bg3 = sfSprite_getPosition(csfml->map.bg3);
        if (pos_bg3.x + 1200.0 > pos_player.x && pos_bg3.x < pos_player.x)
            sfSprite_setPosition(csfml->map.bg4, pos_bg3);
        if (pos_bg3.x + 2600.0 < pos_player.x && pos_bg3.x +
        3840.0 > pos_player.x) {
            pos_bg3.x += 7640.0;
            sfSprite_setPosition(csfml->map.bg4, pos_bg3); }
    }
    if (d == 2) {
        sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
        sfVector2f pos_bg4 = sfSprite_getPosition(csfml->map.bg4);
        if (pos_bg4.x - 1200.0 < pos_player.x && pos_bg4.x > pos_player.x)
            sfSprite_setPosition(csfml->map.bg3, pos_bg4);
        if (pos_bg4.x - 2600.0 > pos_player.x && pos_bg4.x - 3840.0 <
        pos_player.x) {
            pos_bg4.x -= 7640.0;
            sfSprite_setPosition(csfml->map.bg3, pos_bg4); }
    }
}

void manage_bg_x_down(csfml_t *csfml, int d)
{
    if (d == 1) {
        sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
        sfVector2f pos_bg5 = sfSprite_getPosition(csfml->map.bg5);
        if (pos_bg5.x + 1200.0 > pos_player.x && pos_bg5.x < pos_player.x)
            sfSprite_setPosition(csfml->map.bg6, pos_bg5);
        if (pos_bg5.x + 2600.0 < pos_player.x && pos_bg5.x + 3840.0 >
        pos_player.x) {
            pos_bg5.x += 7640.0;
            sfSprite_setPosition(csfml->map.bg6, pos_bg5); }
    }
    if (d == 2) {
        sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
        sfVector2f pos_bg6 = sfSprite_getPosition(csfml->map.bg6);
        if (pos_bg6.x - 1200.0 < pos_player.x && pos_bg6.x > pos_player.x)
            sfSprite_setPosition(csfml->map.bg5, pos_bg6);
        if (pos_bg6.x - 2600.0 > pos_player.x && pos_bg6.x -
        3840.0 < pos_player.x) {
            pos_bg6.x -= 7640.0;
            sfSprite_setPosition(csfml->map.bg5, pos_bg6); }
    }
}