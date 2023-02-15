/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

int len_tab(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

char ***get_dialog(char *path)
{
    char ***res;
    char **tmp;
    char *buffer;
    struct stat file_stat;
    int fd;
    int size;

    if ((fd = stat(path, &file_stat)) == -1) return (NULL);
    size = file_stat.st_size;
    if ((fd = open(path, O_RDONLY)) == -1) return (NULL);
    buffer = malloc (sizeof(char) * size + 1);
    if (!buffer) return (NULL);
    if (read(fd, buffer, size) == -1) return (NULL);
    buffer[size] = '\0';
    close(fd);
    tmp = my_str_to_word_array(buffer, "#");
    if (!tmp) return (NULL);
    if (buffer) free (buffer);
    size = len_tab(tmp);
    res = malloc(sizeof(char **) * (size + 1));
    if (!res) return (NULL);
    for (register short i = 0; i < size; i++) {
        res[i] = my_str_to_word_array(tmp[i], "&");
        if (!res[i]) return (NULL);
    }
    res[size] = NULL;
    for (register short i = 0; tmp[i]; i++)
        if (tmp[i]) free(tmp[i]);
    if (tmp) free(tmp);
    return (res);
}