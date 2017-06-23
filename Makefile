##
## Makefile for  in /home/romain.huet/rendu/Backup_Zappy
## 
## Made by Romain HUET
## Login   <romain.huet@epitech.net>
## 
## Started on  Mon Jun 19 11:37:44 2017 Romain HUET
## Last update Fri Jun 23 15:22:55 2017 Romain HUET
##

CC		= gcc

RM		= rm -f

CFLAGS		= -W -Wextra -Wall -I./include/ 

SERVER		= zappy_server

SERVER_SRCS	= srcs/server/main_serv.c	\
		  srcs/server/help_serv.c	\
		  srcs/server/args_manager.c	\
		  srcs/server/init_serv.c	\
		  srcs/server/init_args.c	\
		  srcs/server/check_params.c	\
		  srcs/server/utils.c		\
		  srcs/server/new_connection.c	\
		  srcs/server/server_loop.c	\
		  srcs/server/init_players.c	\
		  srcs/server/show_map.c	\
		  srcs/server/map.c		\
		  srcs/server/get_nth_word.c

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)

all: server

server: $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) 

clean:
	$(RM) $(AI_OBJS) $(SERVER_OBJS) srcs/ai/*~ srcs/server/*~ include/ai/*~ include/server/*~ *~

fclean: clean
	$(RM) $(SERVER) $(AI)

re: fclean all

.PHONY: all clean fclean re
