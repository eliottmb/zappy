/*
** timed_cmd_res.c for zappy in /home/mederic.unissart/rendu/zappy/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Sun Jul  2 14:03:26 2017 Médéric Unissart
** Last update Sun Jul  2 16:25:30 2017 Médéric Unissart
*/

#include "zappy_server.h"

void		timed_take(t_server *server,
			   t_player *player,
			   int res)
{
  if (res == -1)
    {
      dprintf(player->fd, "ko\n");
      return ;
    }
  dprintf(player->fd, "ok\n");
  dprintf(server->graph_cli_fd, "pgt %d %d\n", player->n, res);
  player_build(player, server);
  one_tile_content(server->graph_cli_fd, &server->map[player->y][player->x]);
}

void		timed_set(t_server *server,
			  t_player *player,
			  int res)
{
  if (res == -1)
    {
      dprintf(player->fd, "ko\n");
      return ;
    }
  dprintf(player->fd, "ok\n");
  dprintf(server->graph_cli_fd, "pdr %d %d\n", player->n, res);
  player_build(player, server);
  one_tile_content(server->graph_cli_fd, &server->map[player->y][player->x]);  
}

void		timed_inventory(t_server *server,
				t_player *p,
				int res)
{
  server = server;
  res = res;
  dprintf(p->fd, "[ food %d, linemate %d, deraumere %d, sibur %d,"
	  " mendiane %d, phiras %d, thystame %d ]\n", p->i[0], p->i[1],
	  p->i[2], p->i[3], p->i[4], p->i[5], p->i[6]);
}

void		timed_look(t_server *server,
			   t_player *player,
			   int res)
{
  res = res;
  server = server;
  dprintf(player->fd, "%s", player->look);
  free(player->look);
}
