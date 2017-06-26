/*
** check_params.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Wed Jun 21 17:19:12 2017 Romain HUET
** Last update Mon Jun 26 13:01:20 2017 Romain HUET
*/

#include "server/zappy_server.h"

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
  else if (args->f > 10000 || args->f < 2)
    {
      printf("Error : -f option value must be between 2 and 10000\n");
      exit(-1);
    }
  aff_args(args);
}