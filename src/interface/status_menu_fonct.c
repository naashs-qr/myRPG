/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** interface
*/

#include "rpg.h"

void set_txt_bonus4(csfml_t *csfml, sfVector2f vect)
{
    if (csfml->player.stat.bonus_state[5] == 0)
        sfText_setString(csfml->interface.status.double_jump_txt, "???");
    else {
        sfText_setString(csfml->interface.status.double_jump_txt,
        csfml->interface.status.double_jump_str); }
    sfText_setPosition(csfml->interface.status.double_jump_txt, vect);
    vect.y += 65.0;
    if (csfml->player.stat.bonus_state[6] == 0)
        sfText_setString(csfml->interface.status.salto_electrical_txt, "???");
    else {
        sfText_setString(csfml->interface.status.salto_electrical_txt,
        csfml->interface.status.salto_electrical_str); }
    sfText_setPosition(csfml->interface.status.salto_electrical_txt, vect);
    vect.y += 60.0;
    if (csfml->player.stat.bonus_state[7] == 0)
        sfText_setString(csfml->interface.status.ball_txt, "???");
    else {
        sfText_setString(csfml->interface.status.ball_txt,
        csfml->interface.status.ball_str); }
    sfText_setPosition(csfml->interface.status.ball_txt, vect);
}

void set_txt_bonus3(csfml_t *csfml, sfVector2f vect)
{
    if (csfml->player.stat.bonus_state[3] == 0)
        sfText_setString(csfml->interface.status.missile_txt, "???");
    else {
        sfText_setString(csfml->interface.status.missile_txt,
        csfml->interface.status.missile_str);
    }
    sfText_setPosition(csfml->interface.status.missile_txt, vect);
    vect.y += 130.0;
    if (csfml->player.stat.bonus_state[4] == 0)
        sfText_setString(csfml->interface.status.bombe_txt, "???");
    else {
        sfText_setString(csfml->interface.status.bombe_txt,
        csfml->interface.status.bombe_str);
    }
    sfText_setPosition(csfml->interface.status.bombe_txt, vect);
    vect.y += 125.0;
    set_txt_bonus4(csfml, vect);
}

void set_txt_bonus2(csfml_t *csfml, sfVector2f vect)
{
    if (csfml->player.stat.bonus_state[1] == 0)
        sfText_setString(csfml->interface.status.beam_plasma_txt, "???");
    else {
        sfText_setString(csfml->interface.status.beam_plasma_txt,
        csfml->interface.status.beam_plasma_str);
    }
    sfText_setPosition(csfml->interface.status.beam_plasma_txt, vect);
    vect.y += 65.0;
    if (csfml->player.stat.bonus_state[2] == 0)
        sfText_setString(csfml->interface.status.beam_ice_txt, "???");
    else {
        sfText_setString(csfml->interface.status.beam_ice_txt,
        csfml->interface.status.beam_ice_str);
    }
    sfText_setPosition(csfml->interface.status.beam_ice_txt, vect);
    vect.y += 125.0;
    set_txt_bonus3(csfml, vect);
}

void set_txt(csfml_t *csfml, sfVector2f vect)
{
    vect.x += 130.0;
    vect.y += 150.0;
    if (csfml->player.stat.bonus_state[0] == 0)
        sfText_setString(csfml->interface.status.beam_charge_txt, "???");
    else {
        sfText_setString(csfml->interface.status.beam_charge_txt,
        csfml->interface.status.beam_charge_str);
    }
    sfText_setPosition(csfml->interface.status.beam_charge_txt, vect);
    vect.x -= 60.0;
    sfSprite_setPosition(csfml->interface.status.arrow.sprite, vect);
    csfml->interface.status.pos = 0;
    csfml->interface.status.pos2 = 1;
    vect.x += 60.0;
    vect.y += 65.0;
    set_txt_bonus2(csfml, vect);
}