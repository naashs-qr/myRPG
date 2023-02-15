/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of player
*/

#include "rpg.h"

void init_stat_player3(csfml_t *csfml)
{
    csfml->player.stat.cap_missile = 10;
    csfml->player.stat.cap_missile_max = 10;
    csfml->player.stat.lvl_cap_missile = 1;
    csfml->player.stat.lvl_dammage_missile = 1;
    csfml->interface.status.lvl_dammage_missile_txt = sfText_create();
    csfml->interface.status.lvl_cap_missile_txt = sfText_create();
    csfml->interface.status.lvl_hp_txt = sfText_create();
    csfml->interface.status.pt_comp_txt = sfText_create();
    csfml->interface.status.lvl_player_txt = sfText_create();
    csfml->interface.status.hp_txt = sfText_create();
    csfml->interface.status.cap_missile_txt = sfText_create();
    csfml->interface.status.dammage_missile_txt = sfText_create();
}

void init_stat_player2(csfml_t *csfml)
{
    sfText_setFont(csfml->interface.status.lvl_dammage_missile_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.lvl_dammage_missile_txt, 30);
    sfText_setFont(csfml->interface.status.lvl_cap_missile_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.lvl_cap_missile_txt, 30);
    sfText_setFont(csfml->interface.status.lvl_hp_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.lvl_hp_txt, 30);
    sfText_setFont(csfml->interface.status.pt_comp_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.pt_comp_txt, 30);
    sfText_setFont(csfml->interface.status.lvl_player_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.lvl_player_txt, 30);
    sfText_setFont(csfml->interface.status.hp_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.hp_txt, 30);
    sfText_setFont(csfml->interface.status.cap_missile_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.cap_missile_txt, 30);
    sfText_setFont(csfml->interface.status.dammage_missile_txt, csfml->var.font);
    sfText_setCharacterSize(csfml->interface.status.dammage_missile_txt, 30);
}

void init_base_bonus(csfml_t *csfml)
{
    csfml->player.stat.bonus_state[0] = 0;
    csfml->player.stat.bonus_state[1] = 0;
    csfml->player.stat.bonus_state[2] = 0;
    csfml->player.stat.bonus_state[3] = 0;
    csfml->player.stat.bonus_state[4] = 0;
    csfml->player.stat.bonus_state[5] = 0;
    csfml->player.stat.bonus_state[6] = 0;
    csfml->player.stat.bonus_state[7] = 0;
}

void init_stat_player(csfml_t *csfml)
{
    csfml->interface.status.cap_missile_str = "Capacite";
    csfml->interface.status.dammage_missile_str = "Dammage";
    csfml->interface.status.hp_str = "Hp";
    csfml->player.stat.lvl_player = 1;
    csfml->player.stat.lvl_hp = 1;
    csfml->player.stat.pt_comp = 0;
    csfml->player.stat.hp = 100;
    csfml->player.stat.xp = 0;
    csfml->player.stat.access_player = 1;
    csfml->player.stat.access_player_save = 1;
    csfml->player.stat.boss_state = 1;
    csfml->player.stat.xp_max = 50;
    csfml->player.stat.hp_max = 100;
    init_base_bonus(csfml);
    init_stat_player3(csfml);
    init_stat_player2(csfml);
}