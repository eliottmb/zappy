/*
** main_serv.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 14:32:59 2017 Romain HUET
** Last update Fri Jun 23 15:22:14 2017 Romain HUET
*/

#include "server/zappy_server.h"

int	check_cmd(char *s, t_player *players)
{
  
  return (0);
  return (1);
}

void	read_data(t_player *players, int src)
{
  char		*buf;
  int		read_ret;

  buf = NULL;
  while (!buf)
    buf = calloc(512, 1);
  read_ret = read(players[src].fd, buf, strlen(buf));
  if (read < 0)
    printf("error on read\n");
  else if (read > 0)
    {
      if (check_cmd(buf, players))
	printf("command %s bien reçue\n", buf);
    }
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
  show_map(map);
  if (init_server(&server, &args) == -1)
    {
      printf("problem in init server\n");
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
