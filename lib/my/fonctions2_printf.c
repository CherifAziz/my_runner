/*
** EPITECH PROJECT, 2021
** fonctions2_printf
** File description:
** desc
*/

#include <stdarg.h>
#include "my.h"

void printf_octal_nbr(va_list *ap)
{
    unsigned int nbr = va_arg(*ap, unsigned int);
    my_put_octal_nbr(nbr);
}

void printf_scientific_notation(va_list *ap)
{
    double nbr = va_arg(*ap, double);
    my_scientific_notation(nbr);
}

void printf_scientific_notation2(va_list *ap)
{
    double nbr = va_arg(*ap, double);
    my_scientific_notation2(nbr);
}

void printf_hex_nbr(va_list *ap)
{
    unsigned int nbr = va_arg(*ap, unsigned int);
    put_hex_nbr(nbr);
}