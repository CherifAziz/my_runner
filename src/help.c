/*
** EPITECH PROJECT, 2020
** help.c
** File description:
** desc
*/

#include "../lib/my/my.h"
#include "../include/my_hunter.h"

void print_help(void)
{
    my_printf("\n********WELCOME TO MY GAME********");
    my_printf("\n\nThis game is based on the rules of a finite Endless ");
    my_printf("Game.");
    my_printf("\nThe purpose of the game is to survive as long as possible.");
    my_printf("\nTo execute the game you just have to type this command :");
    my_printf("\n./my_runner");
    my_printf("\n\nHow to play :");
    my_printf("\n\nTo jump you have to press the space key.");
    my_printf("\nTo attack you have to press the right arrow key.");
    my_printf("\nTo bend down you have to press the down arrow key.");
    my_printf("\nTo pause the game you have to press the escape key.");
    my_printf("\n\nA few comments :");
    my_printf("\n\nThe difficulty of the game increases over time.");
    my_printf("\nThe options menu still does not work.");
    my_printf("\n\nTry to do the best score !");
    my_printf("\nEnjoy !\n");
}