/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** task02
*/

#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        str++;
    }
    return (0);
}