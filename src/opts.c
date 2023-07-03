/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** options.c
*/

#include <stddef.h> /* NULL */
#include <stdio.h> /* printf */
#include <stdlib.h> /* atoi */

#include "palindrome.h"

palindrome_t *dash_n(palindrome_t *pal, char const *argv)
{
    if (argv == NULL || !my_isnum(argv)) {
        printf("invalid argument\n");
        exit(84);
    }
    pal->nb = atoi(argv);
    pal->is_flag++;
    pal->is_opt = 1;
    return pal;
}

palindrome_t *dash_p(palindrome_t *pal, char const *argv)
{
    if (argv == NULL || !my_isnum(argv)) {
        printf("invalid argument\n");
        exit(84);
    }
    pal->pal = atoi(argv);
    pal->is_flag++;
    pal->is_opt = 1;
    return pal;
}

palindrome_t *dash_b(palindrome_t *pal, char const *argv)
{
    if (argv == NULL) {
        printf("invalid argument\n");
        exit(84);
    }
    if (!my_isnum(argv))
        return NULL;

    int neg = atoi(argv);
    if (neg < 2 || neg > 10) {
        printf("invalid argument\n");
        exit(84);
    }
    pal->base = atoi(argv);
    pal->is_opt = 1;
    return pal;
}

palindrome_t *dash_imin(palindrome_t *pal, char const *argv)
{
    if (argv == NULL) {
        printf("invalid argument\n");
        exit(84);
    }
    if (!my_isnum(argv))
        return NULL;

    int imin = atoi(argv);
    if (imin < 0) {
        printf("invalid argument\n");
        exit(84);
    }
    pal->imin = imin;
    pal->is_opt = 1;
    return pal;
}

palindrome_t *dash_imax(palindrome_t *pal, char const *argv)
{
    if (argv == NULL) {
        printf("invalid argument\n");
        exit(84);
    }

    if (!my_isnum(argv))
        return NULL;

    int imax = atoi(argv);

    pal->imax = imax;
    pal->is_opt = 1;
    return pal;
}
