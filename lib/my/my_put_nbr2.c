/*
** EPITECH PROJECT, 2020
** my_put_nbr2.c
** File description:
** desc
*/

int my_putnbr_str(int nb, char *str, int i)
{
    int modulo = 0;
    if (nb < 0) {
        nb_neg(nb);
        return (0);
    }
    if (nb >= 10) {
        modulo = (nb % 10);
        nb = (nb - modulo) / 10;
        str[i] = (modulo + 48);
        i++;
        my_putnbr_str(nb, str, i);
    } else {
        str[i] = (nb +48);
    }
    return (str);
}