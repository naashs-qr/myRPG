/*
** EPITECH PROJECT, 2021
** struct_rpg.h
** File description:
** structures of project my_defender
*/

#ifndef STRUCT_DEFENDER_H_
#define STRUCT_DEFENDER_H_
#define FILE_NOT_EXIST -2
#define IS_DIRECTORY -3;
#define FILE_EMPTY -4;
#define ERROR_OPEN -5;
#define ERROR_MEM -6;
#define ERROR_READ -7;
#define ERROR_CLOSE -8;
#define BLOCX 1920/14
#define BLOCY 108

#include "lib.h"

typedef enum {
    PLAYER      ,
    OBSTACLE    ,
    BACKGOUND1  ,
    BACKGOUND2  ,
    OBJ_COUNT
} type_object;

typedef enum mob_type {
    RIEN = -1,
    CHARGE = 0,
    JUMP = 1,
    TRAP = 2,
    KRAB = 3,
    INSECT = 4,
    ZOMBIE = 5,
} mob_type_e;

typedef enum mob_act {
    IDLE,
    MVT,
    ATK,
    DEAD
} mob_act_e;

enum bloc_type {
    VOID ,
    GROUND ,
    PATH ,
    ROCK,
    SPAWN,
    CASTL,
    EDGE,
    TRAVEL,
    UP_SPIKE,
    DO_SPIKE,
    GRILLE,
    BG1,
    BG_G,
    BG_Z,
    FG_Z,
    ENTITY,
    DEBR,
    VENT,
    GREEN,
    RED,
} ;

enum level_nb {
    LVL_ONE,
    LVL_TWO,
    LVL_TRE,
    LVL_FOU,
    LVL_FIV,
    LVL_SIX,
    LVL_SEV,
    LVL_EIG,
    LVL_NIN,
    LVL_TEN,
    NONE,
    EXIT
};

/* ALL STRUCT */

typedef struct stats_s
{
    mob_type_e type;
    short grav;
    short life;
    short damg;
    short defs;
    short sped;
    short vani;
    short scale;
    short anim[4];
    sfIntRect rect;
    sfFloatRect hitbox;
} stats_t;

typedef struct room_s {
    char *map;
    char **way;
    stats_t scr_mob[6];
    int ent;
} room_t;

typedef struct tile_s {
    enum bloc_type type;
    int touch;
    bool on;
    sfVector2f pos;
    sfFloatRect hitbox;
    sfSprite *sprite;
    struct tile_s *next;
    struct tile_s *n_stop;
    struct tile_s *n_door;
    struct tile_s *n_layer;
    struct tile_s *n_break;
    struct tile_s *n_spike;
} tile_t;

typedef struct travel_s {
    tile_t *tile;
    int room;
    int door;
    struct travel_s *next;
}travel_t;

typedef struct object_s
{
    type_object type;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f offset;
    sfIntRect rect;
    int path;
} object_t;

typedef struct hitmark_s {
    sfTexture *text;
    sfSprite *sprite;
    sfColor color;
} hitmark_t;

typedef struct stat_player_s
{
    int bonus_state[8];
    int lvl_player;
    int lvl_hp;
    int pt_comp;
    int lvl_cap_missile;
    int lvl_dammage_missile;
    int hp;
    int hp_max;
    int cap_missile;
    int cap_missile_max;
    int xp;
    int xp_max;
    int point_de_save;
    int boss_state;
    int access_player;
    int access_player_save;
    int state_entities[11];
} stat_player_t;

typedef struct stat_shoot_s
{
    sfTexture *texture;
    sfIntRect rect;
    sfFloatRect hitbox;
    sfVector2f speed_line;
    sfVector2f speed_diag;
    short dig;
    short dmg;
    short dmg_max;
    short anim;
    short anim2;
    bool charge;
} stat_shoot_t;

typedef struct bullet_mobs_s
{
    sfSprite *sprite;
    sfSprite *boom;
    sfIntRect rect;
    sfFloatRect hitbox;
    sfVector2f speed_diag;
    sfVector2f speed_line;
    short dirx;
    short diry;
    short anim;
    short dig;
    float grav;
    short dmg;
    short on;
} bullet_mobs_t;

typedef struct bullet_s
{
    sfSprite *sprite;
    sfSprite *boom;
    stat_shoot_t stats;
    short dirx;
    short diry;
    float charge;
    int dmg;
    short on;
} bullet_t;


typedef struct bomb_s
{
    sfSprite *sprite;
    sfIntRect rect;
    float radius;
    sfVector2f center;
    short delay;
    short count;
    int dmg;
    short on;
} bomb_t;

