/*
** EPITECH PROJECT, 2020
** my_put_binary_nbr
** File description:
** convert decimal number to a binary number and print it
*/

#include <stdlib.h>
#include "my.h"

void my_put_binary_nbr(int nbr)
{
    char *tab = malloc(sizeof(char *) * 20);
    for (int i = 0; nbr != 1; i++) {
        tab[i] = (nbr % 2) + 48;
        nbr = nbr / 2;
        if (nbr == 1)
            tab[i+1] = 49;
    }
    my_put_nbr(my_getnbr(my_revstr(tab)));
}