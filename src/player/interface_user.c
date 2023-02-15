/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

char *get_cap_missile(csfml_t *csfml, int nb1, int nb2)
{
    char *str = malloc(20 * sizeof(char));
    char str1[100];
    itoa2(nb1, str1);
    char str2[100];
    itoa2(nb2, str2);
    if (str1[1] != '\0') {
        str[0] = str1[0];
        str[1] = str1[1];
    } else {
        str[0] = '0';
        str[1] = str1[0];
    }
    str[2] = '/';
    if (str2[1] != '\0') {
        str[3] = str2[0];
        str[4] = str2[1];
    } else {
        str[3] = '0';
        str[4] = str2[0]; }
    str[5] = '\0';
    return (str);
}

char *get_hp_number(csfml_t *csfml, int nb1, int nb2)
{
    char *str = malloc(20 * sizeof(char));
    char str1[100];
    char str2[100];
    itoa2(nb1, str1);
    itoa2(nb2, str2);
    if (str1[1] == '\0') {
        str[0] = '0';
        str[1] = '0';
        str[2] = str1[0];
    } else if (str1[2] == '\0') {
        str[0] = '0';
        str[1] = str1[0];
        str[2] = str1[1];
    } else {
        str[0] = str1[0];
        str[1] = str1[1];
        str[2] = str1[2];
    }
    str[3] = '/';
    str[4] = str2[0];
    str[5] = str2[1];
    str[6] = str2[2];
    str[7] = '\0';
    return (str);
}

void manage_shoot_ui(csfml_t *csfml)
{
    char *str;
    sfVector2f vect = sfView_getCenter(csfml->var.view);
    vect.x -= 600.0;
    vect.y -= 520.0;
    sfSprite_setPosition(csfml->interface.ui.icon_charge.sprite, vect);
    sfSprite_setPosition(csfml->interface.ui.icon_missile.sprite, vect);
    sfSprite_setPosition(csfml->interface.ui.icon_plasma.sprite, vect);
    sfSprite_setPosition(csfml->interface.ui.icon_ice.sprite, vect);
    vect.y += 70.0;
    sfText_setPosition(csfml->interface.ui.selected, vect);
    vect.y -= 70.0;
    vect.x += 120.0;
    sfSprite_setPosition(csfml->interface.ui.missile.sprite, vect);
    vect.y += 50.0;
    str = get_cap_missile(csfml, csfml->player.stat.cap_missile,
        csfml->player.stat.cap_missile_max);
    sfText_setString(csfml->interface.ui.cap_missile, str);
    sfText_setPosition(csfml->interface.ui.cap_missile, vect);
    free(str);
}

void manage_ui(csfml_t *csfml)
{
    energy(csfml);
    manage_shoot_ui(csfml);
}

void quick_switch(csfml_t *csfml, int nb)
{
    player_t *play = &csfml->player;
    int k = play->stat.bonus_state[0] + play->stat.bonus_state[1] +
        play->stat.bonus_state[2] + play->stat.bonus_state[3];
    if (csfml->var.cooldown_switch == 0 && (k != 0 && k != 1)) {
        int i = play->select_shot;
        if (nb == 1) {
            if (i == 3) i = 0;
            else i++;
            for (; play->stat.bonus_state[i] != 1 && i != 0; i++)
                if (i == 3) i = 0; }
        else {
            if (i == 0) i = 3;
            else i--;
            for (; play->stat.bonus_state[i] != 1 && i != 0; i--)
                if (i == 0) i = 3; }
        csfml->var.cooldown_switch = 80;
        play->select_shot = i;
    }
}