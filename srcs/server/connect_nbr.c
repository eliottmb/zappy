/*
** client_commands.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Fri Jun 23 17:46:38 2017 Romain HUET
** Last update Thu Jun 29 17:14:25 2017 Romain HUET
*/

#include "zappy_server.h"

void	connect_nbr(void *player, void *server, int no)
{
  t_player	*p;
  t_server	*serv;
  int		i;

  i = 0;
  no = no;
  p = (t_player *)player;
  serv = (t_server *)server;
  while (i < serv->nb_of_teams && strcmp(serv->teams[i].name, p->team))
    i++;
  dprintf(p->fd, "%d\n", serv->teams[i].room_left);
}
