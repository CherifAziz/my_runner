/*
** EPITECH PROJECT, 2020
** display_window.c
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

void render(struct game *game_info, struct gui *game_menu)
{
    display_background(game_info, game_menu);
    display_zoro(game_info, game_menu);
    if (game_menu->escape != 0)
        display_menu(game_info, game_menu);
    if (game_info->time2 >= 100 && game_info->time2 <= 115) {
        if (game_info->time2 > 100 && game_info->time2 < 105)
            sfRenderWindow_drawSprite(game_info->window,
            game_info->zoro_atk1, NULL);
        if (game_info->time2 >= 105 && game_info->time2 < 110)
            sfRenderWindow_drawSprite(game_info->window,
            game_info->zoro_atk2, NULL);
        if (game_info->time2 >= 110 && game_info->time2 < 115)
            sfRenderWindow_drawSprite(game_info->window,
            game_info->zoro_atk3, NULL);
        if (game_info->time2 == 115) {
            game_info->attack = 0;
            game_info->time2 = 0;
        }
    }
}

void display_life(struct game *game_info, struct gui *game_menu)
{
    if (game_info->life_nbr == 2) {
        game_info->rect.left = -119;
        sfSprite_setTextureRect(game_info->life, game_info->rect);
    }
    if (game_info->life_nbr == 1) {
        game_info->rect.left = -238;
        sfSprite_setTextureRect(game_info->life, game_info->rect);
    }
    if (game_info->life_nbr == 0) {
        game_info->rect.left = -357;
        sfSprite_setTextureRect(game_info->life, game_info->rect);
        game_menu->die = 1;
    }
}

void display_menu(struct game *game_info, struct gui *game_menu)
{
    if (game_menu->choice == 0)
        sfRenderWindow_drawSprite(game_info->window, game_menu->menu, NULL);
    if (game_menu->choice == 1)
        sfRenderWindow_drawSprite(game_info->window, game_menu->resume, NULL);
    if (game_menu->choice == 2)
        sfRenderWindow_drawSprite(game_info->window, game_menu->options, NULL);
    if (game_menu->choice == 3)
        sfRenderWindow_drawSprite(game_info->window, game_menu->exit, NULL);
}

void set_value(struct game *game_info)
{
    game_info->time++;
    game_info->time2++;
    game_info->time_brb++;
    game_info->score++;
}

void display_window(struct game *game_info, struct gui *game_menu)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_info->window = sfRenderWindow_create(mode, "SFML window",
    sfResize | sfClose, NULL);
    sprite(game_info, game_menu);
    sfSound_play(game_info->ost);
    sfRenderWindow_setFramerateLimit(game_info->window, 30);
    while (sfRenderWindow_isOpen(game_info->window)) {
        game_info->mouse_pos = sfMouse_getPosition(game_info->window);
        while (sfRenderWindow_pollEvent(game_info->window, &game_info->event))
            event(game_info, game_menu);
        game(game_info, game_menu);
    }
}