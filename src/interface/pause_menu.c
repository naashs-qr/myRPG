/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void move_arrow_pause(csfml_t *csfml)
{
    sfText *tab2[4] = {csfml->interface.pause.resume,
    csfml->interface.pause.option, csfml->interface.pause.menu,
    csfml->interface.pause.quit};
    sfText *tab3[3] = {csfml->interface.pause.music,
    csfml->interface.pause.sound, csfml->interface.pause.retour};
    for (int i = 0; i < 4; i++)
        sfText_setScale(tab2[i], (sfVector2f) {1.0, 1.0});
    for (int i = 0; i < 3; i++)
        sfText_setScale(tab3[i], (sfVector2f) {1.0, 1.0});
    if (csfml->interface.pause.state_pause == 0) {
        sfVector2f vect = sfText_getPosition(tab2[csfml->interface.pause.pos]);
        vect.x -= 60.0;
        sfSprite_setPosition(csfml->interface.pause.arrow.sprite, vect);
        sfText_setScale(tab2[csfml->interface.pause.pos],
        (sfVector2f) {1.2, 1.2}); }
    else {
        sfVector2f vect = sfText_getPosition(tab3[csfml->interface.pause.pos]);
        vect.x -= 60.0;
        sfSprite_setPosition(csfml->interface.pause.arrow.sprite, vect);
        sfText_setScale(tab3[csfml->interface.pause.pos],
        (sfVector2f) {1.2, 1.2}); }
}

void set_txt_pause(csfml_t *csfml, sfVector2f vect)
{
    vect.x += 130.0;
    vect.y += 150.0;
    sfText_setPosition(csfml->interface.pause.resume, vect);
    vect.x -= 60.0;
    sfSprite_setPosition(csfml->interface.pause.arrow.sprite, vect);
    csfml->interface.status.pos = 0;
    vect.x += 60.0;
    vect.y += 150.0;
    sfText_setPosition(csfml->interface.pause.option, vect);
    vect.y += 150.0;
    sfText_setPosition(csfml->interface.pause.menu, vect);
    vect.y += 150.0;
    sfText_setPosition(csfml->interface.pause.quit, vect);
}

void set_txt_pause2(csfml_t *csfml, sfVector2f vect)
{
    vect.x += 130.0;
    vect.y += 150.0;
    sfText_setPosition(csfml->interface.pause.music, vect);
    vect.x -= 60.0;
    sfSprite_setPosition(csfml->interface.pause.arrow.sprite, vect);
    csfml->interface.status.pos = 0;
    vect.x += 260.0;
    sfSprite_setPosition(csfml->interface.pause.check1.sprite, vect);
    vect.x -= 200.0;
    vect.y += 150.0;
    sfText_setPosition(csfml->interface.pause.sound, vect);
    vect.x += 200.0;
    sfSprite_setPosition(csfml->interface.pause.check2.sprite, vect);
    vect.x -= 200.0;
    vect.y += 150.0;
    sfText_setPosition(csfml->interface.pause.retour, vect);
}

void fonct_pause_menu(csfml_t *csfml)
{
    if (csfml->interface.menu != 4) {
        if (csfml->interface.pause.state_music == 0 &&
        csfml->interface.starting_menu.state_music == 1)
            sfMusic_stop(csfml->music.game);
        if (csfml->interface.pause.state_music == 1 &&
        csfml->interface.starting_menu.state_music == 0)
            sfMusic_play(csfml->music.game);
        csfml->interface.starting_menu.state_music =
        csfml->interface.pause.state_music;
        csfml->var.cooldown_menu = 50;
    }
    if (csfml->interface.pause.cooldown > 0)
        csfml->interface.pause.cooldown -= 1;
}

void pause_menu(csfml_t *csfml)
{
    sfVector2f vect = sfView_getCenter(csfml->var.view);

    vect.x -= 1000.0;
    vect.y -= 650.0;
    sfSprite_setPosition(csfml->interface.pause.pause_menu.sprite, vect);
    vect.x += 800.0;
    vect.y += 200.0;
    if (csfml->interface.pause.state_pause == 0)
        set_txt_pause(csfml, vect);
    else
        set_txt_pause2(csfml, vect);
    event_pause_menu(csfml);
    move_arrow_pause(csfml);
    display_pause_menu(csfml);
    fonct_pause_menu(csfml);
    sfRenderWindow_setView(csfml->var.window, csfml->var.view);
    sfRenderWindow_display(csfml->var.window);
}