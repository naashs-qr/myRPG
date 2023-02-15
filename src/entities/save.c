/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void interact_save(player_t *player, entity_t *entity, interface_t *ui)
{
    ui->menu = 5;
    set_chatbox(entity, &ui->chatbox, 0);
    player->speed.x = 0;
    save(player->stat);
}

int init_save_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 48, 35};
    entity->pos = (sfVector2f) {10.5 * BLOCX, 10.5 * BLOCY};
    entity->offset = (sfVector2f) {0, 0};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 240, 35 * 5};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {5, 5});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/save.txt");
    if (!entity->dialog) return (84);
    entity->delay = 15;
    entity->anim[0] = 4;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 3;
    entity->loop = 0;
    entity->interact = interact_save;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}