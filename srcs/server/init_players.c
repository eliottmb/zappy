/*
** init_players.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 17:27:58 2017 Romain HUET
** Last update Fri Jun 23 17:43:19 2017 Romain HUET
*/

#include "server/zappy_server.h"

t_player        *init_players(t_player *players, t_args *args)
{
  int           i;

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
      players[i].o = rand() % 4;
      players[i].n = i;
      players[i].i = NULL;
      while (!players[i].i)
	        players[i].i =
		  calloc(INVENTORY_SIZE, sizeof(int));
      players[i].i[0] = STARTING_FOOD;
      players[i].team = NULL;
      players[i].lvl = 1;
      players[i].incantating = false;
      players[i].broadcasting = false;
      i++;
    }
  return (players);
}

