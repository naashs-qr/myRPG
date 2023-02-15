/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of player
*/

#include "rpg.h"

char *read_map(int fd, int size)
{
    char *res = malloc (sizeof(char) * size + 1);

    if (!res) return (NULL);
    if (read(fd, res, size) == -1) return (NULL);
    res[size] = '\0';
    return (res);
}

int read_room(room_t *lvl, char *filepath)
{
    struct stat file_stat;
    int fd;
    int size;

    if ((fd = stat(filepath, &file_stat)) == -1) return (84);
    size = file_stat.st_size;
    if ((fd = open(filepath, O_RDONLY)) == -1) return (84);
    lvl->map = read_map(fd, size);
    close(fd);
    if (!lvl->map) return (84);
    return (0);
}

int init_rooms2(csfml_t *csfml)
{
    if (read_room(&csfml->room[17], "assets/rooms/room20.txt") == 84) return 84;
    if (read_room(&csfml->room[18], "assets/rooms/room21.txt") == 84) return 84;
    if (read_room(&csfml->room[19], "assets/rooms/room22.txt") == 84) return 84;
    if (read_room(&csfml->room[20], "assets/rooms/room23.txt") == 84) return 84;
    if (read_room(&csfml->room[21], "assets/rooms/room24.txt") == 84) return 84;
    if (read_room(&csfml->room[22], "assets/rooms/room25.txt") == 84) return 84;
    if (read_room(&csfml->room[23], "assets/rooms/charge.txt") == 84) return 84;
    if (read_room(&csfml->room[24], "assets/rooms/missil.txt") == 84) return 84;
    if (read_room(&csfml->room[25], "assets/rooms/??.txt") == 84) return 84;
    if (read_room(&csfml->room[26], "assets/rooms/roomsave2.txt") == 84) return 84;
    if (read_room(&csfml->room[27], "assets/rooms/preboss1.txt") == 84) return 84;
    if (read_room(&csfml->room[28], "assets/rooms/boss1.txt") == 84) return 84;
    if (read_room(&csfml->room[29], "assets/rooms/boss2.txt") == 84) return 84;
    if (read_room(&csfml->room[30], "assets/rooms/roomA1.txt") == 84) return 84;
    if (read_room(&csfml->room[31], "assets/rooms/final.txt") == 84) return 84;
    if (read_room(&csfml->room[32], "assets/rooms/roompnj.txt") == 84) return 84;
    if (read_room(&csfml->room[33], "assets/rooms/roomh6.txt") == 84) return 84;
    if (read_room(&csfml->room[34], "assets/rooms/roomh7.txt") == 84) return 84;
    return (0);
}

int init_rooms(csfml_t *csfml)
{
    if (read_room(&csfml->room[0], "assets/rooms/room1.txt") == 84) return 84;
    if (read_room(&csfml->room[1], "assets/rooms/room2.txt") == 84) return 84;
    if (read_room(&csfml->room[2], "assets/rooms/room3.txt") == 84) return 84;
    if (read_room(&csfml->room[3], "assets/rooms/room4.txt") == 84) return 84;
    if (read_room(&csfml->room[4], "assets/rooms/room5.txt") == 84) return 84;
    if (read_room(&csfml->room[5], "assets/rooms/room6.txt") == 84) return 84;
    if (read_room(&csfml->room[6], "assets/rooms/room7.txt") == 84) return 84;
    if (read_room(&csfml->room[7], "assets/rooms/room8.txt") == 84) return 84;
    if (read_room(&csfml->room[8], "assets/rooms/room9.txt") == 84) return 84;
    if (read_room(&csfml->room[9], "assets/rooms/room10.txt") == 84) return 84;
    if (read_room(&csfml->room[10], "assets/rooms/room11.txt") == 84) return 84;
    if (read_room(&csfml->room[11], "assets/rooms/room12.txt") == 84) return 84;
    if (read_room(&csfml->room[12], "assets/rooms/room13.txt") == 84) return 84;
    if (read_room(&csfml->room[13], "assets/rooms/room14.txt") == 84) return 84;
    if (read_room(&csfml->room[14], "assets/rooms/room16.txt") == 84) return 84;
    if (read_room(&csfml->room[15], "assets/rooms/room17.txt") == 84) return 84;
    if (read_room(&csfml->room[16], "assets/rooms/room19.txt") == 84) return 84;
    init_rooms2(csfml);
    return (0);
}