/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

void manage_interact(csfml_t *csfml)
{
    sfVector2f pos = sfSprite_getPosition(csfml->player.obj.sprite);
    pos.y -= 50.0;
    pos.x -= 100.0;
    sfText_setPosition(csfml->player.interact, pos);
}

void manage_display_xp(csfml_t *csfml)
{
    csfml->player.count_display_xp += 1;
    sfVector2f pos = sfSprite_getPosition(csfml->player.obj.sprite);
    pos.y -= 100.0;
    sfText_setPosition(csfml->player.xp_won, pos);
    if (csfml->player.count_display_xp == 60)
        csfml->player.count_display_xp = 0;
}

void manage_xp(csfml_t *csfml)
{
    if (csfml->player.stat.lvl_player >= 10)
        return;
    if (csfml->player.stat.xp >= csfml->player.stat.xp_max)
    {
        csfml->player.stat.xp = 0;
        csfml->player.stat.xp_max = csfml->player.stat.xp_max * 1.2;
        csfml->player.stat.lvl_player += 1;
        if (csfml->player.stat.lvl_player % 2 == 0)
            csfml->player.stat.pt_comp += 1;
    }
}

void manage_stat_player2(csfml_t *csfml, player_t *player)
{
    if (player->stat.hp <= 0) {
        if (csfml->interface.starting_menu.state_eric == 1)
            player->stat.hp = player->stat.hp_max;
        else
            csfml->var.scene = 5;
    }
    if (csfml->var.count_recup_stat == 0) {
        if (player->stat.hp_max > player->stat.hp + 10)
            player->stat.hp += 10;
        else
            player->stat.hp = player->stat.hp_max;
        if (player->stat.cap_missile_max > player->stat.cap_missile + 1)
            player->stat.cap_missile += 1;
        else
            player->stat.cap_missile = player->stat.cap_missile_max;
        csfml->var.count_recup_stat = 500;
    }
}

void manage_stat_player(csfml_t *csfml)
{
    manage_xp(csfml);
    if (csfml->player.count_display_xp > 0)
        manage_display_xp(csfml);
    manage_interact(csfml);
    if (csfml->var.count_recup_stat > 0)
        csfml->var.count_recup_stat -= 1;
    int tab[5] = {100, 150, 200, 250, 300};
    int k = csfml->player.stat.lvl_hp - 1;
    csfml->player.stat.hp_max = tab[k];
    int tab2[5] = {10, 15, 20, 25, 30};
    k = csfml->player.stat.lvl_cap_missile - 1;
    csfml->player.stat.cap_missile_max = tab2[k];
    manage_stat_player2(csfml, &csfml->player);
}