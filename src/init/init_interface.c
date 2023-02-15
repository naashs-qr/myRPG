/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of all interfaces
*/

#include "rpg.h"

void init_all_text2(csfml_t *csfml)
{
    sfText_setFont(csfml->interface.status.beam_ice_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.beam_ice_txt, 30);
    sfText_setFont(csfml->interface.status.beam_charge_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.beam_charge_txt, 30);
    sfText_setFont(csfml->interface.status.beam_plasma_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.beam_plasma_txt, 30);
    sfText_setFont(csfml->interface.status.ball_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.ball_txt, 30);
    sfText_setFont(csfml->interface.status.bombe_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.bombe_txt, 30);
    sfText_setFont(csfml->interface.status.missile_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.missile_txt, 30);
    sfText_setFont(csfml->interface.status.double_jump_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.double_jump_txt, 30);
    sfText_setFont(csfml->interface.status.salto_electrical_txt,
    csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.salto_electrical_txt, 30);
}

void init_all_text(csfml_t *csfml)
{
    csfml->interface.status.ball_str = "Ball";
    csfml->interface.status.bombe_str = "Bombe";
    csfml->interface.status.double_jump_str = "Double jump";
    csfml->interface.status.beam_ice_str = "Ice beam";
    csfml->interface.status.beam_plasma_str = "Plasma beam";
    csfml->interface.status.beam_charge_str = "Charge beam";
    csfml->interface.status.missile_str = "Missile";
    csfml->interface.status.salto_electrical_str = "Salto electrical";
    csfml->interface.status.salto_electrical_txt = sfText_create();
    csfml->interface.status.double_jump_txt = sfText_create();
    csfml->interface.status.bombe_txt = sfText_create();
    csfml->interface.status.ball_txt = sfText_create();
    csfml->interface.status.missile_txt = sfText_create();
    csfml->interface.status.beam_ice_txt = sfText_create();
    csfml->interface.status.beam_plasma_txt = sfText_create();
    csfml->interface.status.beam_charge_txt = sfText_create();
    init_all_text2(csfml);
}

void init_all_bonus(csfml_t *csfml)
{
    create_object("assets/menu/arrow2.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.status.arrow);
    create_object("assets/menu/check2.png",
    (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.status.check);
    csfml->interface.status.type_beam = 1;
    csfml->interface.end = 0;
    csfml->interface.end2 = 0;
    csfml->interface.timer = 150;
    csfml->interface.count_time = 0;
    csfml->interface.time = sfText_create();
    sfText_setFont(csfml->interface.time, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.time, 50);
}

void init_all_button(csfml_t *csfml)
{
    init_button(&csfml->interface.play, (sfVector2f)
    {400.0, 400.0}, (sfVector2f) {200.0, 200.0});
    init_button(&csfml->interface.how_p, (sfVector2f)
    {0.0, 0.0}, (sfVector2f) {200.0, 200.0});
}

int init_interface(csfml_t *csfml)
{
    init_all_button(csfml);
    init_all_bonus(csfml);
    init_all_text(csfml);
    init_ui(csfml);
    init_chatbox(csfml);
    init_pause_menu(csfml);
    init_starting_menu(csfml);
    init_scene1(csfml);
    init_scene2(csfml);
    init_scene3(csfml);
    csfml->interface.menu = 0;
    create_object("assets/menu/menu.png", (sfVector2f) {0.0, 0.0}, 
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.starting_menu.main_menu);
    sfSprite_setScale(csfml->interface.starting_menu.main_menu.sprite, (sfVector2f) {1.2, 1.2});
    create_object("assets/menu/menu_alien.png", (sfVector2f) {830.0, 430.0}, 
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.alien);
    sfSprite_setScale(csfml->interface.alien.sprite, (sfVector2f) {0.7, 0.7});
    create_object("assets/menu/status3.png",
    (sfVector2f) {500.0, 500.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.status.status_menu);
    return 0;
}