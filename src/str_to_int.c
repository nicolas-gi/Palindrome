/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** str_to_int.c
*/

#include <limits.h> /* INT_MAX && INT_MIN */
#include <stdlib.h> /* strtol */

int str_to_int(char const *str, int base)
{
    char *endptr;
    long result = strtol(str, &endptr, base);

    if (endptr == str)
        return -1;
    if (*endptr != '\0')
        return -1;
    if (result > INT_MAX || result < INT_MIN)
        return -1;
    return result;
}
