##
## EPITECH PROJECT, 2020
## libmy.a
## File description:
## Makefile
##

CC	= 	gcc

SRC2	=	$(wildcard src/*.c src/map_solver/*.c)

OBJ2	=  $(SRC2:.c=.o)

NAME	=	solver

LDFLAGS	=	-I./include -L./lib/my -lmy

SFMLFLAGS	=	-l csfml-graphics -l csfml-system -l csfml-window -lm

CFLAGS	=	-W -Wall -Wextra -Wno-unused-variable

all:	$(NAME)

$(NAME):	$(OBJ2)
	make -C ./lib/my
	$(CC) -o $(NAME) $(OBJ2) $(LDFLAGS) $(SFMLFLAGS)

clean:
	make clean -C ./lib/my
	$(RM) $(OBJ2)

fclean: clean
	make fclean -C ./lib/my
	$(RM) -f $(NAME)

re:	fclean all
