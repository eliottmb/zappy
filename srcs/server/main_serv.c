/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Fri Jun 30 16:48:53 2017 Romain HUET
*/

#include "zappy_server.h"

t_func	g_cmds[NB_CMDS] =
  {
    {"Forward", &player_forward},
    {"Right", &player_turn_right},
    {"Left", &player_turn_left},
    {"Look", &player_look},
    {"Inventory", &player_inventory},
    {"Connect_nbr", &connect_nbr},
    {"Fork", &player_spawn_egg},
    {"Eject", &player_expell},
    {"Take", &player_take_ress},
    {"Set", &player_drop_ress},
  };

int	check_cmd(char *s, t_player *player_src, t_server *server)
{
  char	*cmd;
  int	i;
  int	id;

  i = 0;
  id = 0;
  cmd = NULL;
  printf("dans check cmd : s = %s\n", s);
  if ((player_src->team == NULL && strcmp(s, "GRAPHIC\n")) ||
      (!strcmp(s, "GRAPHIC\n") && server->graph_cli_fd != -1))
    {
      dprintf(player_src->fd, "ko\n");
      return (0);
    }
  if (!strcmp(get_nth_word(s, 1), "Take") ||
      !strcmp(get_nth_word(s, 1), "Set"))
    id = atoi(get_nth_word(s, 2));
  cmd = strdup(get_nth_word(s, 1));
  while (i < NB_CMDS)
    {
      if (!strcmp(cmd, g_cmds[i].name))
	{
	  g_cmds[i].ptrfunc(player_src, server, id);
	  return (1);
	}
      i++;
    }
  return (0);
}

void	dc_player(t_player *player)
{
  player->fd = -1;
  free(player->i);
  free(player->team);
}

void	read_data(t_player *players, int src, t_server *server)
{
  char		*buf;
  int		read_ret;

  if ((buf = calloc(512, 1)) == NULL)
    {
      dprintf(players[src].fd, "ko\n");
      return ;
    }
  read_ret = read(players[src].fd, buf, 512);
  if (read_ret <= 0)
    {
      free(buf);
      dc_player(&players[src]);
      return ;
    }
  printf("dans read data : %s\n", buf);
  if (strcmp(buf, "GRAPHIC\n") == 0 && server->graph_cli_fd == -1 && players[src].team == NULL)
    set_graph_cli(&players[src], server);
  else if (is_team(buf, server))
    affect_team(buf, &players[src], server);
  else
    {
      if (!check_cmd(buf, &players[src], server))
	dprintf(players[src].fd, "suc\n");
    }
  free(buf);
}

int	main(int ac, char **av)
{
  t_args	args;
  t_server	server;
  t_player	*players;

  players = NULL;
  srand(time(NULL));
  check_help(ac, av);
  check_args(&args, av);
  players = init_players(players, &args);
  if (init_server(&server, &args) == -1)
    {
      printf("[ERROR] : init_server : failed\n");
      return (-1);
    }
  else if (server_loop(&server, players) == -1)
    {
      free_args(&args);
      return (-1);
    }
  free_args(&args);
  close_all(&server, &args, players);
  return (0);
}
