/*
** EPITECH PROJECT, 2023
** synthesis
** File description:
** parse_argv.c
*/

#include <stdlib.h> /* malloc */
#include <string.h> /* strcmp */
#include <stdio.h> /* printf */

#include "palindrome.h"

static palindrome_t *alloc_pal(void)
{
    palindrome_t *pal = malloc(sizeof(palindrome_t));
    if (pal == NULL)
        return NULL;

    pal->nb = 0;
    pal->pal = 0;
    pal->base = 10;
    pal->imin = 0;
    pal->imax = 100;
    pal->is_solution = 0;
    pal->is_flag = 0;
    pal->is_opt = 0;
    return pal;
}

static palindrome_t *parse_opts(palindrome_t *pal, char const **argv, int argc)
{
    for (int i = 1; i < argc; i += 2) {
        pal->is_opt = 0;
        if (strcmp(argv[i], "-n") == 0)
            dash_n(pal, argv[i + 1]);
        if (strcmp(argv[i], "-p") == 0)
            dash_p(pal, argv[i + 1]);
        if (strcmp(argv[i], "-b") == 0)
            dash_b(pal, argv[i + 1]);
        if (strcmp(argv[i], "-imin") == 0)
            dash_imin(pal, argv[i + 1]);
        if (strcmp(argv[i], "-imax") == 0)
            dash_imax(pal, argv[i + 1]);
        if (pal->is_opt == 0) {
            printf("invalid argument\n");
            exit(84);
        }
    }
    return pal;
}

static palindrome_t *error_handling_opts(palindrome_t *pal, char const **argv)
{
    int exist = 0;

    if (argv == NULL || pal == NULL)
        return NULL;
    is_multi_flag(argv, "-imin");
    is_multi_flag(argv, "-imax");
    is_multi_flag(argv, "-n");
    is_multi_flag(argv, "-b");
    is_multi_flag(argv, "-p");
    if (pal->imin > pal->imax || exist > 1) {
        printf("invalid argument\n");
        exit(84);
    }
    return pal;
}

palindrome_t *parse_argv(int argc, char const **argv)
{
    palindrome_t *pal = alloc_pal();
    if (pal == NULL)
        return NULL;

    if (error_handling_opts(pal, argv) == NULL) {
        free(pal);
        return NULL;
    }
    if (parse_opts(pal, argv, argc) == NULL) {
        free(pal);
        return NULL;
    }
    if (pal->is_flag > 1 || pal->imin > pal->imax) {
        printf("invalid argument\n");
        exit(84);
    }
    return pal;
}
