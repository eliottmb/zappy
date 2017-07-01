/*
** cmds_manager.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Sat Jul  1 13:56:15 2017 Romain HUET
** Last update Sat Jul  1 18:38:55 2017 Romain HUET
*/

#include "zappy_server.h"

int     res_to_int(char *ress, t_player *player_src)
{
  int	i;
  char	*res[7];

  i = 0;
  res[0] = "food";
  res[1] = "linemate";
  res[2] = "deraumere";
  res[3] = "sibur";
  res[4] = "mendiane";
  res[5] = "phiras";
  res[6] = "thystame";
  while (i < 7)
    {
      if (!strcmp(ress, res[i]))
	return (i);
      i++;
    }
  dprintf(player_src->fd, "ko\n");
  return (-1);
}

void	check_for_incantation(char *cmd, t_server *server, t_player *players, t_player *player_src)
{
  char	*msg;
  char	*plist;
  int	i;

  i = 0;
  if (strcmp(get_nth_word(cmd, 1), "Incantation")
      || (msg = calloc(128, 1)) == NULL
      || (plist = calloc(128, 1)) == NULL)
    return ;
  sprintf(msg, "pic %d %d %d", player_src->x, player_src->y, player_src->n);
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd != -1 &&
	  players[i].x == player_src->x &&
	  players[i].y == player_src->y)
	{
	  sprintf(plist, " %d", players[i].n);
	  strcat(msg, plist);
	}
      i++;
    }
  strcat(msg, "\n\0");
  dprintf(server->graph_cli_fd, "%s", msg);
  dprintf(player_src->fd, "ok\n");
  printf("%s", msg);
}

int	check_cmd(char *s, t_player *player_src, t_server *server, t_player *players)
{
  char	**cmds;
  int	j;
  int	id;
  char	*res;

  j = 0;
  if ((cmds = my_strtowordtab(s, '\n')) == NULL)
    return (-1);
  while (cmds[j])
    {
      check_for_incantation(cmds[j], server, players, player_src);
      if (!strcmp(get_nth_word(cmds[j], 1), "Take") ||
	  !strcmp(get_nth_word(cmds[j], 1), "Set"))
	{
	  res = strdup(get_nth_word(cmds[j], 2));
	  if ((id = res_to_int(res, player_src)) == -1)
	    return (1);
	}
      if (strcmp(get_nth_word(cmds[j], 1), "Broadcast"))
        run_cmd(cmds[j], player_src, server, id);
      else 
	player_broadcast(players, server, cmds[j], player_src->n);
      j++;
    }
  return (1);
}
