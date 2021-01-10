/*
** EPITECH PROJECT, 2021
** display_zoro.c
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

void display_zoro(struct game *game_info, struct gui *game_menu)
{
    if (game_info->time2 <= 8)
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro, NULL);
    else if (game_info->time2 > 8 && game_info->time2 <= 16)
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro2, NULL);
    if (game_info->time2 == 16) {
        game_info->modulo++;
        game_info->time2 = 0;
    }
    display_zoro_jump(game_info, game_menu);
    if (game_info->time2 >= 300)
        sfRenderWindow_drawSprite(game_info->window,
        game_info->zoro_down, NULL);
    if (game_info->time2 >= 300 && game_info->down == 1 &&
    !(sfKeyboard_isKeyPressed(sfKeyDown))) {
        game_info->time2 = 0;
        game_info->down = 0;
    }
    display_zoro_down(game_info);
}

void display_zoro_jump(struct game *game_info, struct gui *game_menu)
{
    if (game_info->time2 >= 50 && game_info->time2 < 64) {
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro3, NULL);
        if (game_menu->escape == 0) {
            game_info->vector_jump.y = game_info->vector_jump.y - 8;
            sfSprite_setPosition(game_info->zoro3, game_info->vector_jump);
        }
    }
    if (game_info->time2 >= 64 && game_info->time2 < 74) {
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro3, NULL);
        if (game_menu->escape == 0) {
            game_info->vector_jump.y = game_info->vector_jump.y + 11.2;
            sfSprite_setPosition(game_info->zoro3, game_info->vector_jump);
        }
    }
    if (game_info->time2 == 74) {
        game_info->time2 = 0;
        game_info->vector_jump.y = 800;
        game_info->jump = 0;
    }
}

void display_zoro_down(struct game *game_info)
{
    if ((game_info->vector_ground.x >= 125 && game_info->vector_ground.x <= 309
    && game_info->vector_jump.y == 800 ) || game_info->time2 >= 150)
        display_zoro_hit(game_info);
    if ((game_info->vector_ground.x >= -530 &&
    game_info->vector_ground.x <= -460 &&
    game_info->vector_jump.y == 800 ) || game_info->time2 >= 150)
        display_zoro_hit(game_info);
    if ((game_info->vector_ground.x >= -1287 &&
    game_info->vector_ground.x <= -1218 &&
    game_info->down != 1 ) || game_info->time2 >= 150)
        display_zoro_hit(game_info);
    if (game_info->brb_vector.x >= -698 &&
    game_info->brb_vector.x <= -629 && game_info->down != 1 &&
    game_info->brb_dead == 0 || game_info->time2 >= 150)
        display_zoro_hit(game_info);
}

void display_zoro_hit(struct game *game_info)
{
    if (game_info->time2 < 150) {
        game_info->life_nbr = game_info->life_nbr - 1;
        game_info->time2 = 150;
        game_info->time_brb = 0;
        game_info->vector_jump.y = 800;
    }
    if (game_info->time2 >= 150 && game_info->time2 < 155)
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro_hit, 0);
    if (game_info->time2 >= 155 && game_info->time2 < 160)
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro_hit2, 0);
    if (game_info->time2 >= 160 && game_info->time2 < 165)
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro_hit3, 0);
    if (game_info->time2 >= 165 && game_info->time2 < 170)
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro_hit4, 0);
    if (game_info->time2 >= 170 && game_info->time2 < 175)
        sfRenderWindow_drawSprite(game_info->window, game_info->zoro_hit5, 0);
    if (game_info->time2 == 175)
        reset_value(game_info);
}

void reset_value(struct game *game_info)
{
    game_info->time2 = 0;
    game_info->time_hit = 150;
    game_info->jump = 0;
    game_info->attack = 0;
}