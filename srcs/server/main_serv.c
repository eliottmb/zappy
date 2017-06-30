/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Fri Jun 30 19:56:30 2017 Romain HUET
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

int     res_to_int(char *ress)
{
  int	i;
  char	*res[7];

  printf("ress dans restoint = %s\n", ress);
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
  return (-1);
}

int	check_cmd(char *s, t_player *player_src, t_server *server)
{
  char	*cmd;
  char	**cmds;
  int	i;
  int	id;
  char	*res;
  int	ok;

  i = 0;
  id = 0;
  ok = 0;
  cmd = NULL;
  printf("dans check cmd : s = %s\n", s);
  if ((player_src->team == NULL && strcmp(s, "GRAPHIC\n")) ||
      (!strcmp(s, "GRAPHIC\n") && server->graph_cli_fd != -1
       && !is_team(s, server)))
    {
      printf("on renvoie ko\n");
      dprintf(player_src->fd, "ko\n");
      return (0);
    }

  printf("%d mots dans la commande\n", count_words(s));
  
  if ((!strcmp(get_nth_word(s, 1), "Take") ||
       !strcmp(get_nth_word(s, 1), "Set")) && count_words(s) == 2)
    {
      printf("piege 1\n");
      res = strdup(get_nth_word(s, 2));
      if ((id = res_to_int(res)) == -1)
	{
	  dprintf(player_src->fd, "ko\n");
	  return (0);
	}
    }
  
  if ((cmds = cut_cmd(s)) == NULL)
    {
      printf("cut_cmd renvoie NULL\n");
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
    }
  else
    {
      int	j = 0;
      printf("cut_cmd a pas renvoyé NULL :)\n");
      while (cmds[j])
	{
	  i = 0;
	  printf("cmds[j] = %s\n", cmds[j]);
	  if (!strcmp(get_nth_word(cmds[j], 1), "Take") ||
	      !strcmp(get_nth_word(cmds[j], 1), "Set"))
	    {
	      res = strdup(get_nth_word(cmds[j], 2));
	      printf("cmd TAKE or SET detected, id = %d\n", id);
	      if ((id = res_to_int(res)) == -1)
		{
		  dprintf(player_src->fd, "ko\n");
		  return (0);
		}
	    }
	  while (i < NB_CMDS)
	    {
	      printf("on boucle sur le tableau de sous commandes\n");
	      if (!strcmp(cmds[j], g_cmds[i].name))
		{
		  g_cmds[i].ptrfunc(player_src, server, id);
		  ok = 1;
		}
	      i++;
	    }
	  j++;
	}
      if (ok)
	return (1);
    }
  return (0);
}

void	dc_player(t_player *player, t_server *server)
{
  player->fd = -1;
  server->map[player->y][player->x].nb_players--;
  dprintf(server->graph_cli_fd, "pdi %d\n", player->n);
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
      dc_player(&players[src], server);
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
