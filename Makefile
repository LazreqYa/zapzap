##
## EPITECH PROJECT, 2024
## B-NWP-400-PAR-4-1-myteams-ismaiel.diapaka
## File description:
## Makefile
##

NAMESERVER 	= zappy_server
NAMEGUI 	= zappy_gui
NAMEAI 		= zappy_ai

all: server GUI AI

server:
	make -C Server/

# GUI:
# 	make -C GUI/

# AI:
# 	make -C AI/

clean:
	make -C Server/ clean
	make -C GUI/ clean
# make -C AI/ clean

fclean:	clean
	$(RM) $(NAMESERVER) $(NAMEGUI) $(NAMEAI)
	$(RM) coding-style-reports.log

debug:
	make -C server/ debug

re:	fclean all

.PHONY:	all clean fclean re server GUI AI debug
