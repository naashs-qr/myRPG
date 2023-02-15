/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void interact_access_red(player_t *player, entity_t *entity, interface_t *ui)
{
    if (player->stat.access_player < RED) {
        ui->menu = 5;
        set_chatbox(entity, &ui->chatbox, 0);
        player->speed.x = 0;
        player->stat.access_player = RED;
        player->stat.access_player_save = RED;
    }
}

int init_access1_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 54, 74};
    entity->pos = (sfVector2f) {26 * BLOCX, 8 * BLOCY};
    entity->offset = (sfVector2f) {-3 * 54, 0};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y, 3 * 54, 3 * 74};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {-3, 3});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/access1.txt");
    if (!entity->dialog) return (84);
    entity->delay = 15;
    entity->anim[0] = 4;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 3;
    entity->loop = 0;
    entity->interact = interact_access_red;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->maxx = 0;
    entity->index = 7;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}

void interact_access_green(player_t *player, entity_t *entity, interface_t *ui)
{
    if (player->stat.access_player < GREEN) {
        ui->menu = 5;
        set_chatbox(entity, &ui->chatbox, 0);
        player->speed.x = 0;
        player->stat.access_player = GREEN;
        player->stat.access_player_save = GREEN;
    }
}

int init_access0_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 54, 74};
    entity->pos = (sfVector2f) {3 * BLOCX, 18 * BLOCY};
    entity->offset = (sfVector2f) {0, 0};
    entity->hitbox =
        (sfFloatRect) {entity->pos.x, entity->pos.y, 3 * 54, 3 * 74};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {3, 3});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/access0.txt");
    if (!entity->dialog) return (84);
    entity->delay = 15;
    entity->anim[0] = 4;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 3;
    entity->loop = 0;
    entity->interact = interact_access_green;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->maxx = 0;
    entity->index = 7;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}