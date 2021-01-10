/*
** EPITECH PROJECT, 2020
** my_put_float
** File description:
** print a float
*/

#include <stdlib.h>
#include "my.h"

char *my_strncat2(char *dest, char const *src, int compteur)
{
    dest = malloc(sizeof(char) *compteur);
    int len_dest = 0;
    int len_src = my_strlen(src);
    for (int i = len_src -compteur; i <= len_src; i++, len_dest++) {
            dest[len_dest] = src[i];
    }
    dest[len_dest] = '\0';
    return (dest);
}

int print_zero(float number)
{
    if (number < 10)
        number = number * 10;
    while (number < 1000000)
    {
        my_putchar('0');
        number = number * 10;
    }
}

int my_put_float(float number)
{
    char *str3 = malloc(sizeof(char *) * 8);
    char *str = malloc(sizeof(char *) *5);
    char *str2 = malloc(sizeof(char *) *3);
    int integer = number;
    int compteur = 0;
    int number2 = number;
    if (number < 0)
        number = number * (-1);
    while (number2 < number && number < 1000000) {
        number = number * 10;
        compteur++;
        number2 = number;
    }
    str = my_putnbr2(number2, str3, 0);
    str2 = my_strncat2(str2, my_revstr(str), compteur);
    my_put_nbr(integer);
    my_putchar('.');
    my_put_nbr(my_getnbr(str2));
    print_zero(number);
}

int my_putnbr2(int nb, char *str, int i)
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
        my_putnbr2(nb, str, i);
    } else {
        str[i] = (nb +47);
    }
    return (str);
}