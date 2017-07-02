/*
** timed_cmd_special.c for zappy in /home/mederic.unissart/rendu/zappy/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Sun Jul  2 14:05:11 2017 Médéric Unissart
** Last update Sun Jul  2 23:03:27 2017 Médéric Unissart
*/

#include "zappy_server.h"

int			res_req(int *res, int lvl)
{
  int			i;

  i = 0;
  if (lvl == 1)
    while (i < 7)
      {
	if ((i == 2 && res[i] != 1) ||
	    (i != 2 && res[i] > 0))
	  return (0);
	++i;
      }
  return (1);
}

void			timed_fork(t_server *server,
				   t_player *player,
				   int res)
{
  server = server;
  player = player;
  res = res;
}

void			timed_incantation(t_server *server,
					  t_player *player,
					  int res)
{
  if (player->x + player->y * server->map[0][0].x_max != res &&
      res_req(server->map[player->y][player->x].res, player->lvl) != 1)
    {
      dprintf(player->fd, "ko\n");
      return ;
    }
  if (player->lvl < 8)
    player->lvl += 1;
  dprintf(player->fd, "Current lvl : %d\n", player->lvl);
}

void			timed_broadcast(t_server *server,
					t_player *player,
					int res)
{
  if (player->n == res)
    {
      dprintf(player->fd, "ok\n");
      dprintf(server->graph_cli_fd, "pbc %d %s\n", player->n, player->look);
      free(player->look);
    }
  else
    dprintf(player->fd, "%s", player->look);
}
