/*
** EPITECH PROJECT, 2021
** defender
** File description:
** object
*/

#include "rpg.h"

object_t *moove_rect(object_t *object, int widht)
{
    object->rect.left += widht;
    sfSprite_setTextureRect(object->sprite, object->rect);
    return (object);
}

sfIntRect create_rect(float x, float y, float a, float b)
{
    sfIntRect rect = {x, y, a, b};
    return (rect);
}

sfVector2f create_vector(float x, float y)
{
    sfVector2f vect = {x, y};
    return (vect);
}

int create_object(
    char *path, sfVector2f off, sfIntRect rect, object_t *obj)
{
    obj->sprite = sfSprite_create();
    if (!obj->sprite) return (84);
    obj->texture = sfTexture_createFromFile(path, NULL);
    if (!obj->texture) return (84);
    obj->offset = off;
    obj->rect = rect;
    sfSprite_setTexture(obj->sprite, obj->texture, 0);
    sfSprite_move(obj->sprite, obj->offset);
    return (0);
}