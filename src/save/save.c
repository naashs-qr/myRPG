/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** object
*/

#include "rpg.h"

void reset_save(csfml_t *csfml)
{
    csfml->player.stat.lvl_player = 1;
    csfml->player.stat.lvl_hp = 1;
    csfml->player.stat.pt_comp = 10;
    csfml->player.stat.hp = 100;
    csfml->player.stat.xp = 0;
    csfml->player.stat.xp_max = 10;
    csfml->player.stat.hp_max = 100;
    csfml->player.stat.cap_missile = 10;
    csfml->player.stat.cap_missile_max = 10;
    csfml->player.stat.lvl_cap_missile = 1;
    csfml->player.stat.lvl_dammage_missile = 1;
}

int load_save(csfml_t *csfml)
{
    stat_player_t temp;
    short fd = 0;
    char *path = "assets/save/save.txt";

    if ((fd = open(path, O_RDONLY)) < 0) return -2;

    if (read(fd, &temp, sizeof(stat_player_t)) == -1) return -1;
    if (close(fd) < 0)  return -3;
    csfml->player.stat = temp;
    return 0;
}

int load_save_cheat(csfml_t *csfml)
{
    stat_player_t temp;
    short fd = 0;
    char *path = "assets/save/save_cheat.txt";

    if ((fd = open(path, O_RDONLY)) < 0) return -2;

    if (read(fd, &temp, sizeof(stat_player_t)) == -1) return -1;
    if (close(fd) < 0)  return -3;
    csfml->player.stat = temp;
    return 0;
}

int save(stat_player_t stat)
{
    short fd = 0;
    char *path = "assets/save/save.txt";

    if ((fd = open(path, O_WRONLY | O_RDONLY | O_TRUNC)) < 0) return -1;
    if (write(fd, &stat, sizeof(stat_player_t)) == -1) return -1;
    if (close(fd) < 0)  return ERROR_CLOSE;
    return 0;
}