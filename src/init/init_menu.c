/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of all interfaces
*/

#include "rpg.h"

void init_ui(csfml_t *csfml)
{
    create_object("assets/menu/hp_bar.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.ui.hp);
    create_object("assets/menu/red_bar.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 73.0, 20.0}, &csfml->interface.ui.hp_bar);
    create_object("assets/player/charge_beam.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.ui.icon_charge);
    create_object("assets/player/plasma_beam.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.ui.icon_plasma);
    create_object("assets/player/ice_beam.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.ui.icon_ice);
    create_object("assets/player/shoot2.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0, 0, 100, 70}, &csfml->interface.ui.icon_missile);
    create_object("assets/player/shoot2.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0, 0, 100, 70}, &csfml->interface.ui.missile);
    sfSprite_setScale(csfml->interface.ui.icon_charge.sprite, (sfVector2f) {0.7, 0.7});
    sfSprite_setScale(csfml->interface.ui.icon_ice.sprite, (sfVector2f) {0.7, 0.7});
    sfSprite_setScale(csfml->interface.ui.icon_missile.sprite, (sfVector2f) {0.8, 0.8});
    init_ui2(csfml);
}

int init_chatbox(csfml_t *csfml)
{
    csfml->interface.chatbox.count_dialog = 0;
    csfml->interface.chatbox.cooldown_input = 0;
    csfml->interface.chatbox.text = sfText_create();
    sfText_setCharacterSize(csfml->interface.chatbox.text, 30);
    sfText_setFont(csfml->interface.chatbox.text, csfml->var.font2);
    csfml->interface.chatbox.chat = sfSprite_create();
    csfml->interface.chatbox.pers = sfSprite_create();
    sfTexture *bulle = sfTexture_createFromFile("assets/menu/bulle.png", NULL);
    sfSprite_setTexture(csfml->interface.chatbox.chat, bulle, sfFalse);
    return (0);
}

int init_scene1(csfml_t *csfml)
{
    csfml->interface.scene.index_scene1 = 0;
    csfml->interface.scene.state_cine1 = 1;
    char ***temp = get_dialog("assets/intro.txt");
    csfml->interface.scene.dialog_scene1 = temp[0];
    create_object("assets/menu/game_over.png", (sfVector2f) {0.0, 0.0}, 
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.scene.bg_mort);
    create_object("assets/menu/bg_4.png", (sfVector2f) {0.0, 0.0}, 
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.scene.bg1);
    csfml->interface.scene.txt_scene1 = sfText_create();
    sfSprite_setScale(csfml->interface.scene.bg1.sprite, (sfVector2f) {2.2, 1.6});
    sfText_setCharacterSize(csfml->interface.scene.txt_scene1, 50);
    sfText_setPosition(csfml->interface.scene.txt_scene1, (sfVector2f) {100.0, 920.0});
    sfText_setFont(csfml->interface.scene.txt_scene1, csfml->var.font2);
    sfText_setString(csfml->interface.scene.txt_scene1, csfml->interface.scene.dialog_scene1[0]);
    sfColor color = sfColor_fromRGBA(255, 255, 255, 0);
    sfText_setColor(csfml->interface.scene.txt_scene1, color);
    return (0);
}

int init_scene2(csfml_t *csfml)
{
    csfml->interface.scene.index_scene2 = 0;
    csfml->interface.scene.state_cine2 = 1;
    char ***temp = get_dialog("assets/outro1.txt");
    csfml->interface.scene.dialog_scene2 = temp[0];
    create_object("assets/menu/bg_cine2.png", (sfVector2f) {0.0, 0.0}, 
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.scene.bg2);
    csfml->interface.scene.txt_scene2 = sfText_create();
    sfText_setCharacterSize(csfml->interface.scene.txt_scene2, 50);
    sfText_setPosition(csfml->interface.scene.txt_scene2, (sfVector2f) {100.0, 920.0});
    sfText_setFont(csfml->interface.scene.txt_scene2, csfml->var.font2);
    sfText_setString(csfml->interface.scene.txt_scene2, csfml->interface.scene.dialog_scene2[0]);
    sfColor color = sfColor_fromRGBA(255, 255, 255, 0);
    sfText_setColor(csfml->interface.scene.txt_scene2, color);
    return (0);
}

int init_scene3(csfml_t *csfml)
{
    csfml->interface.scene.index_scene3 = 0;
    csfml->interface.scene.state_cine3 = 1;
    char ***temp = get_dialog("assets/outro2.txt");
    csfml->interface.scene.dialog_scene3 = temp[0];
    create_object("assets/menu/bg_cine3.png", (sfVector2f) {0.0, 0.0}, 
    (sfIntRect) {0.0, 0.0, 0.0, 0.0}, &csfml->interface.scene.bg3);
    csfml->interface.scene.txt_scene3 = sfText_create();
    sfText_setCharacterSize(csfml->interface.scene.txt_scene3, 50);
    sfText_setPosition(csfml->interface.scene.txt_scene3, (sfVector2f) {100.0, 920.0});
    sfText_setFont(csfml->interface.scene.txt_scene3, csfml->var.font2);
    sfText_setString(csfml->interface.scene.txt_scene3, csfml->interface.scene.dialog_scene3[0]);
    sfColor color = sfColor_fromRGBA(255, 255, 255, 0);
    sfText_setColor(csfml->interface.scene.txt_scene3, color);
    return (0);
}