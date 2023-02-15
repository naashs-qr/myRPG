/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void show_txt3(csfml_t *csfml)
{
    if (csfml->var.count_cinematik3 % 200 == 0) {
        csfml->interface.scene.index_scene3 += 1;
        if (csfml->interface.scene.dialog_scene3[csfml->interface.scene.index_scene3] == NULL) {
            csfml->var.scene = 0;
            csfml->interface.menu = 0;
            csfml->var.state_starting_menu = 0;
        }
        else {
            sfText_setString(csfml->interface.scene.txt_scene3,
            csfml->interface.scene.dialog_scene3[csfml->interface.scene.index_scene3]);
            sfColor color2 = sfColor_fromRGBA(255, 255, 255, 0);
            sfText_setColor(csfml->interface.scene.txt_scene3, color2);
        }
    }
    sfColor color = sfText_getColor(csfml->interface.scene.txt_scene3);
    if (color.a < 247)
        color.a += 2.0;
    sfText_setColor(csfml->interface.scene.txt_scene3, color);
}

void event_cinematik3(csfml_t *csfml)
{
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
            csfml->var.scene = 0;
            csfml->interface.menu = 0;
            csfml->var.state_starting_menu = 0;
        }
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
            csfml->interface.menu = 0;
        }
    }
}

void show_cinematik3(csfml_t *csfml)
{
    sfView_reset(csfml->var.view, (sfFloatRect) {0.0, 0.0, 1920.0, 1080.0});
    csfml->var.view_rect.left = 0;
    csfml->var.view_rect.top = 0;
    sfRenderWindow_setView(csfml->var.window, csfml->var.view);
    show_txt3(csfml);
    event_cinematik3(csfml);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.scene.bg3.sprite, NULL);
    sfRenderWindow_drawText(csfml->var.window,
    csfml->interface.scene.txt_scene3, NULL);
    sfRenderWindow_display(csfml->var.window);
    csfml->var.count_cinematik3 += 1;
}