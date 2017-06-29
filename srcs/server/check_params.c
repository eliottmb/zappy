/*
** check_params.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Wed Jun 21 17:19:12 2017 Romain HUET
** Last update Thu Jun 29 17:14:14 2017 Romain HUET
*/

#include "zappy_server.h"

void	check_help(int ac, char **av)
{
  if (ac == 2 && !strcmp(av[1], "-help"))
    {
      help_server();
      exit(0);
    }
}

void	check_args(t_args *args, char **av)
{
  if (init_args(args) == -1)
    exit(-1);
  if (get_args(args, av) == -1 ||
      args->port == 0)
    {
      printf("Error : need at least a port as parameter (%s -p port)\n", av[0]);
      exit(-1);
    }
  printf("Port : %d\n", args->port);
}
