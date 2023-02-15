/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** putchar
*/

#include "lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
