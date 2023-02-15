/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include "lib.h"

int my_getnbr(const char *str)
{
    int i;
    int nbr;
    i = 0;
    nbr = 0;
    while ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
        i = i + 1;
    while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\n') {
        nbr = ((nbr * 10) + (str[i] - '0'));
        i = i + 1;
    }
    if (str[0] == '-')
        nbr *= -1;
    return (nbr);
}
