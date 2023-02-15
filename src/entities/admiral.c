/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void interact_adm2(player_t *player, entity_t *entity, interface_t *ui)
{
    ui->menu = 5;
    set_chatbox(entity, &ui->chatbox, 0);
    player->speed.x = 0;
    ui->end = 1;
}

int init_adm2_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 100, 93};
    entity->pos = (sfVector2f) {7 * BLOCX, 8.8 * BLOCY};
    entity->offset = (sfVector2f) {0, BLOCY};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 300, 2 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {3, 3});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/adm2.txt");
    if (!entity->dialog) return (84);
    entity->delay = 10;
    entity->anim[0] = 4;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 3;
    entity->loop = 0;
    entity->interact = interact_adm2;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->maxx = 0;
    entity->index = 12;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}

void interact_adm(player_t *player, entity_t *entity, interface_t *ui)
{
    ui->menu = 5;
    set_chatbox(entity, &ui->chatbox, 0);
    player->speed.x = 0;
}

int init_adm_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 100, 93};
    entity->pos = (sfVector2f) {9 * BLOCX, 8.5 * BLOCY};
    entity->offset = (sfVector2f) {0, BLOCY};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 300, 2 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {3, 3});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/adm.txt");
    if (!entity->dialog) return (84);
    entity->delay = 10;
    entity->anim[0] = 4;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 3;
    entity->loop = 0;
    entity->interact = interact_adm;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->maxx = 0;
    entity->index = 3;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}