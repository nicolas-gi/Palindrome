/*
** EPITECH PROJECT, 2023
** synthesis
** File description:
** parse_dash.c
*/

#include <stddef.h> /* NULL */
#include <string.h> /* strcmp */

#include "palindrome.h"

palindrome_t *parse_dash(palindrome_t *pal, char const **argv)
{
    for (int i = 0; argv[i] != NULL; i++) {
        if (strcmp(argv[i], "-n") == 0 && pal->nb >= 0)
            return handle_dash_n(pal);
        if (strcmp(argv[i], "-p") == 0 && pal->pal >= 0)
            return handle_dash_p(pal);
    }
    return pal;
}
