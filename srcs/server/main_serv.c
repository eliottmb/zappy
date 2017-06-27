/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Tue Jun 27 20:21:03 2017 Romain HUET
*/

#include "server/zappy_server.h"

/* t_func	g_cmds[NB_CMDS] = */
/*   { */
/*     {"Forward", &forward}, // */
/*     {"Right", &right},     // */
/*     {"Left", &left},    // */
/*     {"Look", &player_look},   //OK */
/*     {"Inventory", &inventory},  // */
/*     {"Connect_nbr", &connect_nbr},   // */
/*     {"Fork", &eggfork},          // */
/*     {"Eject", &player_expell},    //OK */
/*     {"Take", &player_take_ress},  //OK */
/*     {"Set", &player_drop_ress},   //OK */
/*   }; */

char	**get_cmd_args(char *s)
{
  char	**args;
  int	nb;
  int	i;

  i = 0;
  nb = count_words(s);
    args = NULL;
  while (!args)
    args = calloc(sizeof(char *), nb);
  while (i < nb)
    {
      args[i] = strdup(get_nth_word(s, i));
      i++;
    }
  args[i] = NULL;
  return (args);
}

int	check_cmd(char *s, t_player *player_src, t_server *server)
{
  char	*cmd;
  char	**cmd_args;
  int	i;

  i = 0;
  cmd = NULL;
  cmd_args = NULL;
  if (player_src->team == NULL && strcmp(s, "GRAPHIC\n"))
    {
      dprintf(player_src->fd, "ko\n");
      return (0);
    }
  /* while (!cmd) */
  /*   cmd = strdup(get_nth_word(s, 1)); */
  /* cmd_args = get_cmd_args(s); */
  /* while (i < NB_CMDS) */
  /*   { */
  /*     if (!strcmp(cmd, g_cmds[i].name)) */
  /* 	{ */
  /* 	  player_src = player_src; */
  /* 	  server = server; */
  /* 	  /\* g_cmds[i].ptrfunc(server, player_src, 0); *\/ */
  /* 	  printf("commande %s bien reçue !\nSes arguments :", cmd); */
  /* 	  for (i = 0; cmd_args[i] != NULL; i++) */
  /* 	    printf("%s\t", cmd_args[i]); */
  /* 	  return (1); */
  /* 	} */
  /*     i++; */
  /*   } */
  return (0);
}

void	set_graph_cli(t_player *player, t_server *server)
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
    dprintf(player->fd, "There already is a graphical server, feel free to enter the game by typing a team name :)\n");
}

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
  while (server->teams[i].name)
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
  buf[i - 1] = '\0';
  i = 0;
  while (server->teams[i].name)
    {
      if (!strcmp(buf, server->teams[i].name) && server->teams[i].room_left >= 1)
	{
	  player->team = strdup(buf);
	  server->teams[i].room_left--;
	  dprintf(player->fd, "%d\n", server->teams[i].room_left);
	  dprintf(player->fd, "%d %d\n", server->map[0][0].x_max, server->map[0][0].y_max);
	  new_player_connection(server->graph_cli_fd, player);
	  ok = 1;
	}
      i++;
    }
  if (!ok && strcmp(buf, "GRAPHIC\n"))
    dprintf(player->fd, "ko\n");
}

void	read_data(t_player *players, int src, t_server *server)
{
  char		*buf;
  int		read_ret;

  buf = NULL;
  while (!buf)
    buf = calloc(512, 1);
  read_ret = read(players[src].fd, buf, 512);
  if (read_ret < 0)
    {
      printf("error on read\n");
      exit(-1);
    }
  printf("data read = %s", buf);
  check_cmd(buf, &players[src], server);
  if (strcmp(buf, "GRAPHIC\n") == 0)
    set_graph_cli(&players[src], server);
  else if (is_team(buf, server))
    affect_team(buf, &players[src], server);
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
      /* printf("problem in init server\n"); */
      return (-1);
    }
  else if (server_loop(&args, &server, players) == -1)
    {
      free_args(&args);
      return (-1);
    }
  free_args(&args);
  close_all(&server, &args, players);
  return (0);
}
