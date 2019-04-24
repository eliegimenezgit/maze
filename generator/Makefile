##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## file of compilation
##

SRC = ./src/main.c            \
      ./src/generator.c       \
      ./src/core.c          \
      ./src/particular_case.c

OBJ = $(SRC:.c=.o)

NAME = generator

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