typedef struct player_s
{
    sfTexture *bomb_text;
    sfText *interact;
    int state_interact;
    sfText *xp_won;
    int count_display_xp;
    stat_player_t stat;
    object_t obj;
    object_t charge_anim;
    object_t salto;
    object_t bombe;
    sfFloatRect box;
    sfFloatRect box_shoot;
    sfVector2f speed;
    sfVector2f speed_env;
    int state_salto;
    int airborne;
    bullet_t bullet[10];
    bomb_t bomb[3];
    hitmark_t hurt;
    sfVector2f vect_shoot;
    object_t shoot;
    int type_shoot;
    bool tp;
    object_t charge_beam;
    object_t missile;
    object_t plasma_beam;
    object_t ice_beam;
    int select_shot;
    sfVector2f hang_move;
} player_t;


typedef struct mobs_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    bullet_mobs_t bullet[20];
    short count_animate_mob;
    short count_frame;
    short direct;
    void (*atk)(sfTexture *, player_t *, struct mobs_s *);
    void (*mvt)(sfTexture *, player_t *, struct mobs_s *);
    void (*dead)(sfTexture *, player_t *, struct mobs_s *);
    void (*idle)(sfTexture *, player_t *, struct mobs_s *);
    stats_t stats;
    sfVector2f speed;
    bool state;
    mob_act_e act;
    struct mobs_s *next;
} mobs_t;

typedef struct button_s
{
    sfRectangleShape *rect;
    object_t butt;
    int state;
} button_t;

typedef struct event_s
{
    int nb_room[2];
    int state[2];
    int nb_mobs[2];
} event_t;

typedef struct menu_status_s
{
    object_t status_menu;
    int pos;
    int pos2;
    int type_beam;
    object_t arrow;
    object_t check;
    sfText *beam_ice_txt;
    sfText *beam_plasma_txt;
    sfText *beam_charge_txt;
    sfText *bombe_txt;
    sfText *ball_txt;
    sfText *double_jump_txt;
    sfText *salto_electrical_txt;
    sfText *missile_txt;
    char *hp_str;
    char *cap_missile_str;
    char *dammage_missile_str;
    sfText *lvl_player_txt;
    sfText *lvl_hp_txt;
    sfText *lvl_cap_missile_txt;
    sfText *lvl_dammage_missile_txt;
    sfText *pt_comp_txt;
    sfText *hp_txt;
    sfText *cap_missile_txt;
    sfText *dammage_missile_txt;
    char *beam_ice_str;
    char *beam_plasma_str;
    char *beam_charge_str;
    char *bombe_str;
    char *ball_str;
    char *double_jump_str;
    char *salto_electrical_str;
    char *missile_str;
    bool on;
} menu_status_t;

typedef struct menu_pause_s
{
    object_t pause_menu;
    object_t arrow;
    int pos;
    sfText *resume;
    sfText *option;
    sfText *menu;
    int state_music;
    int state_sound;
    int state_pause;
    object_t check1;
    object_t check2;
    sfText *music;
    sfText *sound;
    sfText *retour;
    sfText *quit;
    int cooldown;
} menu_pause_t;

typedef struct chatbox_s {
    sfTexture *texture[1];
    sfSprite *chat;
    sfSprite *pers;
    sfText *text;
    char **dialog;
    int count_dialog;
    int cooldown_input;
} chatbox_t;

typedef struct starting_menu_s {
    object_t bg;
    int pos;
    int save_input;
    int cooldown;
    int anim_alien;
    int state_alien;
    object_t how_to_play;
    object_t main_menu;
    sfText *start_game;
    sfText *option;
    sfText *retour;
    sfText *retour2;
    sfText *how_play;
    sfText *music;
    sfText *eric;
    sfText *sound;
    sfText *quit;
    object_t check1;
    object_t check2;
    object_t check3;
    int state_eric;
    int state_music;
    int state_sound;
    sfText *previous_save;
    sfText *new_game;
    object_t arrow;
} starting_menu_t;

typedef struct ui_s {
    object_t hp;
    object_t hp_bar;
    object_t icon_missile;
    object_t missile;
    object_t icon_charge;
    object_t icon_plasma;
    object_t icon_ice;
    sfText *cap_missile;
    sfText *hp_number;
    sfText *selected;
} ui_t;

typedef struct scene_s {
    object_t bg1;
    int state_cine1;
    int index_scene1;
    sfText *txt_scene1;
    char **dialog_scene1;
    object_t bg2;
    int state_cine2;
    int index_scene2;
    sfText *txt_scene2;
    char **dialog_scene2;
    object_t bg3;
    int state_cine3;
    int index_scene3;
    sfText *txt_scene3;
    char **dialog_scene3;
    object_t bg_mort;
} scene_t;


typedef struct interface_s
{
    int timer;
    sfText *time;
    int count_time;
    int menu;
    button_t play;
    button_t how_p;
    button_t param;
    object_t alien;
    starting_menu_t starting_menu;
    ui_t ui;
    int end;
    int end2;
    scene_t scene;
    short scene_transfert;
    menu_status_t status;
    chatbox_t chatbox;
    menu_pause_t pause;
} interface_t;

