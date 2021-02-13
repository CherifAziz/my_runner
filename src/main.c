/*
** EPITECH PROJECT, 2020
** my_hunter
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

char *conv_score(int nbr)
{
    int len = number_digits(nbr);
    char *result = malloc(sizeof(char) * len);
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}

int number_digits(int nbr)
{
    int n = 1;
    int po = 10;
    while (nbr >= po) {
        n++;
        po *= 10;
    }
    return (n);
}

void sprite(struct game *game_info, struct gui *game_menu)
{
    background(game_info);
    zoro(game_info);
    zoro_attack(game_info);
    brb_noir(game_info);
    zoro_hit(game_info);
    zoro_sprite(game_info);
    menu(game_menu);
    text(game_info, game_menu);
    sound(game_info);
    game_over(game_menu);
}

void reset(struct game *game_info, struct gui *game_menu)
{
    init_game_struct(game_info);
    init_game_struct2(game_info, game_menu);
    text(game_info, game_menu);
    zoro_sprite(game_info);
}

int main(int ac, char **av)
{
    struct game *game_info = get_info();
    struct gui *game_menu = get_menu();
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            print_help();
        else {
            my_printf("%s is not a valid argument\n", av[1]);
            return (84);
        }
    }
    else if (ac > 2)
        my_printf("Too much arguments");
    else
        display_window(game_info, game_menu);
}