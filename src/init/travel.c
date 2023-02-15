/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** init tile
*/

#include "rpg.h"

travel_t *create_travel(void)
{
    travel_t *new  = malloc(sizeof(travel_t));

    if (!new) return (NULL);
    new->tile = NULL;
    new->door = -1;
    new->room = -1;
    new->next = NULL;
    return new;
}

void add_travel(travel_t *travel)
{
    travel_t *tmp = travel;
    travel_t *new = create_travel();

    if(!new) {
        travel = NULL;
        return;
    }
    for (; tmp && tmp->next; tmp = tmp->next);
    tmp->next = new;
}

travel_t *init_way(int nb)
{
    travel_t *travel = create_travel();

    for (int i = 1; i < nb && travel; i++) {
        add_travel(travel);        
    }
    if (!travel) return (NULL);
    return (travel);
}

char **read_way(char *filepath)
{
    struct stat file_stat;
    int fd;
    int size;
    char **tab;
    char *res;

    if ((fd = stat(filepath, &file_stat)) == -1) return (NULL);
    size = file_stat.st_size;
    if ((fd = open(filepath, O_RDONLY)) == -1) return (NULL);
    res = malloc (sizeof(char) * size + 1);
    if (!res) return (NULL);
    if (read(fd, res, size) == -1) return (NULL);
    res[size] = '\0';
    close(fd);
    tab = my_str_to_word_array(res, "#");
    if (!tab) return (NULL);
    return (tab);
}

int init_travel(csfml_t *csfml)
{
    char **res = read_way("assets/waypoint.txt");

    if (!res) return (84);
    for (int i = 0; i < 35 && res[i]; i++) {
        csfml->room[i].way = my_str_to_word_array(res[i], "\n");
        if (!csfml->room[i].way) return (84);
        if (res[i]) free(res[i]);
    }
    if (res) free(res);
    /*for (int i = 5; i < 43; i++)
        csfml->room[i].way = NULL;*/
    return (0);
}
