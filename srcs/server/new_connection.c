/*
** new_connection.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 17:25:45 2017 Romain HUET
** Last update Mon Jun 26 15:27:06 2017 Romain HUET
*/

#include "server/zappy_server.h"

void    give_team(t_args *args, t_player *players, int i)
{
  static int    nb_p_in_team = 0;
  static int    team_num = 0;

  if (nb_p_in_team < args->c_per_team)
    {
      players[i].team = strdup(args->names[team_num]);
      nb_p_in_team++;
    }
  else if (nb_p_in_team == args->c_per_team && team_num < args->nb_of_teams)
    {
      nb_p_in_team = 0;
      team_num++;
      give_team(args, players, i);
    }
}

void	give_infos_to_gclient(t_server *server, t_args *args, t_tile **map)
{
  map_size(server->graph_cli_fd, (void **)map);
  server_time(server->graph_cli_fd, args);
  many_tile_content(server->graph_cli_fd, (void **)map);
  team_name(server->graph_cli_fd, args);
}

void	message_from_gclient(t_server *server, t_args *args)
{
  char	*gc_ans;
  
  gc_ans = calloc(16, 1);
  read(server->graph_cli_fd, gc_ans, strlen(gc_ans));
  printf("|%s|\n", gc_ans);
  if (!strcmp(gc_ans, "GRAPHIC\n"))
    give_infos_to_gclient(server, args, server->map);  
}

int		new_connection(t_server *server, t_player *players)
{
  int		i;
  int		incoming_fd;

  i = 0;
  incoming_fd = 0;
  printf("on est dans new_connexion\n");
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != -1)
	{
	  if ((incoming_fd = accept(server->fd, (struct sockaddr *)&(server->s_in_client), &(server->s_in_size))) == -1)
	    printf("error : accept failed\n");
	  dprintf(incoming_fd, "WELCOME\n");
	}
      i++;
    }
  return (0);
}
