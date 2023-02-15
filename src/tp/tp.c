/*
** EPITECH PROJECT, 2020
** event_utils.c
** File description:
** all utils events
*/

#include "rpg.h"

void adjust_view(csfml_t *csfml, tile_t *stop, transit_t *transit)
{
    tile_t *tmp = stop;
    sfVector2f move = {0, 0};
    int i = 0;

    while (tmp && !sfFloatRect_intersects(
        &csfml->var.view_rect, &tmp->hitbox, NULL)) {
        i++;
        tmp = tmp->n_stop;
    }
    if (!tmp) return;
    move.y = (csfml->var.view_rect.top) - tmp->hitbox.top;
    if (move.y < -540)
        move.y = -(1080 + move.y);
    else
        move.y =  -move.y + BLOCY;
    transit->movey = move.y / 10;
}

void tp_player(csfml_t *csfml, transit_t *transit)
{
    travel_t *tmp;
    tile_t *tmp2;
    sfVector2f pos;
    sfVector2f view_move;

    init_this_room(&csfml->map, &csfml->room[transit->room], csfml);
    tmp = csfml->map.travel;
    for (int i = 0; i < transit->door && i < 5; i++, tmp = tmp->next);
    transit->out = (sfVector2f){tmp->tile->hitbox.left, tmp->tile->hitbox.top};
    view_move.x = transit->out.x - transit->in.x;
    view_move.y = transit->out.y - transit->in.y;
    if (view_move.x < 0)
        pos = (sfVector2f) {transit->out.x + 2.5 * BLOCX, transit->out.y};
    else
        pos = (sfVector2f) {transit->out.x - 1.5 *BLOCX, transit->out.y};
    sfSprite_setPosition(csfml->player.obj.sprite, pos);
    csfml->player.box.left = pos.x - 50;
    if (csfml->var.count_animate_ball)
        pos.y += 100;
    csfml->player.box.top = pos.y;
    sfView_move(csfml->var.view, view_move);
    csfml->var.view_rect.left += view_move.x;
    csfml->var.view_rect.top += view_move.y;
    csfml->map.transit.door_tile = NULL;
    for (tmp2 = csfml->map.doors; tmp2 &&
        !csfml->map.transit.door_tile; tmp2 = tmp2->n_door)
        if (sfFloatRect_intersects(&tmp2->hitbox, &csfml->player.box, NULL))
            csfml->map.transit.door_tile = tmp2;
    adjust_view(csfml, csfml->map.stop, transit);
}

void transit(csfml_t *csfml, transit_t *transit)
{
    sfVector2f pos;

    if (transit->state == 1 && transit->count < 60) {
        sfView_move(csfml->var.view, (sfVector2f) {transit->movex, 0});
        csfml->var.view_rect.left += transit->movex;
        transit->count++;
    }
    if (transit->count >= 60) {
        transit->state = 2;
        tp_player(csfml, transit);
        transit->count = 0;
    } else if (transit->state == 2 && transit->count < 10) {
        sfView_move(csfml->var.view, (sfVector2f) {0, transit->movey});
        csfml->var.view_rect.top += transit->movey;
        transit->count++;
    }
    if (transit->state == 2 && transit->count >= 10) {
        transit->state = 0;
        transit->count = 0;
        csfml->var.tp = 0;
        csfml->player.tp = 0;
        set_background(csfml);
    }
    sfRenderWindow_clear(csfml->var.window, sfBlack);
    if (transit->door_tile) {
        pos = (sfVector2f) {transit->door_tile->hitbox.left,
            transit->door_tile->hitbox.top};
        sfSprite_setPosition(csfml->map.door_sp.door, pos);
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->map.door_sp.door, NULL);
    }
    sfRenderWindow_setView(csfml->var.window, csfml->var.view);
    sfRenderWindow_display(csfml->var.window);
}