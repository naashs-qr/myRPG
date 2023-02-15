/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init lvl
*/

#include "rpg.h"

int add_stats_mobs2(stats_t *stat, char *line, short i, char **res)
{
    stat->type = res[0][5] - 48;
    stat->grav = my_getnbr(&res[1][5]);
    stat->life = my_getnbr(&res[2][5]);
    stat->damg = my_getnbr(&res[3][5]);
    stat->defs = my_getnbr(&res[4][5]);
    stat->sped = my_getnbr(&res[5][5]);
    stat->anim[0] = my_getnbr(&res[12][5]);
    stat->anim[1] = my_getnbr(&res[13][5]);
    stat->anim[2] = my_getnbr(&res[14][5]);
    stat->vani = my_getnbr(&res[15][5]);
    stat->scale = my_getnbr(&res[16][5]);
    stat->anim[3] = my_getnbr(&res[17][5]);
    return (0);
}

int add_stats_mobs(stats_t *stat, char *line, short i)
{
    char **res = my_str_to_word_array(line, " ");
    int posy = my_getnbr(&res[6][5]) * BLOCY;
    int posx = my_getnbr(&res[7][5]) * BLOCX;
    int recx = my_getnbr(&res[8][5]);
    int recy = my_getnbr(&res[9][5]);
    int hitx = my_getnbr(&res[10][5]);
    int hity = my_getnbr(&res[11][5]);

    free (line);
    if(!res) return(84);
    add_stats_mobs2(stat, line, i, res);
    stat->rect = (sfIntRect){0, 0, recx, recy};
    stat->hitbox = (sfFloatRect){posx, posy, hitx, hity};
    for (int k = 0; res[k]; k++)
        free (res[k]);
    if (res) free(res);
    return (0);
}

int read_mobs2(room_t *room, char *path, char **res)
{
    int i = 0;
    for (; res[i]; i++)
        if (add_stats_mobs(&room->scr_mob[i], res[i], i) == 84) return (84);
    for (; i < 6; i++) 
        room->scr_mob[i].type = RIEN;
    return (0);
}

int read_mobs(room_t *room, char *path)
{
    struct stat info;
    char *line;
    char **res;
    int fd = 0, size = 0;
    if (stat(path, &info) == -1) return 84;
    if (S_ISDIR(info.st_mode) == 1) return 84;
    size = info.st_size;
    if (size == 0) return 84;
    if ((fd = open(path, O_RDONLY & O_ASYNC)) < 0) return 84;
    line = malloc (sizeof(char) * (size + 1));
    if(!line) return (84);
    if (read(fd, line, size) == -1) return (84);
    line[size] = '\0';
    res = my_str_to_word_array(line, "\n");
    if (line) free(line);
    if (!res) return (84);
    read_mobs2(room, path, res);
    if (close(fd) < 0) return 84;
    return 0;
}

int init_script(csfml_t *csfml)
{
    if (init_rooms(csfml) == 84) return (84);
    if (init_travel(csfml) == 84) return (84);
    if (init_mobs(csfml) == 84) return (84);
    if (init_scr_ent(csfml) == 84) return (84);
    return (0);
}