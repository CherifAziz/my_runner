/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include "my.h"

void printf_hex_nbr2(va_list *ap)
{
    unsigned int nbr = va_arg(*ap, unsigned int);
    put_hex_nbr2(nbr);
}

void printf_unsigned_int(va_list *ap)
{
    unsigned int nbr = va_arg(*ap, unsigned int);
    my_print_unsigned_int(nbr);
}

int flag_finder(char str, char *FlagsTab)
{
    int a = 0;
    for (int i = 0; FlagsTab[i] != 0; i++) {
        if (str == FlagsTab[i])
            return (i);
        else
            a++;
    }
    return (a);
}

void my_printf(char *str, ...)
{
    void (*functions[13]) (va_list *) = {printf_str, printf_nbr, printf_nbr
    , printf_char, printf_float, printf_binary_nbr, printf_octal_nbr
    , printf_scientific_notation, printf_scientific_notation2
    , printf_hex_nbr, printf_hex_nbr2, printf_unsigned_int};
    char FlagsTab[13] = {'s', 'd', 'i', 'c', 'f', 'b', 'S', 'o', 'e', 'E'
    , 'x', 'X', 'u', 0};
    va_list ap;
    va_start(ap, str);
    for (int i = 0, counter_percentage = 0; str[i] != '\0'; i++) {
        if (str[i] == '%')
            counter_percentage++;
        if (i != 0 && str[i-1] == '%' && flag_finder(str[i], FlagsTab) != 16
        && counter_percentage % 2 == 1) {
            (*functions[flag_finder(str[i], FlagsTab)]) (&ap);
            counter_percentage = 0;
        } else if (str[i] != '%' || counter_percentage % 2 == 0)
            my_putchar(str[i]);
    }
    va_end(ap);
}