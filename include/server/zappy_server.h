/*
** zappy_server.h for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 11:58:03 2017 Romain HUET
** Last update Thu Jun 22 17:06:46 2017 Romain HUET
*/

#ifndef SERV_H
# define SERV_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>

/*
** ARGUMENTS
*/

typedef struct	s_args
{
  int		port;
  int		width;
  int		height;
  int		nb_of_teams;
  char		**names;
  int		c_per_team;
  int		f;
  int		max_players;
}		t_args;

int	is_num(char *s);
void	aff_args(t_args *args);
void	check_help(int ac, char **av);
void	check_args(t_args *args, char **av);
void	help_server();
int	init_args(t_args *args);
int	get_args(t_args *args, char **av);
void	aff_args(t_args *args);
int	count_teams(char **av);
int	check_doublons(char **names);
void	free_args(t_args *args);

/*
** SERVER
*/

typedef struct		s_server
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			graph_cli_fd;
}			t_server;

int	tablen(char **tab);
int	init_server(t_server *server, t_args *args);
int	bind_serv(t_server *server);
int	listen_serv(t_server *server, t_args * args);

/*
** PLAYERS
*/

# define STARTING_FOOD 10
# define INVENTORY_SIZE 7
# define STARTING_LIFE 1260

typedef struct  s_player
{
  int		fd;
  int           x;
  int           y;
  int           life;
  int           direction;
  int           id;
  int           *inventory;
  char          *team;
  int           lvl;
  bool          incantating;
  bool          broadcasting;
}               t_player;

/*
** COMMANDS
*/

typedef struct	s_func
{
  char		*name;
  void		(*ptrfunc)();
}		t_func;

#endif /* !SERV_H */
