/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void how_to_play(csfml_t *csfml)
{
    int nb = 0;
    while (nb == 0)
    {
        nb = event_how_menu(csfml);
        sfRenderWindow_drawSprite(csfml->var.window,
        csfml->interface.starting_menu.how_to_play.sprite, NULL);
        sfRenderWindow_display(csfml->var.window);
    }
}

void move_arrow_starting2(
csfml_t *csfml, sfText **tab2, sfText **tab3, sfText **tab4)
{
    if (csfml->var.state_starting_menu == 1) {
        sfVector2f vect = sfText_getPosition(
        tab2[csfml->interface.starting_menu.pos]);
        sfText_setScale(tab2[csfml->interface.starting_menu.pos],
        (sfVector2f) {1.2, 1.2});
        vect.x -= 60.0;
        sfSprite_setPosition(csfml->interface.starting_menu.arrow.sprite, vect);
    }
    if (csfml->var.state_starting_menu == 2) {
        sfVector2f vect = sfText_getPosition(
        tab3[csfml->interface.starting_menu.pos]);
        vect.x -= 60.0;
        sfSprite_setPosition(
        csfml->interface.starting_menu.arrow.sprite, vect);
        sfText_setScale(
        tab3[csfml->interface.starting_menu.pos], (sfVector2f) {1.2, 1.2});
    }
    if (csfml->var.state_starting_menu == 3) {
        sfVector2f vect = sfText_getPosition(
        tab4[csfml->interface.starting_menu.pos]);
        vect.x -= 60.0;
        sfSprite_setPosition(csfml->interface.starting_menu.arrow.sprite, vect);
        sfText_setScale(
        tab4[csfml->interface.starting_menu.pos], (sfVector2f) {1.2, 1.2});
    }
}

void move_arrow_starting(csfml_t *csfml)
{
    sfText *tab2[4] = {csfml->interface.starting_menu.start_game,
    csfml->interface.starting_menu.option,
    csfml->interface.starting_menu.how_play,
    csfml->interface.starting_menu.quit};
    sfText *tab3[3] = {csfml->interface.starting_menu.previous_save,
    csfml->interface.starting_menu.new_game,
    csfml->interface.starting_menu.retour};
    sfText *tab4[4] = {csfml->interface.starting_menu.music,
    csfml->interface.starting_menu.eric,
    csfml->interface.starting_menu.sound,
    csfml->interface.starting_menu.retour2};
    for (int i = 0; i < 4; i++)
        sfText_setScale(tab2[i], (sfVector2f) {1, 1});
    for (int i = 0; i < 4; i++)
        sfText_setScale(tab4[i], (sfVector2f) {1, 1});
    for (int i = 0; i < 3; i++)
        sfText_setScale(tab3[i], (sfVector2f) {1, 1});
    move_arrow_starting2(csfml, tab2, tab3, tab4);
}

void move_alien(csfml_t *csfml)
{
    if (csfml->interface.starting_menu.anim_alien % 3 == 0) {
        if (csfml->interface.starting_menu.state_alien == 0) {
            sfVector2f pos = sfSprite_getPosition(
            csfml->interface.alien.sprite);
            if (pos.y < 440.0) {
                pos.y += 0.5;
                sfSprite_setPosition(csfml->interface.alien.sprite, pos); }
            else
                csfml->interface.starting_menu.state_alien = 1;
        }
        if (csfml->interface.starting_menu.state_alien == 1) {
            sfVector2f pos = sfSprite_getPosition(
            csfml->interface.alien.sprite);
            if (pos.y > 380.0) {
                pos.y -= 0.5;
                sfSprite_setPosition(csfml->interface.alien.sprite, pos); }
            else
                csfml->interface.starting_menu.state_alien = 0;
        }
    }
}

void starting_menu(csfml_t *csfml)
{
    if (csfml->interface.starting_menu.cooldown > 0)
        csfml->interface.starting_menu.cooldown -= 1;
    csfml->var.view_rect.left = 0;
    csfml->var.view_rect.top = 0;
    csfml->interface.starting_menu.anim_alien += 1;
    move_arrow_starting(csfml);
    if (csfml->var.state_starting_menu == 0)
        move_alien(csfml);
    sfView_reset(csfml->var.view, csfml->var.view_rect);
    event_starting_menu(csfml);
    display_starting_menu(csfml);
    sfRenderWindow_display(csfml->var.window);
}