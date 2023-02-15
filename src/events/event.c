/*
** EPITECH PROJECT, 2020
** event_utils.c
** File description:
** all utils events
*/

#include "rpg.h"

int analyse_events(csfml_t *csfml)
{
    csfml->var.input_jump = 0;
    if (sfKeyboard_isKeyPressed(sfKeyTab) && csfml->var.cooldown_menu == 0)
        csfml->interface.menu = 3;
    else if (sfKeyboard_isKeyPressed(sfKeyEscape) && csfml->var.cooldown_menu == 0)
        csfml->interface.menu = 4;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        csfml->var.input_jump = 1;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        return (2);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        return (1);
    if (sfKeyboard_isKeyPressed(sfKeyC))
        return (4);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        return (5);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        return (6);
    return (0);
}

int analyse_events_shoot(csfml_t *csfml)
{
    csfml->var.save_shoot = csfml->var.count_charge;
    if (sfKeyboard_isKeyPressed(sfKeyG) || sfKeyboard_isKeyPressed(sfKeyRControl)) {
        if (csfml->var.count_charge < 50)
            csfml->var.count_charge += 1;
    }
    else csfml->var.count_charge = 0;
    if (csfml->var.count_charge == 0 && csfml->var.save_shoot != 0)
        csfml->var.input_shoot = 1;
    else csfml->var.input_shoot = 0;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        quick_switch(csfml, 1);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        quick_switch(csfml, 2);
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        return (3);
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        return (2);
    return (0);
}

bool can_viewmove(sfFloatRect rect, tile_t *stop)
{
    for (tile_t *tmp = stop; tmp; tmp = tmp->n_stop)
        if (sfFloatRect_intersects(&rect, &tmp->hitbox, NULL))
            return (0);
    return (1);
}

void update_view(csfml_t *csfml)
{
    sfVector2f play = sfSprite_getPosition(csfml->player.obj.sprite);
    sfVector2f view = sfView_getCenter(csfml->var.view);
    sfVector2f offset = {play.x - view.x, play.y - view.y};
    sfFloatRect rect_x = {csfml->var.view_rect.left + offset.x,
        csfml->var.view_rect.top, 1920, 1080};
    sfFloatRect rect_y = {csfml->var.view_rect.left,
        csfml->var.view_rect.top + offset.y, 1920, 1080};

    if (((int) offset.x) == 0 && ((int) offset.y) == 0) return;
    if (can_viewmove(rect_x, csfml->map.stop)) {
        sfView_move(csfml->var.view, (sfVector2f) {offset.x, 0});
        csfml->var.view_rect.left += offset.x;
    }
    if (can_viewmove(rect_y, csfml->map.stop)) {
        sfView_move(csfml->var.view, (sfVector2f) {0, offset.y});
        csfml->var.view_rect.top += offset.y;
    }
}

void event(csfml_t *csfml)
{
    sfEvent ev;
    csfml->var.input_aim = analyse_events_shoot(csfml);
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        csfml->var.input = analyse_events(csfml);
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
        }
    }
    update_view(csfml);
}