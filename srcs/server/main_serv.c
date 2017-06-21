/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Wed Jun 21 19:26:38 2017 Romain HUET
*/

#include "server/zappy_server.h"

//////////  A  VIRER /////////////
//////////////////////////////////
void	aff_args(t_args *args)
{
  int	i;

  i = 0;
  printf("port = %d\n", args->port);
  printf("map width = %d\n", args->width);
  printf("map height = %d\n", args->height);
  printf("there are %d teams\n", args->nb_of_teams);
  printf("their names are :\n");
  if (args->nb_of_teams != 0)
    {
      while (args->names[i])
	{
	  printf("%s\n", args->names[i]);
	  i++;
	}
    }
  printf("each teams has %d players\n", args->c_per_team);
  printf("reciprocal of time unit is %d\n", args->f);
}
//////////////////////////////

int     find_max(int max_fd, t_server *server)
{
  return (max_fd > server->fd ? max_fd + 1 : server->fd + 1);
}

int     fd_setting(fd_set *readfds, t_server *server)
{
  //int   i;
  int   max_fd;

  //  i = 0;
  max_fd = 0;
  FD_SET(server->fd, readfds);

  return (max_fd);
}

int	new_connection()
{
  return (0);
}

int	server_loop(t_args *args, t_server *server)
{
  printf("let's work !\n");
  args = args;
  server = server;
  //  int		i;
  //  int		max_fd;
  fd_set	readfds;

  FD_ZERO(&readfds);
  while (42)
    {
      //i = 0;
      //max_fd = fd_setting(&readfds, server);
      break ;
    }
  return (0);
}

void	init_players(t_player **players, t_args *args)
{
  int	i;
  int	max_players;

  i = 0;
  max_players = args->c_per_team * args->nb_of_teams;
  players = NULL;
  while (!players)
    players = malloc(sizeof(t_player) * max_players);
  while (i < max_players)
    {
      players[i]->fd = -1;
      players[i]->x = rand() % args->width;
      players[i]->y = rand() % args->height;
      players[i]->life = STARTING_LIFE;
      players[i]->direction = rand() % 4;
      players[i]->id = i;
      players[i]->inventory = NULL;
      while (!players[i]->inventory)
	players[i]->inventory =
	  calloc(INVENTORY_SIZE, sizeof(int));
      players[i]->team = NULL;
      players[i]->lvl = 1;
      players[i]->incantating = false;
      players[i]->broadcasting = false;
      i++;      
    }
}

int	main(int ac, char **av)
{
  t_args	args;
  t_server	server;
  t_player	*players;

  srand(time(NULL));
  check_help(ac, av);
  check_args(&args, av);
  init_players(&players, &args);
  if (init_server(&server, &args) == -1)
    {
      printf("problem in init server\n");
      return (-1);
    }
  else if (server_loop(&args, &server) == -1)
    {
      free_args(&args);
      return (-1);
    }
  free_args(&args);
  return (0);
}
