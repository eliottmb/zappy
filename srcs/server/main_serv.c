/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Sat Jul  1 13:59:37 2017 Romain HUET
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
    /* {"Incantation", } */
  };

int	run_cmd(char *curr_cmd, t_player *player_src, t_server *server, int id)
{
  int	i;
  int	ok;

  i = 0;
  ok = 0;
  while (i < NB_CMDS)
    {
      if (!strcmp(get_nth_word(curr_cmd, 1), g_cmds[i].name))
	{
	  g_cmds[i].ptrfunc(player_src, server, id);
	  ok = 1;
	}
      i++;
    }
  return (ok);
}

void	dc_player(t_player *player, t_server *server)
{
  close(player->fd);
  player->fd = -1;
  server->map[player->y][player->x].nb_players--;
  player_tragically_dies(server->graph_cli_fd, player);
}

void	read_data(t_player *players, int src, t_server *server)
{
  char		*buf;

  if ((buf = calloc(512, 1)) == NULL)
    {
      dprintf(players[src].fd, "ko\n");
      return ;
    }
  if (read(players[src].fd, buf, 512) < 0)
    {
      printf("on déco le joueur\n");
      dc_player(&players[src], server);
      return ;
    }
  if (!strcmp(buf, "GRAPHIC\n") &&
      server->graph_cli_fd == -1 && players[src].team == NULL)
    set_graph_cli(&players[src], server);
  else if (is_team(buf, server))
    affect_team(buf, &players[src], server);
  else
    {
      if (!strcmp(buf, "GRAPHIC\n") && server->graph_cli_fd != -1)
	dprintf(players[src].fd, "ko\n");
      else if (!check_cmd(buf, &players[src], server, players))
	dprintf(players[src].fd, "suc\n");
    }
}

int	main(int ac, char **av)
{
  t_args	args;
  t_server	server;
  t_player	*players;

  players = NULL;
  srand(time(NULL));
  if (init_sigact() == false)
    return (-1);
  check_help(ac, av);
  check_args(&args, av);
  players = init_players(players, &args);
  if (init_server(&server, &args) == -1)
    {
      printf("[ERROR] : init_server : failed\n");
      return (-1);
    }
  
  if (server_loop(&server, players) == -1)
    {
      free_args(&args);
      return (-1);
    }
  free_args(&args);
  close_all(&server, &args, players);
  return (0);
}
