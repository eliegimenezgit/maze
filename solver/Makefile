##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## file of compilation
##

SRC = ./src/main.c            \
      ./src/solver.c	\
	  ./src/maze.c

OBJ = $(SRC:.c=.o)

NAME = solver

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -I.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
