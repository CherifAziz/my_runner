##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## desc
##

SRC	=	./src/main.c	\
		./src/help.c	\
		./src/event.c	\
		./src/display_window.c \
		./src/display_zoro.c	\
		./src/display_brb_noir.c	\
		./src/gui_sprite.c	\
		./src/zoro_sprite.c	\
		./src/init_struct.c	\
		./src/game_over.c

NAME	=	my_runner

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my/
		gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l csfml-audio -Llib/ -lmy -I ./include/

clean:
		rm -f $(OBJ)
		make clean -C ./lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/my/

re: fclean all