/*
** EPITECH PROJECT, 2020
** my_hunter.h
** File description:
** desc
*/

#include <SFML/Graphics.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct game
{
    int speed;
    int modulo;
    int down;
    int score;
    int time;
    int time2;
    int time_brb;
    int jump;
    int attack;
    int brb_dead;
    int time_hit;
    int life_nbr;
    sfFont *rubik;
    sfText *Score;
    sfFont *one_piece;
    sfText *score_nbr;
    sfSound *attack_sound;
    sfSoundBuffer *attack_buffer;
    sfSound *ost;
    sfSoundBuffer *ost_buffer;
    sfSound *jump_sound;
    sfSoundBuffer *jump_buffer;
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *background;
    sfSprite *sprite;
    sfTexture *ground2;
    sfSprite *ground_game3;
    sfTexture *ground3;
    sfSprite *ground_game4;
    sfTexture *background2;
    sfSprite *sprite2;
    sfTexture *ground;
    sfSprite *ground_game;
    sfSprite *ground_game2;
    sfTexture *zoro_run;
    sfSprite *zoro;
    sfTexture *zoro_run2;
    sfSprite *zoro2;
    sfTexture *zoro_jump;
    sfSprite *zoro3;
    sfTexture *zoro_attack;
    sfSprite *zoro_atk1;
    sfTexture *zoro_attack2;
    sfSprite *zoro_atk2;
    sfTexture *zoro_attack3;
    sfSprite *zoro_atk3;
    sfTexture *barbe_noir1;
    sfSprite *brb_noir1;
    sfTexture *barbe_noir2;
    sfSprite *brb_noir2;
    sfTexture *barbe_noir_die;
    sfSprite *brb_die;
    sfTexture *barbe_noir_die2;
    sfSprite *brb_die2;
    sfTexture *zoro_damage;
    sfSprite *zoro_hit;
    sfTexture *zoro_damage2;
    sfSprite *zoro_hit2;
    sfTexture *zoro_damage3;
    sfSprite *zoro_hit3;
    sfTexture *zoro_damage4;
    sfSprite *zoro_hit4;
    sfTexture *zoro_damage5;
    sfSprite *zoro_hit5;
    sfTexture *zoro_lower;
    sfSprite *zoro_down;
    sfTexture *zoro_damage7;
    sfSprite *zoro_hit7;
    sfTexture *zoro_damage8;
    sfSprite *zoro_hit8;
    sfTexture *zoro_damage9;
    sfSprite *zoro_hit9;
    sfTexture *zoro_life;
    sfSprite *life;
    sfIntRect rect;
    sfVector2f vector_ground;
    sfVector2f vector_ground2;
    sfVector2f vector;
    sfVector2f vector2;
    sfVector2f vector_jump;
    sfVector2f score_vector;
    sfVector2f life_vector;
    sfVector2f zoro_vector;
    sfVector2f brb_vector;
    sfVector2i mouse_pos;
    sfVector2f vector_hit;
    sfVector2f vector_hit2;
    sfVector2f vector_hit3;
    sfVector2f vector_hit4;
    sfKeyCode keybind;
};

struct gui
{
    int escape;
    int die;
    int choice;
    int choice2;
    int best_score;
    sfColor peach;
    sfText *score_best;
    sfVector2f vector_score;
    sfTexture *game_over;
    sfSprite *end;
    sfTexture *game_over1;
    sfSprite *end1;
    sfTexture *game_over2;
    sfSprite *end2;
    sfTexture *echap;
    sfSprite *menu;
    sfTexture *echap2;
    sfSprite *resume;
    sfTexture *echap3;
    sfSprite *options;
    sfTexture *echap4;
    sfSprite *exit;
};

char *conv_score(int nbr);
void print_help(void);
void animation(struct game *game_info);
void event(struct game *game_info, struct gui *game_menu);
void render(struct game *game_info, struct gui *game_menu);
void display_window(struct game *game_info, struct gui *game_menu);
void display_end(struct game *game_info, struct gui *game_menu);
void reset(struct game *game_info, struct gui *game_menu);
void init_game_struct2(struct game *game_info, struct gui *game_menu);
void init_game_struct(struct game *game_info);
void text(struct game *game_info, struct gui *game_menu);
void zoro_sprite(struct game *game_info);
void set_value(struct game *game_info);
void game(struct game *game_info, struct gui *game_menu);