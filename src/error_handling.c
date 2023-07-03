/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** error_handling.c
*/

#include <string.h> /* strcmp */
#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */

int error_handling(int argc, char const **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        printf("USAGE\n"
        "      ./palindrome -n number -p palindrome [-b base] [-imin i] "
        "[-imax i]\n\nDESCRIPTION\n"
        "      -n n\tinteger to be transformed (>=0)\n"
        "      -p pal\tpalindromic number to be obtained (incompatible with "
        "the -n\n\t\toption) (>=0)\n"
        "\t\tif defined, all fitting values of n will be output\n"
        "      -b base\tbase in which the procedure will be executed "
        "(1<b<=10) [def: 10]\n"
        "      -imin i\tminimum number of iterations, included (>=0) [def: 0]"
        "\n      -imax i\tmaximum number of iterations, included (>=0) [def: "
        "100]\n");
        exit(0);
    }
    return 0;
}
