/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** requirement.c
*/

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return 0;
    if (nb == 0)
        return 1;
    return nb * my_factrec_synthesis(nb - 1);
}

int my_squareroot_synthesis(int nb)
{
    int i = 0;

    if (nb < 0)
        return -1;
    while (i <= 46340 && i * i < nb)
        i++;
    if (i * i == nb)
        return i;
    return -1;
}
