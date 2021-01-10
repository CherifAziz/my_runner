/*
** EPITECH PROJECT, 2020
** my_scientific_notation.c
** File description:
** desc
*/

#include "my.h"
#include <stdlib.h>

int my_scientific_notation(double nbr)
{
    char *str = malloc(sizeof(char * ) * 10);
    char *str2 = malloc(sizeof(char * ) * 10);
    int integer = nbr;
    if (nbr < 0)
        nbr = nbr * (-1);
    double result = 0;
    if (nbr == 0)
        my_putstr("0.000000e+00");
    else {
        str = my_revstr(my_putnbr3(integer, str, 0));
        result = nbr / puisssance_dix(my_strlen(str));
        integer = nbr;
        my_put_float(result);
        my_putchar('e');
        my_putchar('+');
        my_putchar('0');
        my_put_nbr(my_strlen(my_putnbr3(integer, str2, 0))- 1);
    }
}

int puisssance_dix(int n)
{
    int b = 1;
    int i = 0;
    while (i < n-1)
    {
        b = b *10;
        i++;
    }
    return (b);
}

int my_putnbr3(int nb, char *str, int i)
{
    int modulo = 0;
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb < 0) {
        nb_neg(nb);
        return (0);
    }
    if (nb >= 10) {
        modulo = (nb % 10);
        nb = (nb - modulo) / 10;
        str[i] = (modulo + 48);
        i++;
        my_putnbr3(nb, str, i);
    } else {
        str[i] = (nb +48);
    }
    return (str);
}