##
## EPITECH PROJECT, 2024
## Zappy
## File description:
## Makefile
##

SRC	=	src/main.cpp

NAME 	= 	zappy_gui

OBJ 	=	$(SRC:.cpp=.o)

CC		=	g++

CXXFLAGS 	=	-std=c++20 -Wall -Wextra

# LIBCONFIGFLAG	=	-lconfig++

all:		$(NAME)

RACINE 	=	../

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)
		@mv $(NAME) $(RACINE)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

debug: $(CXXFLAGS) += -g3
debug: re

re: fclean all

.PHONY: all clean fclean debug re