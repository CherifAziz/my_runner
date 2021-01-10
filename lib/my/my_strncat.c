/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** desc
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int compteur)
{
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);

    for (int i = len_src -compteur; i < len_src; i++, len_dest++) {
        if (src[i] != 0)
            dest[len_dest] = src[i];
        else
            dest[len_dest] = '\0';
    }
    dest[len_dest] = '\0';
    return (dest);
}