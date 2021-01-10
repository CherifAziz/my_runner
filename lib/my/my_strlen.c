/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** count char in string
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[0] != '\0')
    {
        str++;
        i++;
    }
    return (i);
}