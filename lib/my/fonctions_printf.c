/*
** EPITECH PROJECT, 2020
** fonctions.c
** File description:
** desc
*/

#include "my.h"
#include <stdarg.h>

void printf_nbr(va_list *ap)
{
    int nbr = va_arg(*ap, int);
    my_put_nbr(nbr);
}

void printf_str(va_list *ap)
{
    char *str = va_arg(*ap, char *);
    my_putstr(str);
}

void printf_char(va_list *ap)
{
    char c = va_arg(*ap, int);
    my_putchar(c);
}

void printf_float(va_list *ap)
{
    float nbr = va_arg(*ap, double);
    my_put_float(nbr);
}

void printf_binary_nbr(va_list *ap)
{
    int nbr = va_arg(*ap, int);
    my_put_binary_nbr(nbr);
}