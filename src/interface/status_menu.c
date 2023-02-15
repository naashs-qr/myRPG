/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void set_txt_stat2(csfml_t *csfml, sfVector2f vect)
{
    char str[100];
    vect.x -= 230.0;
    vect.y += 67.0;
    sfText_setString(csfml->interface.status.dammage_missile_txt,
    csfml->interface.status.dammage_missile_str);
    sfText_setPosition(csfml->interface.status.dammage_missile_txt, vect);
    vect.x += 230.0;
    itoa2(csfml->player.stat.lvl_dammage_missile, str);
    sfText_setString(csfml->interface.status.lvl_dammage_missile_txt, str);
    sfText_setPosition(csfml->interface.status.lvl_dammage_missile_txt, vect);
    vect.x -= 230.0;
    vect.y += 74.0;
    sfText_setString(csfml->interface.status.cap_missile_txt,
    csfml->interface.status.cap_missile_str);
    sfText_setPosition(csfml->interface.status.cap_missile_txt, vect);
    vect.x += 230.0;
    itoa2(csfml->player.stat.lvl_cap_missile, str);
    sfText_setString(csfml->interface.status.lvl_cap_missile_txt, str);
    sfText_setPosition(csfml->interface.status.lvl_cap_missile_txt, vect);
}

void set_txt2(csfml_t *csfml, sfVector2f vect)
{
    char str[100];
    vect.x += 630.0;
    vect.y += 50.0;
    itoa2(csfml->player.stat.lvl_player, str);
    sfText_setString(csfml->interface.status.lvl_player_txt, str);
    sfText_setPosition(csfml->interface.status.lvl_player_txt, vect);
    vect.x += 460.0;
    vect.y += 30.0;
    itoa2(csfml->player.stat.pt_comp, str);
    sfText_setString(csfml->interface.status.pt_comp_txt, str);
    sfText_setPosition(csfml->interface.status.pt_comp_txt, vect);
    vect.x -= 200.0;
    vect.y += 80.0;
    sfText_setString(csfml->interface.status.hp_txt,
    csfml->interface.status.hp_str);
    sfText_setPosition(csfml->interface.status.hp_txt, vect);
    vect.x += 230.0;
    itoa2(csfml->player.stat.lvl_hp, str);
    sfText_setString(csfml->interface.status.lvl_hp_txt, str);
    sfText_setPosition(csfml->interface.status.lvl_hp_txt, vect);
    set_txt_stat2(csfml, vect);
}

void move_arrow2(csfml_t *csfml, sfText **tab2)
{
    if (csfml->interface.status.pos2 == 1) {
        sfVector2f vect = sfText_getPosition(tab2[csfml->interface.status.pos]);
        vect.x -= 60.0;
        sfSprite_setPosition(csfml->interface.status.arrow.sprite, vect);
        sfVector2f vect2 = sfText_getPosition(
        tab2[csfml->interface.status.type_beam - 1]);
        vect2.x += 190.0;
        csfml->player.select_shot = csfml->interface.status.type_beam - 1;
        sfSprite_setPosition(csfml->interface.status.check.sprite, vect2); }
    else {
        sfText *tab[3] = {csfml->interface.status.hp_txt,
        csfml->interface.status.dammage_missile_txt,
        csfml->interface.status.cap_missile_txt};
        sfVector2f vect = sfText_getPosition(tab[csfml->interface.status.pos]);
        vect.x -= 60.0;
        sfSprite_setPosition(csfml->interface.status.arrow.sprite, vect);
        sfVector2f vect2 = sfText_getPosition(
        tab2[csfml->interface.status.type_beam - 1]);
        csfml->player.select_shot = csfml->interface.status.type_beam - 1;
        vect2.x += 190.0;
        sfSprite_setPosition(csfml->interface.status.check.sprite, vect2); }
}

void move_arrow(csfml_t *csfml)
{
    char str[100];
    itoa2(csfml->player.stat.lvl_hp, str);
    sfText_setString(csfml->interface.status.lvl_hp_txt, str);
    itoa2(csfml->player.stat.lvl_dammage_missile, str);
    sfText_setString(csfml->interface.status.lvl_dammage_missile_txt, str);
    itoa2(csfml->player.stat.lvl_cap_missile, str);
    sfText_setString(csfml->interface.status.lvl_cap_missile_txt, str);
    itoa2(csfml->player.stat.pt_comp, str);
    sfText_setString(csfml->interface.status.pt_comp_txt, str);
    sfText *tab2[8] = {csfml->interface.status.beam_charge_txt,
    csfml->interface.status.beam_plasma_txt,
    csfml->interface.status.beam_ice_txt,
    csfml->interface.status.missile_txt, csfml->interface.status.bombe_txt,
    csfml->interface.status.double_jump_txt,
    csfml->interface.status.salto_electrical_txt,
    csfml->interface.status.ball_txt};
    move_arrow2(csfml, tab2);
}

void status_menu(csfml_t *csfml)
{
    int nb = 0;
    sfVector2f vect = sfView_getCenter(csfml->var.view);
    csfml->var.cooldown_menu = 10;
    vect.x -= 600.0;
    vect.y -= 450.0;
    sfSprite_setPosition(csfml->interface.status.status_menu.sprite, vect);
    set_txt(csfml, vect);
    set_txt2(csfml, vect);
    while (nb == 0) {
        if (csfml->interface.menu != 3) {
            nb = 1;
            csfml->var.cooldown_menu = 50;
        }
        if (csfml->var.cooldown_menu > 0) csfml->var.cooldown_menu -= 1;
        event_status_menu(csfml);
        move_arrow(csfml);
        display_status_menu(csfml);
        sfRenderWindow_display(csfml->var.window);
    }
}