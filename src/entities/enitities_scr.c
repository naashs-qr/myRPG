/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

int init_scr_ent(csfml_t *csfml)
{
    for (int i = 0; i < 35; i++)
        csfml->room[i].ent = -1;
    csfml->room[0].ent = 0;
    csfml->room[15].ent = 2;
    csfml->room[9].ent = 1;
    csfml->room[26].ent = 4;
    csfml->room[32].ent = 9;
    csfml->room[24].ent = 6;
    csfml->room[25].ent = 11;
    csfml->room[28].ent = 15;
    csfml->room[23].ent = 5;
    csfml->room[14].ent = 3;
    csfml->room[22].ent = 12;
    csfml->room[21].ent = 8;
    csfml->room[29].ent = 7;
    csfml->room[7].ent = 4;
    return (0);
}