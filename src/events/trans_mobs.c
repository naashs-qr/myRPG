/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** create lvl
*/

#include "rpg.h"

void assign_fct(mobs_t *mob, mob_type_e type, sfTexture *text_mob)
{
    void (*atk[6])(sfTexture *, player_t *, mobs_t *) = {fct_charge_atk, fct_charge_atk, fct_trap_atk, fct_krab_atk, fct_insect_atk, fct_zombie_atk};
    void (*mvt[6])(sfTexture *, player_t *, mobs_t *) = {fct_move_charge, fct_charge_atk, fct_trap_atk, fct_krab_mvt, fct_insect_mvt, fct_zombie_mvt};
    void (*dead[6])(sfTexture *, player_t *, mobs_t *) = {fct_dead_base, fct_dead_base, fct_dead_base, fct_dead_base, fct_dead_base, fct_zombie_dead};
    void (*idle[6])(sfTexture *, player_t *, mobs_t *) = {fct_idle_base, fct_idle_base, fct_idle_base, fct_idle_base, fct_idle_base, fct_zombie_idle};
    mob->atk = atk[type];
    mob->mvt = mvt[type];
    mob->dead = dead[type];
    mob->idle = idle[type];
}

void init_mob2(mobs_t *mob, mob_type_e type, sfTexture *text_mob, stats_t *stat)
{
    mob->stats.type = stat->type;
    mob->stats.grav = stat->grav;
    mob->stats.life = stat->life;
    mob->stats.damg = stat->damg;
    mob->stats.defs = stat->defs;
    mob->stats.sped = stat->sped;
    mob->stats.anim[0] = stat->anim[0];
    mob->stats.anim[1] = stat->anim[1];
    mob->stats.anim[2] = stat->anim[2];
    mob->stats.anim[3] = stat->anim[3];
    mob->stats.vani = stat->vani;
    mob->stats.rect = stat->rect;
    mob->stats.hitbox = stat->hitbox;
    mob->stats.scale = stat->scale;
}

void init_mob(mobs_t *mob, mob_type_e type, sfTexture *text_mob, stats_t *stat)
{
    init_mob2(mob, type, text_mob, stat);
    mob->state = 1;
    mob->act = IDLE;
    sfSprite_setTexture(mob->sprite, text_mob, sfFalse);
    sfSprite_setTextureRect(mob->sprite, mob->stats.rect);
    sfSprite_setPosition(
        mob->sprite, (sfVector2f) {stat->hitbox.left, stat->hitbox.top});
    sfClock_restart(mob->clock);
    assign_fct(mob, type, text_mob);
    mob->count_animate_mob = 0;
}

void transform_mobs(tilemap_t *map, room_t *script)
{
    mobs_t *tmp = map->mobs;

    for (short i = 0; i < 6 && script->scr_mob[i].type != RIEN; i++, tmp = tmp->next) {
        for (short j = 0; j < 20; j++)
            tmp->bullet[j].on = 0;
        if (script->scr_mob[i].type == CHARGE)
            init_mob(tmp, CHARGE, map->text_mob[CHARGE], &script->scr_mob[i]);
        if (script->scr_mob[i].type == TRAP)
            init_mob(tmp, TRAP, map->text_mob[TRAP], &script->scr_mob[i]);
        if (script->scr_mob[i].type == JUMP)
            init_mob(tmp, JUMP, map->text_mob[JUMP], &script->scr_mob[i]);
        if (script->scr_mob[i].type == KRAB)
            init_mob(tmp, KRAB, map->text_mob[KRAB], &script->scr_mob[i]);
        if (script->scr_mob[i].type == INSECT)
            init_mob(tmp, INSECT, map->text_mob[INSECT], &script->scr_mob[i]);
        if (script->scr_mob[i].type == ZOMBIE)
            init_mob(tmp, ZOMBIE, map->text_mob[ZOMBIE], &script->scr_mob[i]);
    }
    for (; tmp != NULL; tmp = tmp->next)
        tmp->stats.type = RIEN;
}