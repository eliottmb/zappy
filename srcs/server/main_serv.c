/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Thu Jun 22 17:11:41 2017 Romain HUET
*/

#include "server/zappy_server.h"

void	give_team(t_args *args, t_player *players, int i)
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
      give_team(args, players, i);
    }
}

int	new_connection(t_server *server, t_args *args, t_player *players)
{
  int	i;
  static int	first = 0;

  i = 0;
  printf("on est dans new_connexion\n");
  while (players[i].fd != -1)
    i++;
  printf("i = %d\n", i);
  if (!first)
    {
      printf("first connection detected\n");
      if ((server->graph_cli_fd = accept(server->fd, (struct sockaddr *)&(server->s_in_client), &(server->s_in_size))) == -1)
	return (-1);      
      first++;
      dprintf(server->graph_cli_fd, "BIENVENUE\n");
      /////CLIENT GRAPHIQUE
    }
  else
    {
      ///// CLIENTS IA
      if ((players[i].fd = accept(server->fd, (struct sockaddr *)&(server->s_in_client), &(server->s_in_size))) == -1)
	return (-1);
      if (i < args->max_players)
	{
	  give_team(args, players, i);
	  dprintf(players[i].fd, "Bienvenue sur le ZAPPY !\n");
	}
      else
	{
	  dprintf(players[i].fd, "Sorry, no more room for players\n");
	  players[i].fd = -1;
	}
    }
  return (0);
}

int     fd_setting(fd_set *readfds, t_server *server, t_args *args, t_player *players)
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

int	server_loop(t_args *args, t_server *server, t_player *players)
{
  int		i;
  int		max_fd;
  fd_set	readfds;
  fd_set	writefds;

  printf("On est dans server loop\n");
  FD_ZERO(&readfds);
  FD_ZERO(&writefds);
  while (42)
    {
      i = 0;
      max_fd = fd_setting(&readfds, server, args, players);
      printf("avant le select\n");
      if (select(max_fd + 1, &readfds, NULL, NULL, NULL) == -1)
	return (-1);
      if (FD_ISSET(server->fd, &readfds))
	new_connection(server, args, players);
      while (i < args->max_players)
	{
	  if (players[i].fd != - 1 && FD_ISSET(players[i].fd, &readfds))
	    printf("got message from a client\n");
	  i++;
	}
    }
  return (0);
}

t_player	*init_players(t_player *players, t_args *args)
{
  int		i;

  i = 0;
  players = NULL;
  while (!players)
    players = malloc(sizeof(t_player) * args->max_players);
  while (i < args->max_players)
    {
      players[i].fd = -1;
      players[i].x = rand() % args->width;
      players[i].y = rand() % args->height;
      players[i].life = STARTING_LIFE;
      players[i].direction = rand() % 4;
      players[i].id = i;
      players[i].inventory = NULL;
      while (!players[i].inventory)
	players[i].inventory =
	  calloc(INVENTORY_SIZE, sizeof(int));
      players[i].inventory[0] = STARTING_FOOD;
      players[i].team = NULL;
      players[i].lvl = 1;
      players[i].incantating = false;
      players[i].broadcasting = false;
      i++;      
    }
  return (players);
}

int     close_all(t_server *server, t_args *args, t_player *players)
{
  int   i;

  i = 0;
  if (close(server->fd) == -1)
    return (-1);
  while (i < args->max_players)
    {
      if (close(players[i].fd) == -1)
	return (-1);
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_args	args;
  t_server	server;
  t_player	*players;

  players = NULL;
  srand(time(NULL));
  check_help(ac, av);
  check_args(&args, av);
  players = init_players(players, &args);
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
  close_all(&server, &args, players);
  return (0);
}
