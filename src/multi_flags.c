/*
** EPITECH PROJECT, 2022
** palindrome
** File description:
** multi_flags.c
*/

#include <stdlib.h> /* exit */
#include <string.h> /* strcmp */
#include <stdio.h> /* printf */

#include "palindrome.h"

int is_multi_flag(char const **arguments, char *flag)
{
    int exist = 0;

    for (int i = 0; arguments[i] != NULL; i++) {
        if (strcmp(arguments[i], flag) == 0)
            exist++;
    }
    if (exist > 1) {
        printf("invalid argument\n");
        exit(84);
    }
    return 0;
}
