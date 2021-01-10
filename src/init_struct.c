/*
** EPITECH PROJECT, 2021
** init_struct.c
** File description:
** desc
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/Window/Event.h>
#include <SFML/System/Vector2.h>
#include <SFML/Window/Export.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../lib/my/my.h"
#include "../include/my_hunter.h"

struct game *get_info(void)
{
    struct game *game_info = malloc(sizeof(struct game));
    init_game_struct(game_info);
    game_info->vector_ground.x = 1920;
    game_info->vector_ground2.x = 0;
    game_info->vector_hit.x = 150;
    game_info->vector_hit.y = 900;
    game_info->vector_hit2.x = 150;
    game_info->vector_hit2.y = 860;
    game_info->vector_hit3.x = 150;
    game_info->vector_hit3.y = 780;
    game_info->vector_hit4.x = 150;
    game_info->vector_hit4.y = 810;
    game_info->life_vector.x = 1563;
    game_info->brb_vector.x = 3840;
    game_info->rect.height = 90;
    game_info->rect.width = 357;
    game_info->speed = 16;
    game_info->rect.left = 0;
    return (game_info);
}

void init_game_struct(struct game *game_info)
{
    game_info->time = 0;
    game_info->down = 0;
    game_info->speed = 16;
    game_info->score_vector.x = 160;
    game_info->score_vector.y = 0;
    game_info->score = 0;
    game_info->brb_dead = 0;
    game_info->time2 = 0;
    game_info->time_brb = 0;
    game_info->jump = 0;
    game_info->life_nbr = 3;
    game_info->time_hit = 150;
    game_info->attack = 0;
    game_info->vector.x = 1920;
    game_info->vector2.x = 0;
    game_info->vector_jump.x = 150;
    game_info->vector_jump.y = 800;
    game_info->zoro_vector.x = 150;
    game_info->zoro_vector.y = 800;
}

void init_game_struct2(struct game *game_info, struct gui *game_menu)
{
    game_info->vector_ground.x = 1920;
    game_info->vector_ground2.x = 0;
    game_info->vector_hit.x = 150;
    game_info->vector_hit.y = 900;
    game_info->vector_hit2.x = 150;
    game_info->vector_hit2.y = 860;
    game_info->vector_hit3.x = 150;
    game_info->vector_hit3.y = 780;
    game_info->vector_hit4.x = 150;
    game_info->vector_hit4.y = 810;
    game_info->life_vector.x = 1563;
    game_info->brb_vector.x = 3840;
    game_info->rect.height = 90;
    game_info->rect.width = 357;
    game_info->rect.left = 0;
    game_menu->escape = 0;
    game_menu->die = 0;
    game_menu->choice = 0;
    game_menu->choice2 = 0;
}

struct gui *get_menu(void)
{
    struct gui *game_menu = malloc(sizeof(struct game));
    game_menu->escape = 0;
    game_menu->die = 0;
    game_menu->choice = 0;
    game_menu->choice2 = 0;
    game_menu->vector_score.x = 900;
    game_menu->vector_score.y = 620;
    game_menu->best_score = 0;
    return (game_menu);
}