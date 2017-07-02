##
## Makefile for  in /home/romain.huet/rendu/Backup_Zappy
## 
## Made by Romain HUET
## Login   <romain.huet@epitech.net>
## 
## Started on  Mon Jun 19 11:37:44 2017 Romain HUET
##

CC		= gcc

RM		= rm -f

CFLAGS		= -W -Wextra -Wall -I./include/client/ -I./include/server/ -g

SERVER		= zappy_server

AI		= zappy_ai

SERVER_SRCS	=	srcs/server/main_serv.c		\
			srcs/server/help_serv.c		\
		  	srcs/server/check_params.c	\
		  	srcs/server/init_args.c		\
		  	srcs/server/args_manager.c	\
		  	srcs/server/args_getters.c	\
		  	srcs/server/init_serv.c		\
		  	srcs/server/init_players.c	\
		  	srcs/server/map.c		\
	 	  	srcs/server/map_info.c		\
		  	srcs/server/show_map.c		\
		  	srcs/server/player_action.c	\
		  	srcs/server/player_info.c	\
		  	srcs/server/player_inv.c	\
		  	srcs/server/player_look.c	\
		  	srcs/server/player_move.c	\
		  	srcs/server/utils.c		\
		  	srcs/server/new_connection.c	\
		  	srcs/server/settings.c		\
		  	srcs/server/fd_settings.c	\
		  	srcs/server/check_fd_sets.c	\
		  	srcs/server/server_loop.c	\
		  	srcs/server/get_nth_word.c	\
		  	srcs/server/gclient_talking.c	\
		  	srcs/server/connect_nbr.c	\
			srcs/server/sighandling.c	\
			srcs/server/broadcast.c		\
			srcs/server/team_manager.c	\
			srcs/server/cut_cmd.c		\
			srcs/server/cmds_manager.c	\
			lib/my_strtowordtab.c		\
			srcs/server/timed_cmd_move.c	\
			srcs/server/timed_cmd_special.c	\
			srcs/server/timed_cmd_res.c	\
			srcs/server/cycle_time.c

AI_SRCS		= 	srcs/client/call.c			\
			srcs/client/call2.c			\
			srcs/client/call3.c			\
			srcs/client/check.c			\
			srcs/client/client.c			\
			srcs/client/cmd.c			\
			srcs/client/graphic/client_graph.c	\
			srcs/client/graphic/client_graph2.c	\
			srcs/client/graphic/list.c		\
			srcs/client/graphic/my_strtowordtab.c	\
			srcs/client/graphic/my_strcmp.c		\
			srcs/client/graphic/rect.c		\
			srcs/client/graphic/init.c		\
			srcs/client/graphic/display.c		\
			srcs/client/graphic/receive.c		\
			srcs/client/graphic/inittoad.c		\

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)

AI_OBJS		= $(AI_SRCS:.c=.o)

all: server ai

server: $(SERVER_OBJS)
	$(CC) -o $(SERVER) $(SERVER_OBJS) -lrt

ai: $(AI_OBJS)
	$(CC) -o $(AI) $(AI_OBJS) `sdl-config --libs --clfags` -lSDL_ttf -lSDL_mixer

clean:
	$(RM) $(AI_OBJS) $(SERVER_OBJS) srcs/ai/*~ srcs/server/*~ include/ai/*~ include/server/*~ *~

fclean: clean
	$(RM) $(SERVER) $(AI)

re: fclean all

.PHONY: all clean fclean re
