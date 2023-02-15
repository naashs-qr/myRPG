/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef LIB_H_
#define LIB_H_

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);

#endif /* !LIB_H_ */