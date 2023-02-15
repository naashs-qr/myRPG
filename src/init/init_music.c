/*
** EPITECH PROJECT, 2021
** init_interface.c
** File description:
** init of all interfaces
*/

#include "rpg.h"

int init_music2(csfml_t *csfml)
{
    csfml->music.pnj_buffer = sfSoundBuffer_createFromFile("assets/music/Harambe.ogg");
    sfSound_setBuffer(csfml->music.pnj, csfml->music.pnj_buffer);
    csfml->music.footstep = sfSound_create();
    csfml->music.footstep_buffer = sfSoundBuffer_createFromFile("assets/music/Samus_Footstep.ogg");
    sfSound_setBuffer(csfml->music.footstep, csfml->music.footstep_buffer);
    csfml->music.charge = sfSound_create();
    csfml->music.charge_buffer = sfSoundBuffer_createFromFile("assets/music/Basic_Charge_Start.ogg");
    sfSound_setBuffer(csfml->music.charge, csfml->music.charge_buffer);
    csfml->music.explosion = sfSound_create();
    csfml->music.explosion_buffer = sfSoundBuffer_createFromFile("assets/music/Missile_Explosion.ogg");
    sfSound_setBuffer(csfml->music.explosion, csfml->music.explosion_buffer);
    return (0);
}

int init_music(csfml_t *csfml)
{
    csfml->music.menu = sfMusic_createFromFile("assets/music/menu.ogg");
    sfMusic_play(csfml->music.menu);
    sfMusic_setLoop(csfml->music.menu, sfTrue);
    csfml->music.boss = sfMusic_createFromFile("assets/music/boss_music.ogg");
    csfml->music.game = sfMusic_createFromFile("assets/music/IG3.ogg");
    csfml->music.beam = sfSound_create();
    csfml->music.beam_buffer = sfSoundBuffer_createFromFile("assets/music/beam.ogg");
    sfSound_setBuffer(csfml->music.beam, csfml->music.beam_buffer);
    csfml->music.bombe = sfSound_create();
    csfml->music.bombe_buffer = sfSoundBuffer_createFromFile("assets/music/Bomb.ogg");
    sfSound_setBuffer(csfml->music.bombe, csfml->music.bombe_buffer);
    csfml->music.pnj = sfSound_create();
    init_music2(csfml);
    return (0);
}