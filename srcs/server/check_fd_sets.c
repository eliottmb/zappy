/*
** check_fd_sets.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Wed Jun 28 12:40:32 2017 Romain HUET
** Last update Thu Jun 29 17:14:05 2017 Romain HUET
*/

#include "zappy_server.h"

void	check_writefds(fd_set *writefds, t_server *server, t_player *players)
{
  int	i;

  i = 0;
  if (FD_ISSET(server->graph_cli_fd, writefds))
    message_to_gclient(server);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != -1 && FD_ISSET(players[i].fd, writefds))
	write_data(players, i, server);
      i++;
    }
}

void	check_readfds(fd_set *readfds, t_server *server, t_player *players)
{
  int	i;

  i = 0;
  if (FD_ISSET(server->fd, readfds))
    new_connection(server, players);
  else if (FD_ISSET(server->graph_cli_fd, readfds))
    message_from_gclient(server);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != - 1 && FD_ISSET(players[i].fd, readfds))
	read_data(players, i, server);
      i++;
    }
}
