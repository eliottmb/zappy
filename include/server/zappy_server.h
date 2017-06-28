/*
** zappy_server.h for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 11:58:03 2017 Romain HUET
** Last update Wed Jun 28 19:59:06 2017 Romain HUET
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

void	get_p(t_args *args, char **av);
void	get_x(t_args *args, char **av);
void	get_y(t_args *args, char **av);
void	get_c(t_args *args, char **av);
void	get_f(t_args *args, char **av);

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
  int		nb_players;
}		t_tile;

t_tile	**init_map(int x_size, int y_size, int nb_player_max);
void	show_map(t_tile **map);
int     map_size(int fd, void **map);
int     one_tile_content(int fd, void *tile);
int     many_tile_content(int fd, void **map);


/*
** SERVER
*/

# define MAX_PLAYERS 64


typedef struct	s_team
{
  char		*name;
  int		room_left;
}		t_team;

typedef struct		s_server
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			graph_cli_fd;
  t_tile		**map;
  int			f;
  t_team		*teams;
  int			nb_of_teams;
}			t_server;

int	tablen(char **tab);
int	init_server(t_server *server, t_args *args);
void	init_serv_teams(t_server *server, t_args *args);
int	bind_serv(t_server *server);
int	listen_serv(t_server *server);

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
  /* char		*read_buf; */
  /* char		*write_buf; */
}               t_player;

t_player	*init_players(t_player *players, t_args *args);
int		get_max_fd(t_server *server, t_player *players);
void		fd_setting(fd_set *fd_s, t_player *players);
void		check_readfds(fd_set *readfds, t_server *server, t_player *players);
void		check_writefds(fd_set *writefds, t_server *server, t_player *players);
void		write_data(t_player *players, int src, t_server *server);
void		read_data(t_player *players, int src, t_server *server);
int		new_connection(t_server *server, t_player *players);
void		give_infos_to_gclient(t_server *server);
void		give_team(t_args *args, t_player *players, int i);
int		server_loop(t_server *server, t_player *players);
void		set_graph_cli(t_player *players, t_server *server);
void		welcome_graph_client(t_server *server);
void		message_from_gclient(t_server *server);
void		message_to_gclient(t_server *server);
int		close_all(t_server *server, t_args *args, t_player *players);

/*
** COMMANDS
*/

# define NB_CMDS 10
# define C_TIM1 1
# define C_TIM7 7
# define C_TIM42 42
# define C_TIM300 300

typedef struct	s_func
{
  char		*name;
  int		(*ptrfunc)(void *player, void *server, int i);
}		t_func;

/* extern t_func	*g_cmds; */

int	check_cmd(char *s, t_player *player_src, t_server *server);
char	**get_cmd_args(char *s);
int	is_separator(char c);
int	count_words(char *s);
char	*get_nth_word(char *s, int n);

void	player_forward(void *player, void *server, int no);
void	player_turn_right(void *player, void *server, int no);
void	player_turn_left(void *player, void *server, int no);
void    player_build(void *player, void *server, int no);
void    player_spawn_egg(void *player, void *server, int no);
void	connect_nbr(void *player, void *server, int no);
void	player_look(void *player, void *server, int no);

// OK
int	player_expell(void *player, void *server, int no);
int	player_broadcast(void *player, void *server, char *str, int no);
int	player_begin_incantation(void *player, void *server, int j);
int	player_end_incantation(void *player, void *server, int r);
int	player_take_ress(void *player, void *server, int i);
int	player_drop_ress(void *player, void *server, int i);
int	player_tragically_dies(void *player, void *server, int no);

int     team_name(int fd, void *args);
int     new_player_connection(int fd, void *player);
int     player_position(int fd, void *player);
int     player_level(int fd, void *player);

/* int     player_tragically_die(int fd, void *player); */

int     server_time(int fd, void *args);
int     server_game_win(int fd, void *str);
int     server_message(int fd, void *str);
int     server_unknown_command(int fd, void *str);
int     server_bad_param(int fd, void *str);

#endif /* !SERV_H */
