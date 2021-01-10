/*
** EPITECH PROJECT, 2020
** my_put_octal_nbr
** File description:
** convert decimal numbers to octal numbers
*/

#include <stdlib.h>
#include "my.h"

int my_put_octal_nbr(unsigned int nbr)
{
    unsigned int int_max = 4294967295;
    int i = 0;
    char *octal_nbr = malloc(sizeof(char *) *12);
    if (nbr < 0) {
        nbr = int_max - nbr;
    }
    do {
            octal_nbr[i] = (nbr % 8) +48;
            nbr = nbr / 8;
            i++;
    } while (nbr != 0);
    my_putstr(my_revstr(octal_nbr));
}