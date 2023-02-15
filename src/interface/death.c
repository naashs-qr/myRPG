/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** bombe
*/

#include "rpg.h"

void event_mouse_click_menu2(sfMouseButtonEvent event, csfml_t *csfml)
{
    csfml->var.scene = 1;
    csfml->var.scene = 0;
    csfml->interface.menu = 0;
    sfView_reset(csfml->var.view, (sfFloatRect) {0, 0, 1920, 1080});
    csfml->var.view_rect.left = 0;
    csfml->var.view_rect.top = 0;
    csfml->var.state_starting_menu = 0;
    sfRenderWindow_setView(csfml->var.window, csfml->var.view);
}

void event_death_menu(csfml_t *csfml)
{
    sfEvent ev;
    while (sfRenderWindow_pollEvent(csfml->var.window, &ev)) {
        if (ev.type == sfEvtClosed) {
            sfRenderWindow_close(csfml->var.window);
            csfml->var.wind = 1;
        }
        if (ev.type == sfEvtMouseButtonPressed)
            event_mouse_click_menu2(ev.mouseButton, csfml);
    }
}

void death(csfml_t *csfml)
{
    sfVector2f vect = sfView_getCenter(csfml->var.view);

    vect.x -= 960.0;
    vect.y -= 540.0;
    sfSprite_setPosition(csfml->interface.scene.bg_mort.sprite, vect);
    event_death_menu(csfml);
    sfRenderWindow_drawSprite(csfml->var.window,
    csfml->interface.scene.bg_mort.sprite, NULL);
    sfRenderWindow_setView(csfml->var.window, csfml->var.view);
    sfRenderWindow_display(csfml->var.window);
}