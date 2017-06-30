/*
** team_manager.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 29 18:19:44 2017 Romain HUET
** Last update Fri Jun 30 17:08:21 2017 Romain HUET
*/

#include "zappy_server.h"


int	is_team(char *s, t_server *server)
{
  char	buf[32];
  int	i;

  i = 0;
  while (s[i] && s[i] != '\n')
    {
      buf[i] = s[i];
      i++;
    }
  i = 0;
  while (i < server->nb_of_teams)
    {
      if (!strcmp(buf, server->teams[i].name))
	return (1);
      i++;
    }
  return (0);
}

void	affect_team(char *buf, t_player *player, t_server *server)
{
  int	i;
  int	ok;

  i = strlen(buf);
  ok = 0;
  if (i)
    buf[i - 1] = '\0';
  i = 0;
  while (server->teams[i].name)
    {
      if (!strcmp(buf, server->teams[i].name) && server->teams[i].room_left >= 1
	  && player->team == NULL)
	{
	  player->team = strdup(buf);
	  server->teams[i].room_left--;
	  dprintf(player->fd, "%d\n", server->teams[i].room_left);
	  dprintf(player->fd, "%d %d\n", server->map[0][0].x_max, server->map[0][0].y_max);
	  server->map[player->y][player->x].nb_players++;
	  new_player_connection(server->graph_cli_fd, player);
	  ok = 1;
	}
      i++;
    }
  if (!ok)
    dprintf(player->fd, "ko\n");
}
