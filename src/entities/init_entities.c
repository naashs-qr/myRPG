/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void interact_ship(player_t *player, entity_t *entity, interface_t *interface)
{
    if (interface->end == 1)
        interface->end2 = 1;
    else {
        player->speed.x = 0;
        interface->menu = 5;
        set_chatbox(entity, &interface->chatbox, 0);
    }
}

int init_ship_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture)
{
    entity->sprite = sfSprite_create();
    if (!entity->sprite) return (84);
    sfSprite_setTexture(entity->sprite, texture, sfFalse);
    entity->rect = (sfIntRect) {0, 0, 200, 115};
    entity->pos = (sfVector2f) {22 * BLOCX, 6 * BLOCY};
    entity->offset = (sfVector2f) {2 * BLOCX, 2 * BLOCY};
    entity->hitbox = (sfFloatRect) {entity->pos.x + entity->offset.x,
        entity->pos.y + entity->offset.y, 800 - 4 * BLOCX, 460 - 2 * BLOCY};
    sfSprite_setTextureRect(entity->sprite, entity->rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {4, 4});
    sfSprite_setPosition(entity->sprite, entity->pos);
    entity->dialog = get_dialog("assets/dialog/ship.txt");
    if (!entity->dialog) return (84);
    entity->delay = 10;
    entity->anim[0] = 8;
    entity->anim[1] = 0;
    entity->anim[2] = 0;
    entity->state = 0;
    entity->max = 1;
    entity->loop = 0;
    entity->interact = interact_ship;
    entity->anim_count = 0;
    entity->minx = 0;
    entity->maxx = 10000;
    entity->index = 0;
    entity->frame_count = 0;
    entity->move = (sfVector2f) {0, 0};
    entity->next = NULL;
    return (0);
}

int init_all_entities(csfml_t *csfml, tilemap_t *map)
{
    map->text_entities[0] = sfTexture_createFromFile("assets/entities/ship.png", NULL);
    map->text_entities[1] = sfTexture_createFromFile("assets/entities/Gorilla.png", NULL);
    map->text_entities[2] = sfTexture_createFromFile("assets/entities/beurrd.png", NULL);
    map->text_entities[3] = sfTexture_createFromFile("assets/entities/terminal.png", NULL);
    map->text_entities[4] = sfTexture_createFromFile("assets/entities/save.png", NULL);
    map->text_entities[5] = sfTexture_createFromFile("assets/entities/bonus.png", NULL);
    map->text_entities[6] = sfTexture_createFromFile("assets/entities/acces.png", NULL);
    if (init_ship_ent(csfml, &map->all_entities[0], map->text_entities[0]) == 84) return (84);
    if (init_gor_ent(csfml, &map->all_entities[1], map->text_entities[1]) == 84) return (84);
    if (init_bird_ent(csfml, &map->all_entities[2], map->text_entities[2]) == 84) return (84);
    if (init_adm_ent(csfml, &map->all_entities[3], map->text_entities[3]) == 84) return (84);
    if (init_save_ent(csfml, &map->all_entities[4], map->text_entities[4]) == 84) return (84);
    if (init_bonus0_ent(csfml, &map->all_entities[5], map->text_entities[5]) == 84) return (84);
    if (init_bonus1_ent(csfml, &map->all_entities[6], map->text_entities[5]) == 84) return (84);
    if (init_access0_ent(csfml, &map->all_entities[7], map->text_entities[6]) == 84) return (84);
    if (init_access1_ent(csfml, &map->all_entities[8], map->text_entities[6]) == 84) return (84);
    if (init_gor2_ent(csfml, &map->all_entities[9], map->text_entities[1]) == 84) return (84);
    if (init_bird2_ent(csfml, &map->all_entities[10], map->text_entities[2]) == 84) return (84);
    if (init_bonus2_ent(csfml, &map->all_entities[11], map->text_entities[5]) == 84) return (84);
    if (init_adm2_ent(csfml, &map->all_entities[12], map->text_entities[3]) == 84) return (84);
    //if (init_bonus4_ent(csfml, &map->all_entities[13], map->text_entities[5]) == 84) return (84);
    //if (init_bonus5_ent(csfml, &map->all_entities[14], map->text_entities[5]) == 84) return (84);
    if (init_bonus6_ent(csfml, &map->all_entities[15], map->text_entities[5]) == 84) return (84);
    for (register short i = 0; i < 13; i++)
        csfml->player.stat.bonus_state[i] = map->all_entities[i].state;
    return (0);
}