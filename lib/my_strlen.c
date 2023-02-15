/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

#include "lib.h"

int my_strlen(char const *str)
{
    int x;

    for (x = 0; str[x] != '\0'; x++);
    return (x);
}
