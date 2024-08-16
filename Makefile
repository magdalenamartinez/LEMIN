##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	lem_in

LIB	=	-L lib/my/ -lmy

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/init.c	\
		src/content.c	\
		src/file.c	\
		src/alg.c	\
		src/line.c	\
		src/simulation2.c	\
		src/simulation.c	\
		src/tunnels.c	\
		src/write.c	\


OBJ	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME): $(OBJ)
	make -C ./lib/my
	gcc -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB)

clean:
	make -C ./lib/my fclean
	rm -f $(NAME)


fclean: clean
	rm -f $(OBJ)
	rm -f ./lib/my/*.o
	rm -f libmy.a
	rm -f lib/my/libmy.a

re: 	fclean all

library: fclean

exec:	re
	./$(NAME)
