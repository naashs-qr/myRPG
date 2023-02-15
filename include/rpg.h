/*
** EPITECH PROJECT, 2021
** rpg.h
** File description:
** defender header
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_

#include "struct_rpg.h"

/* SRC/DISPLAY/all.c */
int display_element(csfml_t *csfml);
void display_mobs(variable_t *var, mobs_t *mobs);
void display_map(variable_t *var, tilemap_t *map);
void display_status_menu(csfml_t *csfml);
void display_pause_menu(csfml_t *csfml);
void event_pause_menu(csfml_t *csfml);
void display_mobs(variable_t *var, mobs_t *mobs);
void display_doors2(variable_t *var, tilemap_t *map,
sfIntRect rect, sfVector2f pos);
void display_doors(variable_t *var, tilemap_t *map);
void set_pos_hang(csfml_t *csfml, sfVector2f scale);
sfVector2f get_block_x(csfml_t *csfml, sfFloatRect box);
void display_map_fg(variable_t *var, tilemap_t *map);
void energy(csfml_t *csfml);
int pos_wall2(csfml_t *csfml, sfFloatRect box, float y);


/* SRC/EVENT/all.c */

int event_trap(csfml_t *csfml, mobs_t *mobs);
int event_mouse_click(sfMouseButtonEvent event, csfml_t *csfml);
int analyse_events(csfml_t *csfml);
void event(csfml_t *csfml);
void assign_fct(mobs_t *mob, mob_type_e type, sfTexture *text_mob);
void init_mob(mobs_t *mob, mob_type_e type, sfTexture *text_mob, stats_t *stat);
void event_status_menu(csfml_t *csfml);
void transform_mobs(tilemap_t *map, room_t *script);
void change_blocs(tilemap_t *map, room_t *script);
void tp(csfml_t *csfml, travel_t *entry);
void change_way(travel_t *travel, tile_t *tile, char *way);
void tilecraft(tile_t *tile, char c, int x, int y);
void transit(csfml_t *csfml, transit_t *transit);
void manage_travel(csfml_t *csfml, player_t *player, travel_t *travel);
void set_background(csfml_t *csfml);
void set_background(csfml_t *csfml);
sfFloatRect pos_wall(csfml_t *csfml, sfFloatRect box);
void get_special_tiles2(tilemap_t *map, room_t *script,
tile_t *tile, travel_t *tmp);
void get_special_tiles(tilemap_t *map, room_t *script);
void change_blocs2(tilemap_t *map, room_t *script);
void event_mouse_click_menu(sfMouseButtonEvent event, csfml_t *csfml);
void event_input_menu_starting2_bis1(csfml_t *csfml);
void event_input_menu_starting2_bis2(csfml_t *csfml);
void event_input_menu_starting2_bis(csfml_t *csfml);
void event_input_menu_starting2(csfml_t *csfml);
void event_input_menu_starting_bis(csfml_t *csfml);
void event_input_menu_starting(csfml_t *csfml);
void event_input_menu_starting3_bis(csfml_t *csfml);
void event_input_menu_starting3(csfml_t *csfml);
void event_starting_menu(csfml_t *csfml);
int event_how_menu(csfml_t *csfml);
void display_starting_menu(csfml_t *csfml);
void how_to_play(csfml_t *csfml);
void timer(csfml_t *csfml);
int load_save_cheat(csfml_t *csfml);

/* SRC/INIT/all.c */
void init_event(csfml_t *csfml);
int init_button(button_t *button, sfVector2f position, sfVector2f size);
int init_interface(csfml_t *csfml);
char *read_map(int fd, int size);
void init_ui2(csfml_t *csfml);
void init_ui(csfml_t *csfml);
int init_rooms(csfml_t *csfml);
int init_mobs(csfml_t *csfml);
void init_stat_player(csfml_t *csfml);
void init_starting_menu(csfml_t *csfml);
int init_chatbox(csfml_t *csfml);
int init_scene1(csfml_t *csfml);
int init_scene2(csfml_t *csfml);
int init_scene3(csfml_t *csfml);
void init_pause_menu(csfml_t *csfml);
int init_var(variable_t *var);
int init_player(csfml_t *csfml);
int init_all(csfml_t *csfml);
void init_vector(vector_t *vector);
int init_map(tilemap_t *map);
int init_script(csfml_t *csfml);
tile_t *init_tile(sfTexture *texture);
void init_this_room(tilemap_t *map, room_t *script, csfml_t *csfml);
sfVector2f init_vector_for_mobs(vector_t *vector, short pos_mobs);
void init_starting_menu(csfml_t *csfml);
int init_rooms(csfml_t *csfml);
int init_music(csfml_t *csfml);
int init_mobs(csfml_t *csfml);
int read_mobs(room_t *room, char *path);
int add_stats_mobs(stats_t *stat, char *line, short i);
mobs_t *init_list_mobs(void);
void add_mob(mobs_t *mobs);
mobs_t *create_mob(void);
int init_travel(csfml_t *csfml);
travel_t *init_way(int nb);
int init_var_shoot(variable_t *var);
int init_bomb(bomb_t *bomb, sfTexture *texture);
int init_bullet(bullet_t *bullet);
char ***get_dialog(char *path);

/* SRC/COLLISION/all.c */
void check_collision_player(csfml_t *csfml);
void collision_player(csfml_t *csfml);
void gravity_strenght(csfml_t *csfml);
int check_collision(csfml_t *csfml, sfVector2f move, sfFloatRect temp);
int verif_block_collision(csfml_t *csfml, sfFloatRect box);
void check_collision_mob(csfml_t *csfml, mobs_t *mob);
int verif_break_collision(
    csfml_t *csfml, sfFloatRect box, short dig, player_t *player);
