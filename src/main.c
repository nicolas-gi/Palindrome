/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** main.c
*/

#include <stddef.h> /* NULL */
#include <stdio.h> /* printf */

#include "palindrome.h"

int main(int argc, char const **argv)
{
    error_handling(argc, argv);
    palindrome_t *pal = parse_argv(argc, argv);
    if (pal == NULL)
        return 84;
    parse_dash(pal, argv);
    if (pal->is_solution == 0) {
        printf("no solution\n");
    }
    return 0;
}
