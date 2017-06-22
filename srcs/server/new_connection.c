/*
** new_connection.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 17:25:45 2017 Romain HUET
** Last update Thu Jun 22 17:26:27 2017 Romain HUET
*/

#include "server/zappy_server.h"

void    give_team(t_args *args, t_player *players, int i)
{
  static int    nb_p_in_team = 0;
  static int    team_num = 0;

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

int     new_connection(t_server *server, t_args *args, t_player *players)
{
  int   i;
  static int    first = 0;

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
