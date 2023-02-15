/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void show_txt(csfml_t *csfml)
{
    if (csfml->var.count_cinematik1 % 200 == 0) {
        csfml->interface.scene.index_scene1 += 1;
        if (csfml->interface.scene.dialog_scene1[csfml->interface.scene.index_scene1] == NULL)
            csfml->var.scene = 2;
        else {
            sfText_setString(csfml->interface.scene.txt_scene1,
            csfml->interface.scene.dialog_scene1[csfml->interface.scene.index_scene1]);
            sfColor color2 = sfColor_fromRGBA(255, 255, 255, 0);
            sfText_setColor(csfml->interface.scene.txt_scene1, color2);
        }
    }
    sfColor color = sfText_getColor(csfml->interface.scene.txt_scene1);
    if (color.a < 247)
        color.a += 2.0;
    sfText_setColor(csfml->interface.scene.txt_scene1, color);
}

void event_cinematik1(csfml_t *csfml)
{
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            csfml->var.scene = 2;
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
            csfml->interface.menu = 0;
        }
    }
}

void show_cinematik1(csfml_t *csfml)
{
    sfView_reset(csfml->var.view, (sfFloatRect) {0.0, 0.0, 1920.0, 1080.0});
    show_txt(csfml);
    event_cinematik1(csfml);
    if (csfml->var.scene != 1) {
        init_this_room(&csfml->map, &csfml->room[0], csfml);
        sfView_move(csfml->var.view, (sfVector2f) {BLOCX, BLOCY});
        csfml->var.view_rect.left += BLOCX;
        csfml->var.view_rect.top += BLOCY;
    }
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.scene.bg1.sprite, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.scene.txt_scene1, NULL);
    sfRenderWindow_display(csfml->var.window);
    csfml->var.count_cinematik1 += 1;
}