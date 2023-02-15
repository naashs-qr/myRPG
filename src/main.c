/*
** EPITECH PROJECT, 2021
** defender
** File description:
** main
*/

#include "rpg.h"

int free_all(csfml_t *csfml)
{
    sfMusic_destroy(csfml->music.menu);
    sfMusic_destroy(csfml->music.boss);
    sfMusic_destroy(csfml->music.game);
    sfSound_destroy(csfml->music.beam);
    sfSound_destroy(csfml->music.bombe);
    sfSound_destroy(csfml->music.explosion);
    sfSound_destroy(csfml->music.footstep);
    sfSound_destroy(csfml->music.pnj);
    sfSound_destroy(csfml->music.charge);
    sfSoundBuffer_destroy(csfml->music.beam_buffer);
    sfSoundBuffer_destroy(csfml->music.pnj_buffer);
    sfSoundBuffer_destroy(csfml->music.charge_buffer);
    sfSoundBuffer_destroy(csfml->music.footstep_buffer);
    sfSoundBuffer_destroy(csfml->music.explosion_buffer);
    sfSoundBuffer_destroy(csfml->music.bombe_buffer);
    return (0);
}

int manage_element(csfml_t *csfml)
{
    manage_background(csfml);
    gravity_strenght(csfml);
    travel_t *tmp = NULL;
    event_trap(csfml, csfml->map.mobs);
    manage_shoot(csfml);
    if (csfml->interface.end == 1)
        timer(csfml);
    if (csfml->var.hang_state != 1)
        manage_player(csfml);
    if (csfml->var.hang_state == 1)
        hang_mode(csfml);
    if (csfml->var.cooldown_menu > 0)
        csfml->var.cooldown_menu -= 1;
    if (csfml->map.mobs) manage_mobs(csfml);
    if (csfml->map.mobs) mobs_get_hit(csfml, csfml->map.mobs, &csfml->player);
    if (csfml->map.boss) manage_boss(csfml, csfml->map.boss);
    player_get_hit(csfml, csfml->map.mobs, &csfml->player);
    manage_ui(csfml);
    manage_travel(csfml, &csfml->player, csfml->map.travel);
    if (csfml->map.entities)
        manage_entities(csfml, &csfml->map);
    if (csfml->player.hurt.color.a > 0) {
        csfml->player.hurt.color.a += -1.5;
        sfSprite_setColor(csfml->player.hurt.sprite, csfml->player.hurt.color);
        sfSprite_setPosition(csfml->player.hurt.sprite, (sfVector2f)
            {csfml->var.view_rect.left, csfml->var.view_rect.top});
    }
    if (sfKeyboard_isKeyPressed(sfKeyK)) {
        csfml->player.hurt.color.a = 150;
        sfSprite_setColor(csfml->player.hurt.sprite, csfml->player.hurt.color);
        sfSprite_setPosition(csfml->player.hurt.sprite, (sfVector2f)
            {csfml->var.view_rect.left, csfml->var.view_rect.top});
        csfml->player.tp = 0;
    }
    if (!tmp) return (0);
    tp(csfml, tmp);
    return (0);
}

void manage_menu(csfml_t *csfml)
{
    if (csfml->interface.menu == 3 && csfml->var.cooldown_menu == 0)
        status_menu(csfml);
    if (csfml->interface.menu == 4 && csfml->var.cooldown_menu == 0)
        pause_menu(csfml);
    if (csfml->interface.menu == 5)
        chatbox(csfml, &csfml->interface.chatbox);
}

void game(csfml_t *csfml)
{
    if (csfml->var.tp == 1) {
        transit(csfml, &csfml->map.transit);
    } else {
        if (csfml->interface.menu != 0)
            manage_menu(csfml);
        else {
            /*my_putstr("room: ");
            my_put_nbr(csfml->map.transit.room);
            my_putchar('\n');*/
            event(csfml);
            manage_element(csfml);
            display_element(csfml);
            sfRenderWindow_display(csfml->var.window);
        }
        if (csfml->var.cooldown_menu > 0)
            csfml->var.cooldown_menu -= 1;
        if (csfml->interface.end2 == 1) {
            if (csfml->player.stat.state_entities[1] == 1 && 
            csfml->player.stat.state_entities[10] == 1)
                csfml->var.scene = 4;
            else
                csfml->var.scene = 3;
        }
            
    }
    sfClock_restart(csfml->var.clock);
}

int rpg(csfml_t *csfml)
{
    while (csfml->var.wind == 0) {
        csfml->var.time = sfClock_getElapsedTime(csfml->var.clock);
        csfml->var.seconds = csfml->var.time.microseconds / 1000000.0;
        if (csfml->var.seconds > 0.005) {
            if (csfml->var.scene == 0)
                starting_menu(csfml);
            if (csfml->var.scene == 1)
                show_cinematik1(csfml);
            if (csfml->var.scene == 2)
                game(csfml);
            if (csfml->var.scene == 5)
                death(csfml);
             if (csfml->var.scene == 3)
                show_cinematik2(csfml);
            if (csfml->var.scene == 4)
                show_cinematik3(csfml);
        }
    }
    return (0);
}

int main(void)
{
    csfml_t csfml;

    if (init_all(&csfml) == 84) return (84);
    rpg(&csfml);
    free_all(&csfml);
    return (0);
}