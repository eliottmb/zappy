/*
** timed_cmd_move.c for zappy in /home/mederic.unissart/rendu/zappy/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Sun Jul  2 13:42:53 2017 Médéric Unissart
** Last update Sun Jul  2 15:58:17 2017 Médéric Unissart
*/

#include "zappy_server.h"

void		timed_forward(t_server *server,
			      t_player *player,
			      int res)
{
  dprintf(player->fd, "ok\n");
  player_position(server->graph_cli_fd, player);
  res = res;
}

void		timed_right(t_server *server,
			    t_player *player,
			    int res)
{
  dprintf(player->fd, "ok\n");
  player_position(server->graph_cli_fd, player);
  res = res;
}

void		timed_left(t_server *server,
			   t_player *player,
			   int res)
{
  dprintf(player->fd, "ok\n");
  player_position(server->graph_cli_fd, player);
  res = res;
}
