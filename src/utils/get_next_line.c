/*
** EPITECH PROJECT, 2020
** get_line.c
** File description:
** get next line
*/

#include "rpg.h"

static int get_that_line(char **line, char *buff, int fctr, int len)
{
    int i = -1;
    int j = -1;
    char *tmp = *line;
    if (!(*line = (char *)malloc(sizeof(**line) * (64 * fctr + 1)))) {
        free(tmp);
        return (84);
    }
    while (tmp && tmp[++i])
        (*line)[i] = tmp[i];
    i = (i < 0) ? 0 : i;
    while (++j < len)
        (*line)[i + j] = buff[j];
    (*line)[i + j] = 0;
    j = (buff[j]) ? j + 1 : j;
    i = 0;
    while (buff[j])
        buff[i++] = buff[j++];
    buff[i] = 0;
    free(tmp);
    return (1);
}

int get_next_line(int fd, char **line)
{
    static char	buff[64 + 1];
    int len;
    int fctr = 0;
    int ret = 1;
    if (!(*line = NULL) && (64 < 1 || read(fd, buff, 0)))
        return (84);
    while (ret) {
        if (!(buff[0])) {
            ret = read(fd, buff, 64);
            buff[ret] = 0;
        }
        len = 0;
        while (buff[len] && buff[len] != '\n')
            len++;
        if (buff[len] == '\n')
            return (get_that_line(line, buff, ++fctr, len));
        if (get_that_line(line, buff, ++fctr, len) == 84)
            return (84);
    }
    return (0);
}