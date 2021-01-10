/*
** EPITECH PROJECT, 2020
** my_h
** File description:
** desc
*/

#include <stdarg.h>

#ifndef __include_my_h__
#define __include_my_h__
void printf_nbr(va_list *ap);
void printf_str(va_list *ap);
void printf_char(va_list *ap);
void printf_float(va_list *ap);
void printf_binary_nbr(va_list *ap);
void printf_special_str(va_list *ap);
void printf_octal_nbr(va_list *ap);
void printf_scientific_notation(va_list *ap);
void printf_scientific_notation2(va_list *ap);
void printf_hex_nbr(va_list *ap);
int my_put_octal_nbr(unsigned int nbr);
int my_print_unsigned_int(unsigned int nbr);
int scientific_notation(double nbr);
int scientific_notation2(double nbr);
void my_special_putstr(char *str);
void put_hex_nbr(unsigned int nbr);
void put_hex_nbr2(unsigned int nbr);
void my_printf(char *str, ...);
void my_put_binary_nbr(int nbr);
int my_put_float(float number);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char *str);
int my_isneg(int n);
int my_is_prime(int nb);
int my_putchar(char c);
int my_put_nbr(int nbr);
int my_putstr(char const *str);
char *my_revstr(char *str);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);

#endif