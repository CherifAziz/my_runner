/*
** EPITECH PROJECT, 2021
** game_over.c
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

void game(struct game *game_info, struct gui *game_menu)
{
    if (game_menu->die == 0) {
        if (game_menu->escape == 0)
            set_value(game_info);
        render(game_info, game_menu);
        sfRenderWindow_drawText(game_info->window, game_info->Score, NULL);
        sfText_setString(game_info->score_nbr, conv_score(game_info->score));
        sfRenderWindow_drawText(game_info->window, game_info->score_nbr, NULL);
        sfRenderWindow_display(game_info->window);
    } else {
        display_end(game_info, game_menu);
        sfRenderWindow_display(game_info->window);
    }
}

void display_end(struct game *game_info, struct gui *game_menu)
{
    if (game_menu->best_score < game_info->score)
        game_menu->best_score = game_info->score;
    if (game_menu->choice2 == 0)
        sfRenderWindow_drawSprite(game_info->window, game_menu->end, NULL);
    if (game_menu->choice2 == 1)
        sfRenderWindow_drawSprite(game_info->window, game_menu->end1, NULL);
    if (game_menu->choice2 == 2)
        sfRenderWindow_drawSprite(game_info->window, game_menu->end2, NULL);
    game_info->score_vector.x = 900;
    game_info->score_vector.y = 450;
    sfText_setPosition(game_info->score_nbr, game_info->score_vector);
    sfText_setFont(game_info->score_nbr, game_info->rubik);
    sfText_setColor(game_info->score_nbr, sfWhite);
    sfText_setCharacterSize(game_info->score_nbr, 68);
    sfText_setString(game_menu->score_best, conv_score(game_menu->best_score));
    sfRenderWindow_drawText(game_info->window, game_menu->score_best, NULL);
    sfRenderWindow_drawText(game_info->window, game_info->score_nbr, NULL);
}