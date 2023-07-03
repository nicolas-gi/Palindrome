##
## EPITECH PROJECT, 2023
## palindrome
## File description:
## Makefile
##

NAME = palindrome

CC = gcc

CPPFLAGS += -iquote include/

CFLAGS += -Wall -Wextra

MAKEFLAGS += --no-print-directory

SRC_DIR = src/

SRC = main.c           \
      error_handling.c \
	  str_to_int.c     \
	  int_to_str.c     \
	  revstr.c         \
	  is_palindrome.c  \
	  parse_argv.c     \
	  opts.c           \
	  my_isnum.c       \
	  handle_dashes.c  \
	  parse_dash.c     \
	  multi_flags.c

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(LFLAGS) $(OBJ)

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(wildcard vgcore.*)
	@$(RM) $(wildcard *.log)
	@$(RM) $(wildcard *.html)
	@$(RM) $(wildcard *.css)
	@$(RM) $(wildcard *.gcov)
	@$(RM) $(wildcard src/*.gcno)
	@$(RM) $(wildcard src/*.gcda)
	@$(RM) $(NAME)

re : fclean all

debug : re
debug : export CFLAGS = -g3

gcovr : re
gcovr : export CFLAGS += -g3 -O0 -fprofile-arcs -ftest-coverage
gcovr : export LFLAGS += -lgcov --coverage

report_html :
	@./tester.sh
	@gcovr -r . --html-details details.html --html-theme green
	@xdg-open details.html

.PHONY : all clean fclean re debug gcovr report_html