typedef struct entity_s {
    sfSprite *sprite;
    char **text;
    sfFloatRect hitbox;
    sfVector2f pos;
    sfVector2f offset;
    sfIntRect rect;
    short anim[3];
    short index;
    void (*interact) (player_t *, struct entity_s *, interface_t *);
    short max;
    short loop;
    short state;
    short delay;
    int minx;
    int maxx;
    short anim_count;
    short frame_count;
    sfVector2f move;
    char ***dialog;
    struct entity_s *next;
} entity_t;

typedef struct door_sp_s {
    sfTexture *tex[2];
    sfSprite *door;
    sfSprite *gate;
    short anim_count;
    short frame_count;
} door_sp_t;

typedef struct transit_s {
    float movex;
    float movey;
    int room;
    short count;
    short state;
    short door;
    sfVector2f in;
    sfVector2f out;
    tile_t *door_tile;
} transit_t;

typedef struct boss_stats_s {
    int hp;
    int dmg_atk;
    int dmg_mvt;
    int dmg_shot;
    sfVector2f speed;
    sfFloatRect hitbox;

} boss_stats_t;

typedef struct boss_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    short state;
    boss_stats_t stats;
    bullet_mobs_t bullet[10];
    short anim_count;
    short frame_count;
    short state_count;
    short act;
    sfIntRect rect;
    sfVector2f scale;
    sfVector2f pos;
    sfVector2f move;
    short dir;
    bool touch;
    short anim[4];
    void (*idle) (player_t *, struct boss_s *);
    void (*mvt) (player_t *, struct boss_s *);
    void (*atk) (player_t *, struct boss_s *);
    void (*spec) (player_t *, struct boss_s *);
    void (*death) (player_t *, struct boss_s *, entity_t *, interface_t *);
    void (*animate) (struct boss_s *);
} boss_t;

typedef struct tilemap_s {
    sfTexture *tex_bloc;
    sfTexture *text_mob[6];
    sfTexture *text_entities[7];
    entity_t all_entities[13];
    boss_t all_boss[1];
    boss_t *boss;
    tile_t *tile;
    tile_t *stop;
    tile_t *spike;
    tile_t *doors;
    tile_t *breakable;
    tile_t *layer[3];
    door_sp_t door_sp;
    travel_t *travel;
    sfTexture *text_bg;
    transit_t transit;
    sfSprite *bg1;
    sfSprite *bg2;
    sfSprite *bg3;
    sfSprite *bg4;
    sfSprite *bg5;
    sfSprite *bg6;
    mobs_t *mobs;
    entity_t *entities;
    enum level_nb nb;
} tilemap_t;

typedef struct vector_s
{
    sfVector2f vect;
    sfVector2f pos_player;
    sfIntRect rect_player;
    sfVector2f pos_mobs;
    sfIntRect rect_mobs_1;
} vector_t;

typedef struct music_s
{
    sfMusic *menu;
    sfMusic *game;
    sfMusic *boss;
    sfSound *beam;
    sfSoundBuffer *beam_buffer;
    sfSound *footstep;
    sfSoundBuffer *footstep_buffer;
    sfSound *pnj;
    sfSoundBuffer *pnj_buffer;
    sfSound *bombe;
    sfSoundBuffer *bombe_buffer;
    sfSound *explosion;
    sfSoundBuffer *explosion_buffer;
    sfSound *charge;
    sfSoundBuffer *charge_buffer;
} music_t;

typedef struct variable_s
{
    sfVideoMode *video;
    sfRenderWindow *window;
    sfView *view;
    sfClock *clock;
    sfFont *font;
    sfFont *font2;
    sfTime time;
    float seconds;
    sfEvent event;
    int wind;
    int count_climb;
    int cooldown_shoot;
    int input;
    int count_cinematik1;
    int count_cinematik2;
    int count_cinematik3;
    int cooldown_switch;
    int cooldown_menu;
    int save_shoot;
    int count_charge;
    int count_recup_stat;
    int input_jump;
    int double_jump;
    int cooldown_status;
    int cooldown_ball;
    int cooldown_hang;
    int count_animate_bombe;
    int count_animate_ball;
    int state_shoot;
    int input_aim;
    int state_starting_menu;
    int input_shoot;
    int hang_state;
    int count_animate_jump;
    int count_animate_player;
    int cooldown_double_jump;
    int tp;
    short scene;
    stat_shoot_t shoot[4];
    sfFloatRect view_rect;
} variable_t;

/* MAIN STRUCT */

typedef struct csfml_s
{
    interface_t interface;
    vector_t vector;
    variable_t var;
    tilemap_t map;
    room_t room[35];
    player_t player;
    event_t event;
    music_t music;
    short scene;
} csfml_t;

#endif /* !STRUCT_DEFENDER_H_ */