/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of all interfaces
*/

#include "rpg.h"

void read_nothing(room_t *room)
{
    for (register short i = 0; i < 6; i++)
        room->scr_mob[i].type = RIEN;
}

int init_mobs2(csfml_t *csfml)
{
    read_nothing(&csfml->room[18]);
    if (read_mobs(&csfml->room[19], "assets/mobs/script/room22.txt") == 84) return 84;
    if (read_mobs(&csfml->room[20], "assets/mobs/script/room23.txt") == 84) return 84;
    read_nothing(&csfml->room[21]);
    if (read_mobs(&csfml->room[22], "assets/mobs/script/room25.txt") == 84) return 84;
    read_nothing(&csfml->room[23]);
    read_nothing(&csfml->room[24]);
    read_nothing(&csfml->room[25]);
    //if (read_mobs(&csfml->room[24], "assets/mobs/script/missil.txt") == 84) return 84;
    //if (read_mobs(&csfml->room[25], "assets/mobs/script/??.txt") == 84) return 84;*/
    read_nothing(&csfml->room[26]);
    read_nothing(&csfml->room[27]);
    read_nothing(&csfml->room[28]);
    if (read_mobs(&csfml->room[29], "assets/mobs/script/roomboss2.txt") == 84) return 84;
    read_nothing(&csfml->room[30]);
    read_nothing(&csfml->room[31]);
    read_nothing(&csfml->room[32]);
    if (read_mobs(&csfml->room[33], "assets/mobs/script/roomh6.txt") == 84) return 84;
    if (read_mobs(&csfml->room[34], "assets/mobs/script/roomh7.txt") == 84) return 84;
    return (0);
}

int init_mobs(csfml_t *csfml)
{
    read_nothing(&csfml->room[0]);
    read_nothing(&csfml->room[1]);
    if (read_mobs(&csfml->room[2], "assets/mobs/script/room3.txt") == 84) return 84;
    if (read_mobs(&csfml->room[3], "assets/mobs/script/room4.txt") == 84) return 84;
    if (read_mobs(&csfml->room[4], "assets/mobs/script/room5.txt") == 84) return 84;
    read_nothing(&csfml->room[5]);
    if (read_mobs(&csfml->room[6], "assets/mobs/script/room7.txt") == 84) return 84;
    read_nothing(&csfml->room[7]);
    if (read_mobs(&csfml->room[8], "assets/mobs/script/room9.txt") == 84) return 84;
    if (read_mobs(&csfml->room[9], "assets/mobs/script/room10.txt") == 84) return 84;
    if (read_mobs(&csfml->room[10], "assets/mobs/script/room11.txt") == 84) return 84;
    if (read_mobs(&csfml->room[11], "assets/mobs/script/room12.txt") == 84) return 84;
    read_nothing(&csfml->room[12]);
    if (read_mobs(&csfml->room[13], "assets/mobs/script/room14.txt") == 84) return 84;
    read_nothing(&csfml->room[14]);
    if (read_mobs(&csfml->room[15], "assets/mobs/script/room17.txt") == 84) return 84;
    if (read_mobs(&csfml->room[16], "assets/mobs/script/room19.txt") == 84) return 84;
    if (read_mobs(&csfml->room[17], "assets/mobs/script/room20.txt") == 84) return 84;
    init_mobs2(csfml);
    return 0;
}