##
## EPITECH PROJECT, 2020
## Makefile lib
## File description:
## desc
##

SRC     =       my_putstr.c		\
				fonctions_printf.c	\
				fonctions2_printf.c	\
				my_put_nbr2.c		\
				my_putchar.c		\
				my_strlen.c		\
				my_put_hex_nbr.c	\
				my_print_unsigned_int.c	\
				my_scientific_notation.c	\
				my_scientific_notation2.c	\
				my_put_hex_nbr2.c	\
				my_put_octal_nbr.c	\
				my_strcpy.c		\
				my_put_binary_nbr.c	\
				my_put_float.c	\
				my_revstr.c		\
				my_put_nbr.c		\
				my_getnbr.c		\
		 		my_printf.c

NAME = libmy.a

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		rm libmy.a

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../libmy.a

re: fclean all