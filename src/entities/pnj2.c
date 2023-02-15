/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void interact_gor2(player_t *player, entity_t *entity, interface_t *ui)
{
    if (entity->state != -1) {
        ui->menu = 5;
        set_chatbox(entity, &ui->chatbox, 0);
        player->speed.x = 0;
        if (entity->state == 0 && !player->stat.bonus_state[6]) {
            player->stat.bonus_state[6] = 1;
            player->stat.bonus_state[5] = 1;
        }
    }
}

int init_gor2_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 62, 57};
    entity->pos = (sfVector2f) {10 * BLOCX, 8.5 * BLOCY};
    entity->offset = (sfVector2f) {-1 * BLOCX, - BLOCY};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 3 * BLOCX , 2 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {2, 2});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/pnj12.txt");
    if (!entity->dialog) return (84);
    entity->delay = 5;
    entity->anim[0] = 4;
    entity->anim[1] = 5;
    entity->anim[2] = 0;
    entity->state = -1;
    entity->max = 2;
    entity->loop = -1;
    entity->interact = interact_gor2;
    entity->anim_count = 0;
    entity->frame_count = 0;
    entity->minx = 0;
    entity->index = 9;
    entity->maxx = 100000;
    entity->move = (sfVector2f) {0, 0};
    entity->next = &csfml->map.all_entities[10];
    return (0);
}

void interact_bird2(player_t *player, entity_t *entity, interface_t *ui)
{
    ui->menu = 5;
    set_chatbox(entity, &ui->chatbox, 0);
    player->speed.x = 0;
    if (entity->state != -1 && !player->stat.bonus_state[2])
        player->stat.bonus_state[2] = 1;
}

int init_bird2_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 85, 102};
    entity->pos = (sfVector2f) {18 * BLOCX, 8 * BLOCY};
    entity->offset = (sfVector2f) {-1 * BLOCX, 0};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 3 * BLOCX , 2 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {2, 2});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/pnj22.txt");
    if (!entity->dialog) return (84);
    entity->delay = 5;
    entity->anim[0] = 10;
    entity->anim[1] = 7;
    entity->anim[2] = 0;
    entity->state = -1;
    entity->max = 2;
    entity->loop = -1;
    entity->interact = interact_bird2;
    entity->anim_count = 0;
    entity->frame_count = 0;
    entity->minx = 0;
    entity->index = 10;
    entity->maxx = 10000;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}