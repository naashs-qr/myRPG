/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void interact_bonus_missile(player_t *player, entity_t *entity, interface_t *ui)
{
    if (player->stat.bonus_state[3] == 0) {
        ui->menu = 5;
        set_chatbox(entity, &ui->chatbox, 0);
        player->speed.x = 0;
        player->stat.bonus_state[3] = 1;
        player->stat.cap_missile = 10;
    }
}

int init_bonus1_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 112, 105};
    entity->pos = (sfVector2f) {10 * BLOCX, 9.5 * BLOCY};
    entity->offset = (sfVector2f) {112, BLOCY - 3};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 324, BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {4, 4});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/bonus_missile.txt");
    if (!entity->dialog) return (84);
    entity->delay = 10;
    entity->anim[0] = 3;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 3;
    entity->loop = 0;
    entity->interact = interact_bonus_missile;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->maxx = 0;
    entity->index = 6;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}

void interact_bonus_charge(player_t *player, entity_t *entity, interface_t *ui)
{
    if (player->stat.bonus_state[0] == 0) {
        ui->menu = 5;
        set_chatbox(entity, &ui->chatbox, 0);
        player->speed.x = 0;
        player->stat.bonus_state[0] = 1;
    }
}

int init_bonus0_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 112, 105};
    entity->pos = (sfVector2f) {23 * BLOCX, 9.5 * BLOCY};
    entity->offset = (sfVector2f) {112, 2 * (BLOCY - 3)};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 324, 2 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {4, 4});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/bonus_charge.txt");
    if (!entity->dialog) return (84);
    entity->delay = 15;
    entity->anim[0] = 3;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 3;
    entity->loop = 0;
    entity->interact = interact_bonus_charge;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->maxx = 0;
    entity->index = 5;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}