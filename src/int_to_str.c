/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** int_to_str.c
*/

#include <stdlib.h> /* malloc */
#include <stdio.h> /* printf */

#include "palindrome.h"

char const *int_to_str(int i, int base)
{
    int index = 0;
    char *str = malloc(sizeof(char) * 32);
    if (str == NULL)
        return NULL;
    if (base < 2 || base > 10) {
        printf("invalid argument\n");
        exit(84);
    }

    for (; i > 0; i /= base, index++)
        str[index] = i % base + '0';
    str[index] = '\0';
    return revstr(str);
}
