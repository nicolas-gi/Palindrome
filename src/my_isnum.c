/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** my_isnum.c
*/

int my_isnum(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}
