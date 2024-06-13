##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

NAME = zappy_server

LIB	=	lib/count_elements_arr.c	\
		lib/str_tok_word_array.c	\
		lib/display_array.c	\
		lib/player_linked_list.c

SRC	=	src/main.c	\
		src/server.c	\
		src/handle_client.c	\
		src/map.c	\
		src/handle_events.c	\
		src/handle_commands.c

OBJ =           $(SRC:.c=.o) $(LIB:.c=.o)

CFLAGS = -Wall -Wextra

INCLUDE	=	-I../include

all: $(NAME)

RACINE	=	../

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@mv $(NAME) $(RACINE)

clean :
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) vgcore*
	$(RM) coding-style-reports.log

debug: CFLAGS += -g3
debug: re

re : fclean all

.PHONY : all clean fclean re
