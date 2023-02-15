/*
** EPITECH PROJECT, 2021
** defender
** File description:
** object
*/

#include "rpg.h"

int get_bg_x(csfml_t *csfml)
{
    sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
    sfVector2f pos_bg1 = sfSprite_getPosition(csfml->map.bg1);
    sfVector2f pos_bg2 = sfSprite_getPosition(csfml->map.bg2);
    if (pos_bg1.x < pos_player.x && pos_bg1.x + 3840.0 > pos_player.x)
        return (1);
    if (pos_bg2.x > pos_player.x && pos_bg2.x - 3840.0 < pos_player.x)
        return (2);
    return (0);
}

int get_bg_y(csfml_t *csfml)
{
    sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
    sfVector2f pos_bg1 = sfSprite_getPosition(csfml->map.bg1);
    sfVector2f pos_bg3 = sfSprite_getPosition(csfml->map.bg3);
    sfVector2f pos_bg5 = sfSprite_getPosition(csfml->map.bg5);
    if (pos_bg1.y < pos_player.y && pos_bg1.y + 1080.0 > pos_player.y)
        return (1);
    if (pos_bg3.y < pos_player.y && pos_bg3.y + 1080.0 > pos_player.y)
        return (2);
    if (pos_bg5.y < pos_player.y && pos_bg5.y + 1080.0 > pos_player.y)
        return (3);
    return (0);
}

void manage_bg_x(csfml_t *csfml, int d)
{
    if (d == 1) {
        sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
        sfVector2f pos_bg1 = sfSprite_getPosition(csfml->map.bg1);
        if (pos_bg1.x + 1200.0 > pos_player.x && pos_bg1.x < pos_player.x)
            sfSprite_setPosition(csfml->map.bg2, pos_bg1);
        if (pos_bg1.x + 2600.0 < pos_player.x && pos_bg1.x +
        3840.0 > pos_player.x) {
            pos_bg1.x += 7640.0;
            sfSprite_setPosition(csfml->map.bg2, pos_bg1); }
    }
    if (d == 2) {
        sfVector2f pos_player = sfSprite_getPosition(csfml->player.obj.sprite);
        sfVector2f pos_bg2 = sfSprite_getPosition(csfml->map.bg2);
        if (pos_bg2.x - 1200.0 < pos_player.x && pos_bg2.x > pos_player.x)
            sfSprite_setPosition(csfml->map.bg1, pos_bg2);
        if (pos_bg2.x - 2600.0 > pos_player.x && pos_bg2.x - 3840.0 <
        pos_player.x) {
            pos_bg2.x -= 7640.0;
            sfSprite_setPosition(csfml->map.bg1, pos_bg2); }
    }
}

void manage_bg_y(csfml_t *csfml, int d)
{
    sfVector2f pos_bg1 = sfSprite_getPosition(csfml->map.bg1);
    sfVector2f pos_bg3 = sfSprite_getPosition(csfml->map.bg3);
    sfVector2f pos_bg5 = sfSprite_getPosition(csfml->map.bg5);
    if (d == 1) {
        pos_bg1.y -= 1080;
        sfSprite_setPosition(csfml->map.bg3, pos_bg1);
        sfSprite_setPosition(csfml->map.bg4, pos_bg1);
        pos_bg1.y += 2160;
        sfSprite_setPosition(csfml->map.bg5, pos_bg1);
        sfSprite_setPosition(csfml->map.bg6, pos_bg1);
    }
    if (d == 2) {
        pos_bg3.y -= 1080;
        sfSprite_setPosition(csfml->map.bg1, pos_bg3);
        sfSprite_setPosition(csfml->map.bg2, pos_bg3);
        pos_bg3.y += 2160;
        sfSprite_setPosition(csfml->map.bg5, pos_bg3);
        sfSprite_setPosition(csfml->map.bg6, pos_bg3);
    }
    if (d == 3) {
        pos_bg5.y -= 1080;
        sfSprite_setPosition(csfml->map.bg1, pos_bg5);
        sfSprite_setPosition(csfml->map.bg2, pos_bg5);
        pos_bg5.y += 2160;
        sfSprite_setPosition(csfml->map.bg3, pos_bg5);
        sfSprite_setPosition(csfml->map.bg4, pos_bg5);
    }
}

void manage_background(csfml_t *csfml)
{
    int d = get_bg_x(csfml);
    int e = get_bg_y(csfml);
    manage_bg_x(csfml, d);
    manage_bg_x_up(csfml, d);
    manage_bg_x_down(csfml, d);
    manage_bg_y(csfml, e);
}