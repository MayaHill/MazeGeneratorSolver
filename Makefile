##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

NOM = generator

CFLAGS += -I ./include/
CFLAGS += -W -Wall -Wextra

all:	$(NOM)

$(NOM):	comp $(OBJ) $(OBJ2)
	make -C ./solver/
	make -C ./generator/
	make clean

comp:
	make -C ./lib/my

clean:
	make clean -C ./lib/my
	make clean -C ./solver/
	make clean -C ./generator/

fclean: clean
	$(RM) ./generator/generator
	$(RM) ./solver/solver
	make fclean -C ./lib/my

re:	fclean all

r:	clean $(OBJ) $(OBJ2)
	$(RM) ./solver/solver
	$(RM) ./generator/generator
	make -C ./solver/
	make -C ./generator/
	make clean