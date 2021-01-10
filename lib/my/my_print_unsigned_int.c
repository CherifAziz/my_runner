/*
** EPITECH PROJECT, 2020
** my_print_unsigned_int.c
** File description:
** desc
*/

#include "my.h"

int my_print_unsigned_int(unsigned int nbr)
{
    unsigned int intMax = 4294967295;

    if (nbr >= 0)
        my_put_unsigned_int(nbr);
    else
        my_put_unsigned_int(intMax-nbr);
}

int my_put_unsigned_int(unsigned int nb)
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
        my_put_nbr(nb);
        my_putchar(modulo + 48);
    } else {
        my_putchar(nb + 48);
    }
    return (1);
}