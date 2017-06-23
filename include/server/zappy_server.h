/*
** zappy_server.h for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 11:58:03 2017 Romain HUET
** Last update Fri Jun 23 17:43:57 2017 Romain HUET
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
** MAP
*/

# define LIN_RATE 0.23
# define DER_RATE 0.20
# define SIB_RATE 0.26
# define MEN_RATE 0.13
# define PHI_RATE 0.15
# define THY_RATE 0.03

typedef struct	s_tile
{
  int		x_max;
  int		y_max;
  int		x;
  int		y;
  int		res[7];
}		t_tile;

t_tile	**init_map(int x_size, int y_size, int nb_player_max);
void	show_map(t_tile **map);

/*
** PLAYERS
*/

# define STARTING_FOOD 10
# define INVENTORY_SIZE 7
# define STARTING_LIFE 1260

typedef enum	s_dir
  {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
  }		e_dir;

typedef struct  s_player
{
  int		fd;
  int           x;
  int           y;
  int           life;
  e_dir		o;
  int           n;
  int           *i;
  char          *team;
  int           lvl;
  bool          incantating;
  bool          broadcasting;
}               t_player;

t_player	*init_players(t_player *players, t_args *args);
int		fd_setting(fd_set *readfds, t_server *server, t_args *args, t_player *players);
int		new_connection(t_server *server, t_args *args, t_player *players);
void		give_team(t_args *args, t_player *players, int i);
int		server_loop(t_args *args, t_server *server, t_player *players, t_tile **map);
void		read_data(t_player *players, int src, t_server *server, t_tile **map);
int		close_all(t_server *server, t_args *args, t_player *players);

/*
** COMMANDS
*/

# define NB_CMDS 12

typedef struct	s_func
{
  char		*name;
  void		(*ptrfunc)(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
}		t_func;

/* extern t_func	*g_cmds; */

int	check_cmd(char *s, t_player *player_src, t_server *server, t_tile **map);
char	**get_cmd_args(char *s);
int	is_separator(char c);
int	count_words(char *s);
char	*get_nth_word(char *s, int n);

void	forward(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	right(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	left(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	look(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	inventory(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	broadcast(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	connect_nbr(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	eggfork(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	eject(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	take_object(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	set_object(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);
void	start_incantation(t_player *player_src, char **cmd_args, t_server *server, t_tile **map);


/* Forward --> ok */
/* Right -->   ok */
/* Left -->    ok */
/* Look -->    char *[de la mort] */
/* Inventory --> char *[moins de la mort] */
/* Broadcast text --> ok */
/* Connect_nbr --> int nb de slot libres dans l'équipe du player src */
/* Fork --> ok */
/* Eject --> ok/ko */
/* rien --> dead */
/* Take object --> ok/ko */
/* Set object  --> ok/ko */
/* incantation --> elevation underway current level : k / ko */

#endif /* !SERV_H */
