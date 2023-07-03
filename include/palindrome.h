/*
** EPITECH PROJECT, 2023
** palindrome
** File description:
** palindrome.h
*/

#ifndef PALINDROME_H_
    #define PALINDROME_H_

typedef struct palindrome_s {
    int nb;
    int pal;
    int base;
    int imin;
    int imax;
    int is_solution;
    int is_flag;
    int is_opt;
} palindrome_t;

//string to integer
int str_to_int(char const *str, int base);
//int to string
char const *int_to_str(int i, int base);
//reverse string
char const *revstr(char const *str);
//is palindrome
int is_palindrome(char const *str);
//is number
int my_isnum(char const *str);

//error handling
int error_handling(int argc, char const **argv);

//PARSING
palindrome_t *parse_argv(int argc, char const **argv);
palindrome_t *parse_dash(palindrome_t *pal, char const **argv);

//DASH
palindrome_t *dash_n(palindrome_t *pal, char const *argv);
palindrome_t *dash_p(palindrome_t *pal, char const *argv);
palindrome_t *dash_b(palindrome_t *pal, char const *argv);
palindrome_t *dash_imin(palindrome_t *pal, char const *argv);
palindrome_t *dash_imax(palindrome_t *pal, char const *argv);

//palindrome
palindrome_t *handle_dash_n(palindrome_t *pal);
palindrome_t *handle_dash_p(palindrome_t *pal);

int is_multi_flag(char const **arguments, char *flag);

#endif /* PALINDROME_H_ */
