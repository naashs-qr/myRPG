/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void interact_gor(player_t *player, entity_t *entity, interface_t *ui)
{
    ui->menu = 5;
    set_chatbox(entity, &ui->chatbox, 0);
    player->speed.x = 0;
    entity->state += 1;
    entity->rect.top = entity->rect.height;
    entity->move.x = 20;
    entity->hitbox = (sfFloatRect) {0, 0, 0, 0};
    if (entity->state >= entity->max)
        entity->state = entity->loop;
    if (player->stat.state_entities[9] < 0)
        player->stat.state_entities[9] = 0;
    player->stat.state_entities[entity->index] = entity->state;
}

int init_gor_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 62, 57};
    entity->pos = (sfVector2f) {19 * BLOCX, 7 * BLOCY};
    entity->offset = (sfVector2f) {-1 * BLOCX, - BLOCY};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 3 * BLOCX , 2 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {2, 2});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/pnj11.txt");
    if (!entity->dialog) return (84);
    entity->delay = 5;
    entity->anim[0] = 4;
    entity->anim[1] = 5;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 2;
    entity->loop = -1;
    entity->interact = interact_gor;
    entity->anim_count = 0;
    entity->frame_count = 0;
    entity->minx = 0;
    entity->index = 1;
    entity->maxx = 30 * BLOCX;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}

void interact_bird(player_t *player, entity_t *entity, interface_t *ui)
{
    ui->menu = 5;
    set_chatbox(entity, &ui->chatbox, 0);    
    player->speed.x = 0;
    entity->state += 1;
    entity->rect.top = entity->rect.height;
    sfSprite_setScale(entity->sprite, (sfVector2f) {-2.0, 2.0});
    entity->move.x = 30;
    entity->hitbox = (sfFloatRect) {0, 0, 0, 0};
    if (entity->state >= entity->max)
        entity->state = entity->loop;
    if (player->stat.state_entities[7] < 0)
        player->stat.state_entities[7] = 0;
    player->stat.state_entities[entity->index] = entity->state;
}

int init_bird_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 85, 102};
    entity->pos = (sfVector2f) {36 * BLOCX, 4 * BLOCY};
    entity->offset = (sfVector2f) {-2 * BLOCX, -BLOCY};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 5 * BLOCX , 3 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {2, 2});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/pnj21.txt");
    if (!entity->dialog) return (84);
    entity->delay = 5;
    entity->anim[0] = 10;
    entity->anim[1] = 7;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 2;
    entity->loop = -1;
    entity->interact = interact_bird;
    entity->anim_count = 0;
    entity->frame_count = 0;
    entity->minx = 0;
    entity->index = 10;
    entity->maxx = 10000;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}