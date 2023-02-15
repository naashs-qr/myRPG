/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of all interfaces
*/

#include "rpg.h"

void init_starting_menu5(csfml_t *csfml)
{
    create_object("assets/menu/check2.png",
    (sfVector2f) {1100.0, 400.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.starting_menu.check1);
    create_object("assets/menu/check2.png",
    (sfVector2f) {1100.0, 300.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.starting_menu.check2);
    create_object("assets/menu/check2.png",
    (sfVector2f) {1100.0, 500.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.starting_menu.check3);
    create_object("assets/menu/how_to_play.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.starting_menu.how_to_play);
    sfSprite_setScale(csfml->interface.starting_menu.how_to_play.sprite, (sfVector2f) {1, 0.85});
}

void init_starting_menu4(csfml_t *csfml)
{
    sfText_setPosition(csfml->interface.starting_menu.retour2, (sfVector2f) {700.0, 600.0});
    csfml->interface.starting_menu.state_eric = 0;
    csfml->interface.starting_menu.state_music = 1;
    csfml->interface.starting_menu.state_sound = 1;
    csfml->interface.starting_menu.quit = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.quit, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.quit, 50);
    sfText_setString(csfml->interface.starting_menu.quit, "QUIT");
    sfText_setPosition(csfml->interface.starting_menu.quit, (sfVector2f) {700.0, 600.0});
    create_object("assets/sky2.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.starting_menu.bg);
    create_object("assets/menu/arrow2.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.starting_menu.arrow);
    init_starting_menu5(csfml);
}

void init_starting_menu3(csfml_t *csfml)
{
    csfml->interface.starting_menu.sound = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.sound, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.sound, 50);
    sfText_setString(csfml->interface.starting_menu.sound, "SOUND");
    sfText_setPosition(csfml->interface.starting_menu.sound, (sfVector2f) {700.0, 500.0});
    csfml->interface.starting_menu.how_play = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.how_play, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.how_play, 50);
    sfText_setString(csfml->interface.starting_menu.how_play, "HOW TO PLAY");
    sfText_setPosition(csfml->interface.starting_menu.how_play, (sfVector2f) {700.0, 500.0});
    csfml->interface.starting_menu.retour = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.retour, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.retour, 50);
    sfText_setString(csfml->interface.starting_menu.retour, "RETOUR");
    sfText_setPosition(csfml->interface.starting_menu.retour, (sfVector2f) {700.0, 500.0});
    csfml->interface.starting_menu.retour2 = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.retour2, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.retour2, 50);
    sfText_setString(csfml->interface.starting_menu.retour2, "RETOUR");
    init_starting_menu4(csfml);
}

void init_starting_menu2(csfml_t *csfml)
{
    sfText_setFont(csfml->interface.starting_menu.previous_save, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.previous_save, 50);
    sfText_setString(csfml->interface.starting_menu.previous_save, "PREVIOUS SAVE");
    sfText_setPosition(csfml->interface.starting_menu.previous_save, (sfVector2f) {700.0, 300.0});
    csfml->interface.starting_menu.new_game = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.new_game, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.new_game, 50);
    sfText_setString(csfml->interface.starting_menu.new_game, "NEW GAME");
    sfText_setPosition(csfml->interface.starting_menu.new_game, (sfVector2f) {700.0, 400.0});
    csfml->interface.starting_menu.eric = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.eric, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.eric, 50);
    sfText_setString(csfml->interface.starting_menu.eric, "ERIC MODE");
    sfText_setPosition(csfml->interface.starting_menu.eric, (sfVector2f) {700.0, 400.0});
    csfml->interface.starting_menu.music = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.music, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.music, 50);
    sfText_setString(csfml->interface.starting_menu.music, "MUSIC");
    sfText_setPosition(csfml->interface.starting_menu.music, (sfVector2f) {700.0, 300.0});
    init_starting_menu3(csfml);
}

void init_starting_menu(csfml_t *csfml)
{
    csfml->interface.starting_menu.pos = 0;
    csfml->interface.starting_menu.save_input = 0;
    csfml->interface.starting_menu.anim_alien = 0;
    csfml->interface.starting_menu.state_alien = 0;
    csfml->interface.starting_menu.cooldown = 0;
    csfml->interface.starting_menu.start_game = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.start_game, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.start_game, 50);
    sfText_setString(csfml->interface.starting_menu.start_game, "START GAME");
    sfText_setPosition(csfml->interface.starting_menu.start_game, (sfVector2f) {700.0, 300.0});
    csfml->interface.starting_menu.option = sfText_create();
    sfText_setFont(csfml->interface.starting_menu.option, csfml->var.font2);
    sfText_setCharacterSize(csfml->interface.starting_menu.option, 50);
    sfText_setString(csfml->interface.starting_menu.option, "OPTION");
    sfText_setPosition(csfml->interface.starting_menu.option, (sfVector2f) {700.0, 400.0});
    csfml->interface.starting_menu.previous_save = sfText_create();
    init_starting_menu2(csfml);
}