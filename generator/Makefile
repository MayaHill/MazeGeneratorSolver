##
## EPITECH PROJECT, 2020
## Dante Star
## File description:
## Makefile
##

CC	=	gcc

SRC		=	$(wildcard *.c)

OBJ		= $(SRC:.c=.o)

NOM		=	generator

LDFLAGS	=	-I./../include -L./../lib/my -lmy

CFLAGS	=	-W -Wall -Wextra

all:	$(NOM)

$(NOM):	$(OBJ)
	$(CC) $(OBJ) -o $(NOM) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NOM)

re:	fclean all