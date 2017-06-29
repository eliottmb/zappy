/*
** gclient_talking.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Wed Jun 28 12:41:43 2017 Romain HUET
** Last update Thu Jun 29 16:49:34 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

void	message_to_gclient(t_server *server)
{
  printf("dans msg_to_gclient\n");
  server = server;
}

void    give_infos_to_gclient(t_server *server)
{
  map_size(server->graph_cli_fd, (void **)server->map);
  server_time(server->graph_cli_fd, server);
  many_tile_content(server->graph_cli_fd, (void **)server->map);
  team_name(server->graph_cli_fd, server);
}

void    message_from_gclient(t_server *server)
{
  char  *gc_ans;

  gc_ans = calloc(16, 1);
  if (read(server->graph_cli_fd, gc_ans, strlen(gc_ans)) >= 0)
    printf("gclient says : %s\n", gc_ans);
}

void    set_graph_cli(t_player *player, t_server *server)
{
  printf("on est dans set_graph_cli\n");
  if (server->graph_cli_fd == -1)
    {
      printf("setting graph cli :)\n");
      server->graph_cli_fd = player->fd;
      player->fd = -1;
      give_infos_to_gclient(server);
    }
  else
    dprintf(player->fd, "ko\n");
}
