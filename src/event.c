/*
** EPITECH PROJECT, 2020
** event.c
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
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Font.h>
#include "../lib/my/my.h"
#include "../include/my_hunter.h"

void event(struct game *game_info, struct gui *game_menu)
{
    if (game_info->event.type == sfEvtClosed)
        sfRenderWindow_close(game_info->window);
    if (sfKeyboard_isKeyPressed(sfKeySpace) && game_info->jump != 1 &&
    game_info->attack != 1 && game_info->down != 1 && game_info->time2 < 150) {
        sfSound_play(game_info->jump_sound);
        game_info->time2 = 50;
        game_info->jump = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && game_info->jump != 1 &&
    game_info->attack != 1 && game_info->down != 1 && game_info->time2 < 150) {
        sfSound_play(game_info->attack_sound);
        game_info->attack = 1;
        game_info->time2 = 100;
    }
    event2(game_info, game_menu);
}

void event2(struct game *game_info, struct gui *game_menu)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) && game_info->jump != 1 &&
    game_info->attack != 1 && game_info->down != 1 && game_info->time2 < 150) {
        game_info->time2 = 300;
        game_info->down = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (game_menu->escape == 0 || game_menu->escape == 1)
            game_menu->escape++;
        else if (game_menu->escape == 2 || game_menu->escape == 3) {
            if (game_menu->escape == 2)
                game_menu->escape++;
            else
                game_menu->escape = 0;
        }
    }
    mouse_pos(game_info, game_menu);
    mouse_pressed(game_info, game_menu);
    game_over_menu(game_info, game_menu);
}

void game_over_menu(struct game *game_info, struct gui *game_menu)
{
    if (game_info->mouse_pos.x >= 307 && game_info->mouse_pos.x < 776
    && game_info->mouse_pos.y >= 834 && game_info->mouse_pos.y < 924)
        game_menu->choice2 = 1;
    else if (game_info->mouse_pos.x >= 1127 && game_info->mouse_pos.x < 1596
    && game_info->mouse_pos.y >= 834 && game_info->mouse_pos.y < 924)
        game_menu->choice2 = 2;
    else
        game_menu->choice2 = 0;
}

void mouse_pos(struct game *game_info, struct gui *game_menu)
{
    if (game_info->mouse_pos.x >= 737 && game_info->mouse_pos.x < 1068
    && game_info->mouse_pos.y >= 402 && game_info->mouse_pos.y < 465)
        game_menu->choice = 1;
    else if (game_info->mouse_pos.x >= 737 && game_info->mouse_pos.x < 1068
    && game_info->mouse_pos.y >= 612 && game_info->mouse_pos.y < 675)
        game_menu->choice = 3;
    else
        game_menu->choice = 0;
}

void mouse_pressed(struct game *game_info, struct gui *game_menu)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (game_info->mouse_pos.x >= 737 && game_info->mouse_pos.x < 1068
        && game_info->mouse_pos.y >= 402 && game_info->mouse_pos.y < 465
        && game_menu->escape != 0)
            game_menu->escape = 0;
        if (game_info->mouse_pos.x >= 737 && game_info->mouse_pos.x < 1068
        && game_info->mouse_pos.y >= 612 && game_info->mouse_pos.y < 675
        && game_menu->escape != 0)
            sfRenderWindow_close(game_info->window);
        if (game_info->mouse_pos.x >= 307 && game_info->mouse_pos.x < 776
        && game_info->mouse_pos.y >= 834 && game_info->mouse_pos.y < 924
        && game_menu->die != 0)
            reset(game_info, game_menu);
        if (game_info->mouse_pos.x >= 1127 && game_info->mouse_pos.x < 1596
        && game_info->mouse_pos.y >= 834 && game_info->mouse_pos.y < 924
        && game_menu->die != 0)
            sfRenderWindow_close(game_info->window);
    }
}