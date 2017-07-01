/*
** gclient_talking.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Wed Jun 28 12:41:43 2017 Romain HUET
** Last update Sat Jul  1 16:15:14 2017 Romain HUET
*/

#include "zappy_server.h"

void    give_infos_to_gclient(t_server *server)
{
  map_size(server->graph_cli_fd, (void **)server->map);
  server_time(server->graph_cli_fd, server);
  many_tile_content(server->graph_cli_fd, (void **)server->map);
  team_name(server->graph_cli_fd, server);
}

void    set_graph_cli(t_player *player, t_server *server)
{
  if (server->graph_cli_fd == -1)
    {
      server->graph_cli_fd = player->fd;
      player->fd = -1;
      give_infos_to_gclient(server);
    }
  else
    dprintf(player->fd, "ko\n");
}
