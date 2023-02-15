/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of all interfaces
*/

#include "rpg.h"

int init_bullet_mobs(bullet_mobs_t *bullet)
{
    bullet->sprite = sfSprite_create();
    bullet->boom = sfSprite_create();
    if (!bullet->boom || !bullet->boom) return (84);
    bullet->dmg = 0;
    bullet->on = 0;
    bullet->anim = 0;
    bullet->dig = 0;
    bullet->grav = 0;
    bullet->speed_diag = (sfVector2f) {0.0, 0.0};
    bullet->speed_line = (sfVector2f) {0.0, 0.0};
    bullet->rect = (sfIntRect) {0, 0, 0, 0};
    bullet->hitbox = (sfFloatRect) {0.0, 0.0, 0.0, 0.0};
    return (0);
}

mobs_t *create_mob(void)
{
    mobs_t *mob = malloc(sizeof(mobs_t));

    if (!mob) return (NULL);
	mob->state = 1;
    mob->stats.type = RIEN;
    mob->sprite = sfSprite_create();
    if (!mob->sprite) return (NULL);
    mob->clock = sfClock_create();
    mob->speed.x = 0;
    mob->speed.y = 0;
    mob->count_frame = 0;
    mob->direct = 1;
    mob->act = IDLE;
    for (short i = 0; i < 20; i++)
        if (init_bullet_mobs(&mob->bullet[i]) == 84) return (NULL);
    mob->next = NULL;
    return (mob);
}

void add_mob(mobs_t *mobs)
{
    mobs_t *new = create_mob();
    mobs_t *tmp;

    if (!new) {
        mobs = NULL;
        return;
    }
    tmp = mobs;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new;
}

mobs_t *init_list_mobs(void)
{
    mobs_t *res = create_mob();

    for (int j = 1; j < 6 && res; j++) add_mob(res);
	if (!res) return (NULL);
    return (res);
}