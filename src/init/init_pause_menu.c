/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of all interfaces
*/

#include "rpg.h"

void init_ui2(csfml_t *csfml)
{
    sfSprite_setScale(csfml->interface.ui.icon_plasma.sprite, (sfVector2f) {0.7, 0.7});
    sfSprite_setScale(csfml->interface.ui.missile.sprite, (sfVector2f) {0.8, 0.8});
    csfml->interface.ui.cap_missile = sfText_create();
    sfText_setCharacterSize(csfml->interface.ui.cap_missile, 30);
    sfText_setFont(csfml->interface.ui.cap_missile, csfml->var.font2);
    csfml->interface.ui.hp_number = sfText_create();
    sfText_setCharacterSize(csfml->interface.ui.hp_number, 30);
    sfText_setFont(csfml->interface.ui.hp_number, csfml->var.font2);
    csfml->interface.ui.selected = sfText_create();
    sfText_setCharacterSize(csfml->interface.ui.selected, 18);
    sfText_setFont(csfml->interface.ui.selected, csfml->var.font2);
    sfText_setString(csfml->interface.ui.selected, "SELECTED");
    sfSprite_setTextureRect(csfml->interface.ui.missile.sprite, csfml->interface.ui.missile.rect);
    sfSprite_setTextureRect(csfml->interface.ui.icon_missile.sprite, csfml->interface.ui.icon_missile.rect);
    sfSprite_setTextureRect(csfml->interface.ui.hp_bar.sprite, csfml->interface.ui.hp_bar.rect);
    sfSprite_setScale(csfml->interface.ui.hp.sprite, (sfVector2f) {2.0, 2.0});
    sfSprite_setScale(csfml->interface.ui.hp_bar.sprite, (sfVector2f) {2.2, 2.0});
}

void init_pause_menu3(csfml_t *csfml)
{
    create_object("assets/menu/check2.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.pause.check2);
    create_object("assets/menu/check2.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.pause.check1);
    csfml->interface.pause.state_music = 1;
    csfml->interface.pause.state_sound = 1;
    csfml->interface.pause.state_pause = 0;
}

void init_pause_menu2(csfml_t *csfml)
{
    csfml->interface.pause.sound = sfText_create();
    sfText_setFont(csfml->interface.pause.sound, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.pause.sound, 50);
    sfText_setString(csfml->interface.pause.sound, "SOUND");
    csfml->interface.pause.retour = sfText_create();
    sfText_setFont(csfml->interface.pause.retour, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.pause.retour, 50);
    sfText_setString(csfml->interface.pause.retour, "RETOUR");
    csfml->interface.pause.quit = sfText_create();
    sfText_setFont(csfml->interface.pause.quit, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.pause.quit, 50);
    sfText_setString(csfml->interface.pause.quit, "QUIT");
    create_object("assets/menu/pause_menu3.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.pause.pause_menu);
    sfSprite_setScale(csfml->interface.pause.pause_menu.sprite, (sfVector2f) {1.2, 1.2});
    create_object("assets/menu/arrow2.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.pause.arrow);
    init_pause_menu3(csfml);
}

void init_pause_menu(csfml_t *csfml)
{
    csfml->interface.pause.cooldown = 0;
    csfml->interface.pause.resume = sfText_create();
    sfText_setFont(csfml->interface.pause.resume, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.pause.resume, 50);
    sfText_setString(csfml->interface.pause.resume, "RESUME");
    csfml->interface.pause.option = sfText_create();
    sfText_setFont(csfml->interface.pause.option, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.pause.option, 50);
    sfText_setString(csfml->interface.pause.option, "OPTION");
    csfml->interface.pause.menu = sfText_create();
    sfText_setFont(csfml->interface.pause.menu, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.pause.menu, 50);
    sfText_setString(csfml->interface.pause.menu, "MENU");
    csfml->interface.pause.music = sfText_create();
    sfText_setFont(csfml->interface.pause.music, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.pause.music, 50);
    sfText_setString(csfml->interface.pause.music, "MUSIC");
    init_pause_menu2(csfml);
}