/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of player
*/

#include "rpg.h"

int init_hurt(hitmark_t *hit)
{
    hit->text = sfTexture_createFromFile("assets/player/hitmark.png", NULL);
    if (!hit->text) return (84);
    hit->sprite = sfSprite_create();
    if (!hit->sprite) return (84);
    sfSprite_setTexture(hit->sprite, hit->text, sfFalse);
    sfSprite_setScale(hit->sprite, (sfVector2f) {10, 10});
    hit->color = (sfColor) {255, 255, 255, 0};
    return (0);
}

int init_player3(csfml_t *csfml)
{
    sfText_setCharacterSize(csfml->player.interact, 30);
    sfText_setString(csfml->player.interact, "Press E to interact");
    create_object("assets/player/salto3.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 100.0, 105.0}, &csfml->player.salto);
    create_object("assets/player/charge_effects.png", (sfVector2f) {0.0, 0.0},
    (sfIntRect) {0.0, 0.0, 33.0, 39.0}, &csfml->player.charge_anim);
    sfSprite_setScale(csfml->player.charge_anim.sprite, (sfVector2f) {4, 4});
    sfSprite_setTextureRect(csfml->player.salto.sprite, csfml->player.salto.rect);
    sfSprite_setTextureRect(csfml->player.charge_anim.sprite, csfml->player.charge_anim.rect);
    sfSprite_setScale(csfml->player.salto.sprite, (sfVector2f) {2, 2});
    return (0);
}

int init_player2(csfml_t *csfml)
{
    if (init_hurt(&csfml->player.hurt) == 84) return (84);
    for (int i = 0; i < 10; i++)
        if (init_bullet(&csfml->player.bullet[i]) == 84) return (84);
    csfml->player.select_shot = 0;
    for (int i = 0; i < 3; i++)
        if (init_bomb(&csfml->player.bomb[i], csfml->player.bomb_text) == 84)
            return (84);
    csfml->player.tp = 1;
    csfml->player.airborne = 0;
    csfml->player.speed = (sfVector2f) {0, 0};
    csfml->player.speed_env = (sfVector2f) {0, 0};
    csfml->player.count_display_xp = 0;
    csfml->player.state_interact = 0;
    csfml->player.xp_won = sfText_create();
    sfText_setFont(csfml->player.xp_won, csfml->var.font2);
    sfText_setCharacterSize(csfml->player.xp_won, 30);
    csfml->player.interact = sfText_create();
    sfText_setFont(csfml->player.interact, csfml->var.font2);
    init_player3(csfml);
    return (0);
}

int init_player(csfml_t *csfml)
{
    init_stat_player(csfml);
    if (create_object("assets/player/metroid_player2.png",
    csfml->vector.pos_player, csfml->vector.rect_player,
    &csfml->player.obj) == 84)
        return (84);
    csfml->player.bomb_text = sfTexture_createFromFile(
        "assets/player/bombe.png", NULL);
    if (!csfml->player.bomb_text) return (84);
    csfml->player.box = (sfFloatRect) {csfml->vector.pos_player.x - 50, csfml->vector.pos_player.y, 100, 200};
    sfSprite_setOrigin(csfml->player.obj.sprite, (sfVector2f) {100.0, 0.0});
    //csfml->player.box = (sfFloatRect) {csfml->vector.pos_player.x - 100, csfml->vector.pos_player.y, 100, 200};
    init_player2(csfml);
    return (0);
}