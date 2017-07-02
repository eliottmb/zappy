/*
** new_connection.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 17:25:45 2017 Romain HUET
** Last update Sun Jul  2 19:48:12 2017 Romain HUET
*/

#include "zappy_server.h"

int		new_connection(t_server *server, t_player *players)
{
  int			i;
  int			incoming_fd;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;

  i = 0;
  incoming_fd = 0;
  s_in_client = server->s_in_client;
  s_in_size = server->s_in_size;
  while (i < MAX_PLAYERS && players[i].fd != -1)
    i++;
  if (i < MAX_PLAYERS)
    {
      if ((incoming_fd = accept(server->fd, (struct sockaddr *)&s_in_client, &s_in_size)) == -1)
	dprintf(2, "[ERROR] : accept\n");
      else
	{
	  dprintf(incoming_fd, "WELCOME\n");
	  players[i].fd = incoming_fd;
	}
    }
  return (0);
}
