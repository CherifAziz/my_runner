/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** display nbr
*/

#include "my.h"

int nb_neg(int nb)
{
    int modulo = 0;

    nb += 5;
    if (nb > 10) {
        modulo = (nb % 10);
        nb = (nb - modulo) / 10;
        my_put_nbr(nb);
        my_putchar(modulo + 48);
    } else {
        my_putchar((nb + 5)+ 48);
    }
}

int my_put_nbr(int nb)
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