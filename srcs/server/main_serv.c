/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Fri Jun 23 18:33:40 2017 Romain HUET
*/

#include "server/zappy_server.h"

t_func	g_cmds[NB_CMDS] = 
  {
    {"Forward", &forward},
    {"Right", &right},
    {"Left", &left},
    {"Look", &look},
    {"Inventory", &inventory},
    {"Broadcast", &broadcast},
    {"Connect_nbr", &connect_nbr},
    {"Fork", &eggfork},
    {"Eject", &eject},
    {"Take", &take_object},
    {"Set", &set_object},
    {"Incantation", &start_incantation},
  };

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

int	check_cmd(char *s, t_player *player_src, t_server *server, t_tile **map)
{
  char	*cmd;
  char	**cmd_args;
  int	i;

  i = 0;
  cmd = NULL;
  cmd_args = NULL;
  while (!cmd)
    cmd = strdup(get_nth_word(s, 1));
  cmd_args = get_cmd_args(s);
  while (i < NB_CMDS)
    {
      if (!strcmp(cmd, g_cmds[i].name))
	{
	  g_cmds[i].ptrfunc(player_src, cmd_args, server, map);
	  printf("commande %s bien reçue !\nSes arguments :", cmd);
	  for (i = 0; cmd_args[i] != NULL; i++)
	    printf("%s\t", cmd_args[i]);
	  return (1);
	}
      i++;
    }
  return (0);
}

void	read_data(t_player *players, int src, t_server *server, t_tile **map)
{
  char		*buf;
  int		read_ret;

  buf = NULL;
  while (!buf)
    buf = calloc(512, 1);
  read_ret = read(players[src].fd, buf, strlen(buf));
  if (read_ret < 0)
    printf("error on read\n");
  else if (read_ret > 0)
    check_cmd(buf, &players[src], server, map);
}

int	main(int ac, char **av)
{
  t_args	args;
  t_server	server;
  t_player	*players;
  t_tile	**map;

  players = NULL;
  srand(time(NULL));
  check_help(ac, av);
  check_args(&args, av);
  players = init_players(players, &args);
  map = init_map(args.width, args.height, args.max_players - 1);
  if (init_server(&server, &args) == -1)
    {
      printf("problem in init server\n");
      return (-1);
    }
  else if (server_loop(&args, &server, players, map) == -1)
    {
      free_args(&args);
      return (-1);
    }
  free_args(&args);
  close_all(&server, &args, players);
  return (0);
}
