/*
** server_loop.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 17:26:44 2017 Romain HUET
** Last update Mon Jun 26 15:40:01 2017 Romain HUET
*/

#include "server/zappy_server.h"

int	get_max_fd(t_server *server, t_player *players)
{
  int   max_fd;
  int	i;

  i = 0;
  max_fd = server->fd;
  while (i < MAX_PLAYERS)
    {
      if (max_fd < players[i].fd)
	max_fd = players[i].fd;
      i++;
    }
  if (max_fd < server->graph_cli_fd)
    max_fd = server->graph_cli_fd;
  return (max_fd);
}

void     fd_setting(fd_set *fd_s, t_server *server, t_player *players)
{
  int   i;

  i = 0;
  FD_SET(server->fd, fd_s);
  if (server->graph_cli_fd != -1)
    FD_SET(server->graph_cli_fd, fd_s);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != -1)
	FD_SET(players[i].fd, fd_s);
      i++;
    }
}

void	check_readfds(fd_set *readfds, t_server *server, t_player *players, t_args *args)
{
  int	i;

  i = 0;
  if (FD_ISSET(server->fd, readfds))
    new_connection(server, players);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != - 1 && FD_ISSET(players[i].fd, readfds))
	read_data(players, i, server);
      i++;
    }
}

//// A BOUGER ///

void	message_to_gclient(t_server *server, t_args *args)
{
  server = server;
  args = args;
}

void	write_data(t_player *players, int src, t_server *server)
{
  players = players;
  src = src;
  server = server;
}

////////

void	check_writefds(fd_set *writefds, t_server *server, t_player *players, t_args *args)
{
  int	i;

  i = 0;
  if (FD_ISSET(server->graph_cli_fd, writefds))
    message_to_gclient(server, args);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != -1 && FD_ISSET(players[i].fd, writefds))
	write_data(players, i, server);
      i++;
    }
}

int		server_loop(t_args *args, t_server *server, t_player *players)
{
  int           max_fd;
  fd_set        readfds;
  fd_set        writefds;
  
  FD_ZERO(&readfds);
  FD_ZERO(&writefds);
  while (42)
    {
      fd_setting(&readfds, server, players);
      fd_setting(&writefds, server, players);
      max_fd = get_max_fd(server, players);
      if (select(max_fd + 1, &readfds, NULL, NULL, NULL) == -1)
	return (-1);
      check_readfds(&readfds, server, players, args);
      check_writefds(&writefds, server, players, args);
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
