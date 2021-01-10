/*
** EPITECH PROJECT, 2021
** gui_sprite.c
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

void text(struct game *game_info, struct gui *game_menu)
{
    game_menu->peach = sfColor_fromRGB(255, 189, 89);
    game_info->one_piece = sfFont_createFromFile("rsc/one piece font.ttf");
    game_info->Score = sfText_create();
    sfText_setFont(game_info->Score, game_info->one_piece);
    sfText_setString(game_info->Score, "Score :");
    sfText_setColor(game_info->Score, sfRed);
    sfText_setCharacterSize(game_info->Score, 60);
    game_info->score_nbr = sfText_create();
    sfText_setFont(game_info->score_nbr, game_info->one_piece);
    sfText_setString(game_info->score_nbr, convert_score(game_info->score));
    sfText_setColor(game_info->score_nbr, sfRed);
    sfText_setCharacterSize(game_info->score_nbr, 60);
    sfText_setPosition(game_info->score_nbr, game_info->score_vector);
    game_info->rubik = sfFont_createFromFile("rsc/Rubik-Black.ttf");
    game_menu->score_best = sfText_create();
    sfText_setFont(game_menu->score_best, game_info->rubik);
    sfText_setPosition(game_menu->score_best, game_menu->vector_score);
    sfText_setColor(game_menu->score_best, game_menu->peach);
    sfText_setCharacterSize(game_menu->score_best, 68);
}

void sound(struct game *game_info)
{
    game_info->ost = sfSound_create();
    game_info->ost_buffer = sfSoundBuffer_createFromFile("rsc/ost2.wav");
    sfSound_setBuffer(game_info->ost, game_info->ost_buffer);
    game_info->attack_sound = sfSound_create();
    game_info->attack_buffer = sfSoundBuffer_createFromFile("rsc/attack.wav");
    sfSound_setBuffer(game_info->attack_sound, game_info->attack_buffer);
    game_info->jump_sound = sfSound_create();
    game_info->jump_buffer = sfSoundBuffer_createFromFile("rsc/jump.wav");
    sfSound_setBuffer(game_info->jump_sound, game_info->jump_buffer);
    sfSound_setLoop(game_info->ost, sfTrue);
}

void menu(struct gui *game_menu)
{
    game_menu->echap = sfTexture_createFromFile("rsc/echap.png", NULL);
    game_menu->menu = sfSprite_create();
    sfSprite_setTexture(game_menu->menu, game_menu->echap, NULL);
    game_menu->echap2 = sfTexture_createFromFile("rsc/echap2.png", NULL);
    game_menu->resume = sfSprite_create();
    sfSprite_setTexture(game_menu->resume, game_menu->echap2, NULL);
    game_menu->echap3 = sfTexture_createFromFile("rsc/echap3.png", NULL);
    game_menu->options = sfSprite_create();
    sfSprite_setTexture(game_menu->options, game_menu->echap3, NULL);
    game_menu->echap4 = sfTexture_createFromFile("rsc/echap4.png", NULL);
    game_menu->exit = sfSprite_create();
    sfSprite_setTexture(game_menu->exit, game_menu->echap4, NULL);
}

void background(struct game *game_info)
{
    game_info->background = sfTexture_createFromFile("rsc/background.png",
    NULL);
    game_info->ground = sfTexture_createFromFile("rsc/ground.png", NULL);
    game_info->sprite = sfSprite_create();
    game_info->ground_game = sfSprite_create();
    sfSprite_setTexture(game_info->sprite, game_info->background, NULL);
    sfSprite_setTexture(game_info->ground_game, game_info->ground, NULL);
    game_info->background2 = sfTexture_createFromFile("rsc/background.png",
    NULL);
    game_info->sprite2 = sfSprite_create();
    sfSprite_setTexture(game_info->sprite2, game_info->background2, NULL);
    game_info->ground_game2 = sfSprite_create();
    sfSprite_setTexture(game_info->ground_game2, game_info->ground, NULL);
    game_info->ground2 = sfTexture_createFromFile("rsc/ground2.png", NULL);
    game_info->ground3 = sfTexture_createFromFile("rsc/ground3.png", NULL);
    game_info->ground_game3 = sfSprite_create();
    game_info->ground_game4 = sfSprite_create();
    sfSprite_setTexture(game_info->ground_game3, game_info->ground2, NULL);
    sfSprite_setTexture(game_info->ground_game4, game_info->ground3, NULL);
}

void game_over(struct gui *game_menu)
{
    game_menu->game_over = sfTexture_createFromFile("rsc/end.png", NULL);
    game_menu->end = sfSprite_create();
    sfSprite_setTexture(game_menu->end, game_menu->game_over, NULL);
    game_menu->game_over1 = sfTexture_createFromFile("rsc/end1.png", NULL);
    game_menu->end1 = sfSprite_create();
    sfSprite_setTexture(game_menu->end1, game_menu->game_over1, NULL);
    game_menu->game_over2 = sfTexture_createFromFile("rsc/end2.png", NULL);
    game_menu->end2 = sfSprite_create();
    sfSprite_setTexture(game_menu->end2, game_menu->game_over2, NULL);
}