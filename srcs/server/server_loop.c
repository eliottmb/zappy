/*
** server_loop.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 17:26:44 2017 Romain HUET
** Last update Sat Jul  1 15:51:07 2017 Romain HUET
*/

#include "zappy_server.h"

void	write_data(t_player *players, int src, t_server *server)
{
  players = players;
  src = src;
  server = server;
}

int		server_loop(t_server *server, t_player *players)
{
  int           max_fd;
  fd_set        readfds;
  fd_set        writefds;
    
  while (42)
    {
      fd_setting(&readfds, players);
      fd_setting(&writefds, players);
      FD_SET(server->fd, &readfds);
      max_fd = get_max_fd(server, players);
      if (select(max_fd + 1, &readfds, &writefds, NULL, NULL) == -1)
	return (-1);
      check_readfds(&readfds, server, players);
      check_writefds(&writefds, server, players);
    }
  return (0);
}

int     close_all(t_server *server, t_player *players)
{
  int   i;

  i = 0;
  if (close(server->fd) == -1)
    return (-1);
  close(server->graph_cli_fd);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != -1)
	close(players[i].fd);
      i++;
    }
  return (0);
}