void take_spike_dmg(csfml_t *csfml, player_t *player, sfFloatRect spike);
void manage_bg_x_up(csfml_t *csfml, int d);
void manage_bg_x_down(csfml_t *csfml, int d);

/* SRC/PLAYER/all.c */
void manage_player(csfml_t *csfml);
void manage_jump(csfml_t *csfml);
void ball(csfml_t *csfml);
void manage_shoot(csfml_t *csfml);
void manage_animation_right_ball(csfml_t *csfml);
void manage_movement_player(csfml_t *csfml, int direction);
void manage_animation_left_ball(csfml_t *csfml);
void hang(csfml_t *csfml);
float distance_vector(sfVector2f off, sfVector2f off2);
int pos_wall2(csfml_t *csfml, sfFloatRect box, float y);
void hang_mode(csfml_t *csfml);
void get_direction_shoot(csfml_t *csfml, float x, bullet_t *shoot);
void repulse_bombe2(csfml_t *csfml, bomb_t *bombe, sfVector2f pos);
void shoot2(csfml_t *csfml);
void set_shoot(csfml_t *csfml, float x, bullet_t *shoot);
void bombe(csfml_t *csfml);
void manage_bombe(csfml_t *csfml);
void jump(csfml_t *csfml);
void manage_speed_x(csfml_t *csfml);
void manage_charge_anim(csfml_t *csfml);
void quick_switch(csfml_t *csfml, int nb);
void manage_stat_player(csfml_t *csfml);
void manage_ui(csfml_t *csfml);
void player_get_hit(csfml_t *csfml, mobs_t *mob, player_t *player);
void manage_missile(csfml_t *csfml);


/* SRC/MOBS/all.c */
void manage_mobs(csfml_t *csfml);
void animate_mob(csfml_t *csfml, mobs_t *mob);
void act_mob(csfml_t *csfml, mobs_t *mob);
void fct_rien(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_move_charge(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_mob_jump(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_krab_atk(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_trap_atk(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_krab_mvt(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_insect_mvt(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_charge_atk(sfTexture *text_mob, player_t *player, mobs_t *mob);
void fct_insect_atk(sfTexture *texture, player_t *player, mobs_t *mob);
void fct_zombie_atk(sfTexture *texture, player_t *player, mobs_t *mob);
void fct_zombie_mvt(sfTexture *texture, player_t *player, mobs_t *mob);
void fct_zombie_dead(sfTexture *texture, player_t *player, mobs_t *mob);
void fct_zombie_idle(sfTexture *texture, player_t *player, mobs_t *mob);
void mobs_get_hit(csfml_t *csfml, mobs_t *mob, player_t *player);
void fct_dead_base(sfTexture *texture, player_t *player, mobs_t *mob);
void fct_idle_base(sfTexture *texture, player_t *player, mobs_t *mob);
void scale_mob(csfml_t *csfml, mobs_t *mob);
void manage_bullet(csfml_t *csfml, mobs_t *mob);

/* SRC/UTILS/all.c */
int get_next_line(int fd, char **line);
char **my_str_to_word_array(char *str, char *spaces);
void itoa2(int n, char s[]);

/* SRX/INTERFACE/all.c */
void starting_menu(csfml_t *csfml);
void status_menu(csfml_t *csfml);
void show_cinematik1(csfml_t *csfml);
void pause_menu(csfml_t *csfml);
void set_txt(csfml_t *csfml, sfVector2f vect);
void set_txt2(csfml_t *csfml, sfVector2f vect);
void chatbox(csfml_t *csfml, chatbox_t *chatbox);
void set_chatbox(entity_t *entity, chatbox_t *chatbox, int nb);
void death(csfml_t *csfml);
void show_cinematik2(csfml_t *csfml);
void show_cinematik3(csfml_t *csfml);
char *get_hp_number(csfml_t *csfml, int nb1, int nb2);

/*   SRC/BOSS/all.c   */
void animate_boss1(boss_t *boss);
int init_boss1(csfml_t *csfml, boss_t *boss);
int init_bosses(csfml_t *csfml, tilemap_t *map);
void manage_boss(csfml_t *csfml, boss_t *boss);

/* SRC/SAVE/all.c */
int save(stat_player_t stat);
void reset_save(csfml_t *csfml);
int load_save(csfml_t *csfml);

/* SRC/OBJECT/all.c */
sfIntRect create_rect(float x, float y, float a, float b);
sfVector2f create_vector(float x, float y);
int create_object(
    char *path, sfVector2f off, sfIntRect rect, object_t *obj);
object_t *moove_rect(object_t *object, int widht);
void manage_background(csfml_t *csfml);

/* SRC/ENTITIES.c */
int init_all_entities(csfml_t *csfml, tilemap_t *map);
int init_scr_ent(csfml_t *csfml);
int init_gor_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bird_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
void manage_entities(csfml_t *csfml, tilemap_t *map);
int init_adm_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_access0_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bonus0_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bonus1_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_save_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_gor2_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bird2_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_access1_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bonus2_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bonus3_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bonus4_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bonus5_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_bonus6_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);
int init_adm2_ent(csfml_t *csfml, entity_t *entity, sfTexture *texture);

/* all.c */
void player_get_hit(csfml_t *csfml, mobs_t *mob, player_t *player);
int rpg(csfml_t *csfml);
int main(void);

#endif /* !DEFENDER_H_ */