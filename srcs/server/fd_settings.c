/*
** fd_settings.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Wed Jun 28 12:35:36 2017 Romain HUET
** Last update Thu Jun 29 17:14:40 2017 Romain HUET
*/

#include "zappy_server.h"

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

void     fd_setting(fd_set *fd_s, t_player *players)
{
  int   i;

  i = 0;
  FD_ZERO(fd_s);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != -1)
	FD_SET(players[i].fd, fd_s);
      i++;
    }
}
