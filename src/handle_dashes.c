/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** handle_dashes.c
*/

#include <stdio.h> /* printf */
#include <stdlib.h> /* strcmp */

#include "palindrome.h"

static palindrome_t *print_p(palindrome_t *pal, int start, int tmp, int i)
{
    if (tmp == pal->pal && i >= pal->imin && i <= pal->imax) {
        printf("%d leads to %d in %d iteration(s) in base %d\n",
            start, pal->pal, i, pal->base);
        pal->is_solution = 1;
    }
    return pal;
}

palindrome_t *handle_dash_p(palindrome_t *pal)
{
    int start = 1;
    char const *tmp_str = int_to_str(pal->pal, pal->base);
    if (!is_palindrome(tmp_str)) {
        printf("invalid argument\n");
        exit(84);
    }
    char const *rev_str = NULL;
    int rev = 0;

    for (int i = 0; start <= pal->pal; start++, i = 0) {
        for (int tmp = start; i <= pal->imax; i++) {
            pal = print_p(pal, start, tmp, i);
            tmp_str = int_to_str(tmp, pal->base);
            rev_str = revstr(tmp_str);
            rev = str_to_int(rev_str, pal->base);
            tmp += rev;
        }
    }
    return pal;
}

palindrome_t *handle_dash_n(palindrome_t *pal)
{
    int nb = pal->nb;
    int rev = 0;
    int count = 0;
    char const *nb_str = int_to_str(nb, pal->base);
    char const *rev_str = NULL;

    while (count <= pal->imax && (!is_palindrome(nb_str) ||
        count < pal->imin)) {
        rev_str = revstr(nb_str);
        rev = str_to_int(rev_str, pal->base);
        nb += rev;
        nb_str = int_to_str(nb, pal->base);
        count++;
    }
    if (count <= pal->imax) {
        printf("%d leads to %d in %d iteration(s) in base %d\n",
            pal->nb, nb, count, pal->base);
        pal->is_solution = 1;
    }
    return pal;
}
