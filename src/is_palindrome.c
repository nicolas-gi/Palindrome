/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** is_palindrome.c
*/

#include <string.h> /* strlen */

int is_palindrome(char const *word)
{
    int len = strlen(word);

    for (int i = 0; i < len / 2; i++)
        if (word[i] != word[len - i - 1])
            return 0;
    return 1;
}
