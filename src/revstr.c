/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** revstr.c
*/

#include <string.h> /* strlen */
#include <stdlib.h> /* malloc */

char const *revstr(char const *str)
{
    int len = strlen(str);
    char *revstr = malloc(len + 1);
    if (revstr == NULL)
        return NULL;

    for (int i = 0; i < len; i++)
        revstr[i] = str[len - i - 1];
    revstr[len] = '\0';
    return revstr;
}
