/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** str copy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int b = my_strlen(dest);

    while (src[i] != '\0') {
        dest[b] = src[i];
        i++;
        b++;
    }
    return (dest);
}