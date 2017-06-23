/*
** server_loop.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 17:26:44 2017 Romain HUET
** Last update Fri Jun 23 18:49:33 2017 Romain HUET
*/

#include "server/zappy_server.h"

int     fd_setting(fd_set *readfds, t_server *server, t_args *args, t_player *players)
{
  int   i;
  int   max_fd;

  i = 0;
  max_fd = server->fd;
  FD_SET(server->fd, readfds);
  FD_SET(server->graph_cli_fd, readfds);
  while (i < args->max_players)
    {
      FD_SET(players[i].fd, readfds);
      if (max_fd < players[i].fd)
	max_fd = players[i].fd;
      i++;
    }
  return (max_fd);
}

int     server_loop(t_args *args, t_server *server, t_player *players, t_tile **map)
{
  int           i;
  int           max_fd;
  fd_set        readfds;
  fd_set        writefds;

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
      else if (FD_ISSET(server->graph_cli_fd, &readfds))
	message_from_gclient(server, args, map);
      while (i < args->max_players)
	{
	  if (players[i].fd != - 1 && FD_ISSET(players[i].fd, &readfds))
	    read_data(players, i, server, map);
	  i++;
	}
    }
  return (0);
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
