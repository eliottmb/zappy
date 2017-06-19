##
## Makefile for  in /home/romain.huet/rendu/Backup_Zappy
## 
## Made by Romain HUET
## Login   <romain.huet@epitech.net>
## 
## Started on  Mon Jun 19 11:37:44 2017 Romain HUET
## Last update Mon Jun 19 18:16:32 2017 eliott m-barali
##

CC		= gcc

RM		= rm -f

CFLAGS		= -W -Wextra -Wall -I./include/

LDFLAGS_SERV	=

LDFLAGS_AI	=

SERVER		= zappy_server

SERVER_SRCS	= srcs/server/main_serv.c	\
		  srcs/server/map.c

SERVER_OBJS	= $(SERVER_SRCS:.c=.o)

AI		= zappy_ai

AI_SRCS		= srcs/ai/main_ai.c

AI_OBJS		= $(AI_SRCS:.c=.o)

all: $(SERVER) $(AI)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJS) 

$(AI): $(AI_OBJS)
	$(CC) $(CFLAGS) -o $(AI) $(AI_OBJS)

clean:
	$(RM) $(AI_OBJS) $(SERVER_OBJS) srcs/ai/*~ srcs/server/*~ include/ai/*~ include/server/*~ *~

fclean: clean
	$(RM) $(SERVER) $(AI)

re: fclean all

.PHONY: all clean fclean re
