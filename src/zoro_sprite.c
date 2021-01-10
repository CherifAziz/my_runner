/*
** EPITECH PROJECT, 2021
** zoro_sprite.c
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

void zoro(struct game *game_info)
{
    game_info->zoro_run = sfTexture_createFromFile("rsc/zoro_run1.png",
    NULL);
    game_info->zoro_run2 = sfTexture_createFromFile("rsc/zoro_run2.png", NULL);
    game_info->zoro = sfSprite_create();
    game_info->zoro2 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro, game_info->zoro_run, NULL);
    sfSprite_setTexture(game_info->zoro2, game_info->zoro_run2, NULL);
    sfSprite_setPosition(game_info->zoro, game_info->zoro_vector);
    sfSprite_setPosition(game_info->zoro2, game_info->zoro_vector);
    game_info->zoro_jump = sfTexture_createFromFile("rsc/zoro_jump.png", NULL);
    game_info->zoro3 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro3, game_info->zoro_jump, NULL);
    sfSprite_setPosition(game_info->zoro3, game_info->vector_jump);
}

void zoro_attack(struct game *game_info)
{
    game_info->zoro_attack = sfTexture_createFromFile("rsc/zoro_attack1.png",
    NULL);
    game_info->zoro_atk1 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_atk1, game_info->zoro_attack, NULL);
    sfSprite_setPosition(game_info->zoro_atk1, game_info->zoro_vector);
    game_info->zoro_attack2 = sfTexture_createFromFile("rsc/zoro_attack2.png",
    NULL);
    game_info->zoro_atk2 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_atk2, game_info->zoro_attack2, NULL);
    sfSprite_setPosition(game_info->zoro_atk2, game_info->zoro_vector);
    game_info->zoro_attack3 = sfTexture_createFromFile("rsc/zoro_attack3.png",
    NULL);
    game_info->zoro_atk3 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_atk3, game_info->zoro_attack3, NULL);
    sfSprite_setPosition(game_info->zoro_atk3, game_info->zoro_vector);
}

void zoro_hit(struct game *game_info)
{
    game_info->zoro_damage = sfTexture_createFromFile("rsc/zohit.png", NULL);
    game_info->zoro_hit = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_hit, game_info->zoro_damage, NULL);
    sfSprite_setPosition(game_info->zoro_hit, game_info->zoro_vector);
    game_info->zoro_damage2 = sfTexture_createFromFile("rsc/zohit2.png", NULL);
    game_info->zoro_hit2 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_hit2, game_info->zoro_damage2, NULL);
    sfSprite_setPosition(game_info->zoro_hit2, game_info->zoro_vector);
    game_info->zoro_damage3 = sfTexture_createFromFile("rsc/zohit3.png", NULL);
    game_info->zoro_hit3 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_hit3, game_info->zoro_damage3, NULL);
    sfSprite_setPosition(game_info->zoro_hit3, game_info->zoro_vector);
    game_info->zoro_damage4 = sfTexture_createFromFile("rsc/zohit4.png", NULL);
    game_info->zoro_hit4 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_hit4, game_info->zoro_damage4, NULL);
    sfSprite_setPosition(game_info->zoro_hit4, game_info->vector_hit4);
    game_info->zoro_damage5 = sfTexture_createFromFile("rsc/zohit5.png", NULL);
    game_info->zoro_hit5 = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_hit5, game_info->zoro_damage5, NULL);
}

void zoro_sprite(struct game *game_info)
{
    sfSprite_setPosition(game_info->zoro_hit5, game_info->vector_hit3);
    game_info->zoro_life = sfTexture_createFromFile("rsc/zoro_life.png", NULL);
    game_info->life = sfSprite_create();
    sfSprite_setTexture(game_info->life, game_info->zoro_life, NULL);
    sfSprite_setPosition(game_info->life, game_info->life_vector);
    game_info->zoro_lower = sfTexture_createFromFile("rsc/zoro_down.png",
    NULL);
    game_info->zoro_down = sfSprite_create();
    sfSprite_setTexture(game_info->zoro_down, game_info->zoro_lower, NULL);
    sfSprite_setPosition(game_info->zoro_down, game_info->vector_hit2);
}

void brb_noir(struct game *game_info)
{
    game_info->barbe_noir1 = sfTexture_createFromFile("rsc/brn1.png", NULL);
    game_info->brb_noir1 = sfSprite_create();
    sfSprite_setTexture(game_info->brb_noir1, game_info->barbe_noir1, NULL);
    sfSprite_setPosition(game_info->brb_noir1, game_info->brb_vector);
    game_info->barbe_noir2 = sfTexture_createFromFile("rsc/brn2.png", NULL);
    game_info->brb_noir2 = sfSprite_create();
    sfSprite_setTexture(game_info->brb_noir2, game_info->barbe_noir2, NULL);
    sfSprite_setPosition(game_info->brb_noir2, game_info->brb_vector);
    game_info->barbe_noir_die = sfTexture_createFromFile("rsc/brnd.png", NULL);
    game_info->brb_die = sfSprite_create();
    sfSprite_setTexture(game_info->brb_die, game_info->barbe_noir_die, NULL);
    sfSprite_setPosition(game_info->brb_die, game_info->brb_vector);
    game_info->barbe_noir_die2 = sfTexture_createFromFile("rsc/brd.png", NULL);
    game_info->brb_die2 = sfSprite_create();
    sfSprite_setTexture(game_info->brb_die2, game_info->barbe_noir_die2, NULL);
    sfSprite_setPosition(game_info->brb_die2, game_info->brb_vector);
}