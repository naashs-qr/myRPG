/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void move_entities(csfml_t *csfml, entity_t *entities)
{
    entities->pos.x += entities->move.x;
    entities->pos.y += entities->move.y;
    if (entities->pos.x > entities->maxx) {
        entities->state++;
        if (entities->state >= entities->max) {
            entities->state = entities->loop;
        }
    }
    if (entities->pos.x < entities->minx) {
        entities->state++;
        if (entities->state >= entities->max) {
            entities->state = entities->loop;
        }
    }
}

void anim_entities(csfml_t *csfml, entity_t *entities)
{
    entities->frame_count++;
    if (entities->frame_count % entities->delay == 0) {
        entities->frame_count = 0;
        entities->anim_count++;
        if (entities->anim_count >= entities->anim[entities->state]) {
            entities->anim_count = 0;
            entities->rect.left = 0;
        } else
            entities->rect.left += entities->rect.width;
        sfSprite_setTextureRect(entities->sprite, entities->rect);
    }
}

void manage_entities(csfml_t *csfml, tilemap_t *map)
{
    entity_t *tmp = map->entities;
    
    csfml->player.state_interact = 0;
    for (int i = 0; i < 13; i++)
        csfml->player.stat.state_entities[i] = map->all_entities[i].state;
    for (; tmp; tmp = tmp->next) {
        if (tmp->move.x != 0) move_entities(csfml, tmp);
        if (sfFloatRect_intersects(&tmp->hitbox,
        &csfml->player.box, NULL) == sfTrue)
            csfml->player.state_interact = 1;
        if (sfKeyboard_isKeyPressed(sfKeyE) && sfFloatRect_intersects(
            &tmp->hitbox, &csfml->player.box, NULL)) {
            tmp->interact(&csfml->player, tmp, &csfml->interface);
        }
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        anim_entities(csfml, tmp);
    }
    for (int i = 0; i < 13; i++)
        map->all_entities[i].state = csfml->player.stat.state_entities[i];
}