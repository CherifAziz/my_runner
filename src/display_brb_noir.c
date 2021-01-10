/*
** EPITECH PROJECT, 2021
** display_brb_noir.c
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

void display_background(struct game *game_info, struct gui *game_menu)
{
    if (game_info->time == 1)
        set_value1(game_info);
    if (game_info->vector.x == 0) {
        game_info->vector.x = 1920;
        game_info->vector2.x = 0;
    }
    if (game_info->vector_ground.x <= -1920) {
        game_info->vector_ground.x = 1920;
        game_info->speed++;
    }
    if (game_info->vector_ground2.x <= -1920)
        game_info->vector_ground2.x = 1920;
    if (game_info->brb_vector.x <= -1920) {
        game_info->brb_vector.x = 1920;
        game_info->time_brb = 0;
        game_info->brb_dead = 0;
    }
    display_life(game_info, game_menu);
    display_brb_noir(game_info);
}

void set_value1(struct game *game_info)
{
    game_info->vector2.x = game_info->vector2.x - 5;
    game_info->vector.x = game_info->vector.x - 5;
    game_info->vector_ground2.x =
    game_info->vector_ground2.x - game_info->speed;
    game_info->vector_ground.x =
    game_info->vector_ground.x - game_info->speed;
    game_info->brb_vector.x = game_info->brb_vector.x - game_info->speed;
    sfSprite_setPosition(game_info->sprite, game_info->vector2);
    sfSprite_setPosition(game_info->sprite2, game_info->vector);
    sfSprite_setPosition(game_info->ground_game, game_info->vector_ground2);
    sfSprite_setPosition(game_info->ground_game3, game_info->vector_ground);
    sfSprite_setPosition(game_info->ground_game4, game_info->vector_ground);
    sfSprite_setPosition(game_info->brb_noir1, game_info->brb_vector);
    sfSprite_setPosition(game_info->brb_noir2, game_info->brb_vector);
    sfSprite_setPosition(game_info->brb_die, game_info->brb_vector);
    sfSprite_setPosition(game_info->brb_die2, game_info->brb_vector);
    if (game_info->speed == 32)
        game_info->speed = game_info->speed - 1;
    game_info->time = 0;
}

void display_brb_noir(struct game *game_info)
{
    sfRenderWindow_drawSprite(game_info->window, game_info->sprite, NULL);
    sfRenderWindow_drawSprite(game_info->window, game_info->sprite2, NULL);
    sfRenderWindow_drawSprite(game_info->window, game_info->ground_game, NULL);
    if (game_info->modulo % 2 == 0)
        sfRenderWindow_drawSprite(game_info->window,
        game_info->ground_game3, NULL);
    else
        sfRenderWindow_drawSprite(game_info->window,
        game_info->ground_game4, NULL);
    if (game_info->time_brb <= 8 && game_info->brb_dead == 0)
        sfRenderWindow_drawSprite(game_info->window, game_info->brb_noir1, 0);
    else if (game_info->time_brb > 8
    && game_info->time_brb <= 16 && game_info->brb_dead == 0)
        sfRenderWindow_drawSprite(game_info->window, game_info->brb_noir2, 0);
    if (game_info->time_brb == 16) {
        game_info->time_brb = 0;
    }
    sfRenderWindow_drawSprite(game_info->window, game_info->life, NULL);
    display_brb_dead(game_info);
}

void display_brb_dead(struct game *game_info)
{
    if (game_info->brb_vector.x > 280 && game_info->brb_vector.x <= 310
    && game_info->attack == 1 && game_info->brb_dead == 0) {
        game_info->brb_dead = 1;
        game_info->time_brb = 20;
    }
    else if (game_info->brb_vector.x <= 280 && game_info->brb_vector.x > 100
    && game_info->brb_dead == 0  || game_info->time2 >= 150)
        display_zoro_hit(game_info);
    if (game_info->time_brb >= 20 && game_info->time_brb < 35
    && game_info->brb_dead == 1) {
        sfRenderWindow_drawSprite(game_info->window, game_info->brb_die, NULL);
    }
    else if (game_info->time_brb >= 35
    && game_info->time_brb < 50 && game_info->brb_dead == 1)
        sfRenderWindow_drawSprite(game_info->window, game_info->brb_die2, 0);
    if (game_info->time_brb == 50) {
        game_info->brb_dead = 0;
        game_info->time_brb = 0;
    }
}