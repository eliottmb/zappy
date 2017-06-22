/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Thu Jun 22 15:31:37 2017 Romain HUET
*/

#include "server/zappy_server.h"

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

int     fd_setting(fd_set *readfds, t_server *server, t_args *args, t_players *players)
{
  int   i;
  int   max_fd;

  i = 0;
  max_fd = server->fd;
  FD_SET(server->fd, readfds);
  while (i < args->max_players)
    {
      FD_SET(players[i].fd, readfds);
      if (max_fd < players[i].fd)
	max_fd = players[i].fd;
      i++;
    }
  return (max_fd);
}

void	give_team(t_args *args, t_players *players, int i)
{
  static int	nb_p_in_team = 0;
  static int	team_num = 0;

  if (nb_p_in_team < args->c_per_team)
    {
      players[i].team = strdup(args->names[team_num]);
      nb_p_in_team++;
    }
  else if (nb_p_in_team == args->c_per_team && team_num < args->nb_of_teams)
    {
      nb_p_in_team = 0;
      team_num++;
      new_connection(server, args);
    }
}

int	new_connection(t_server *server, t_args *args, t_players *players)
{
  int	i;

  i = 0;
  while (players[i].fd == -1)
    i++;
  if ((players[i].fd = accept(server->fd, (struct sockaddr *)&(server->s_in_client), &(server->s_in_size))) == -1)
    return (-1);
  if (i < args->max_players)
    give_team(args, players, i);
  else
    {
      dprintf(players[i].fd, "Sorry, no more room for players\n");
      players[i].fd = -1;
    }
  return (0);
}

int	server_loop(t_args *args, t_server *server, t_players *players)
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
      //max_fd = fd_setting(&readfds, server, args, players);
      break ;
    }
  return (0);
}

void	init_players(t_player **players, t_args *args)
{
  int	i;
  int	max_players;

  i = 0;
  *players = NULL;
  while (!*players)
    *players = malloc(sizeof(t_player) * args->max_players);
  while (i < args->max_players)
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
      players[i]->inventory[0] = STARTING_FOOD;
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
  else if (server_loop(&args, &server, players) == -1)
    {
      free_args(&args);
      return (-1);
    }
  free_args(&args);
  return (0);
}
