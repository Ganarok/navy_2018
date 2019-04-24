##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for navy
##

SRC =	../main.c\
		playerone.c\
		ttyconnect.c\
		../source/wincond.c\
		../source/checkmap.c\
		../source/printmap.c\
		../source/playertwo.c\
		../source/my_putstr.c\
		../source/my_strlen.c\
		../source/my_getnbr.c\
		../source/my_strcmp.c\
		../source/modifymap.c\
		../source/my_str_isnum.c\
		../source/get_next_line.c\
		../source/my_putnbr_base.c\
		../source/my_str_to_word_array.c\
		../source/boat.c\

CC =	gcc

CFLAGS =	-W -Wextra -Wall

OBJ =	$(SRC:.c=.o)

NAME =	navy

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -g3

clean:
	rm -f $(OBJ)
	rm -f source/$(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all