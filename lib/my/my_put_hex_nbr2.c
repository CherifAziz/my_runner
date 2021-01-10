/*
** EPITECH PROJECT, 2020
** my_put_hex_nbr2.c
** File description:
** desc
*/

#include "my.h"
#include <stdlib.h>

char *hexadecimal_convertor2(char *str)
{
    char letters[5] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 58 && str[i] <= 63) {
            str[i] = letters[letters_finder2(str[i] +7, letters)];
        }
    }
    return (str);
}

void put_hex_nbr2(unsigned int nbr)
{
    unsigned int intMax = 4294967295;
    int i = 0;
    char *hexa_nbr = malloc(sizeof(char *) *10);
    char *modulo = malloc(sizeof(char *) *10);
    if (!(nbr >= 0) || !(nbr >= 0) && !(nbr <= intMax))
        nbr = intMax - nbr;
    do {
            hexa_nbr[i] = (nbr % 16) +48;
            nbr = nbr / 16;
            i++;
    } while (nbr > 0);
    hexa_nbr = hexadecimal_convertor2(my_revstr(hexa_nbr));
    my_putstr(hexa_nbr);
}

int letters_finder2(char *str, char *letters)
{
    for (int i = 0; letters != 0; i++) {
        if (str == letters[i])
            return (i);
    }
}