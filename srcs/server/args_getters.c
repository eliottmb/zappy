/*
** args_getters.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Tue Jun 27 13:25:29 2017 Romain HUET
** Last update Wed Jun 28 15:44:55 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

void    get_p(t_args *args, char **av)
{
  int   i;

  i = 0;
  while (av[i])
    {
      if (!strcmp(av[i], "-p"))
	{
	  if (!is_num(av[i + 1]))
	    {
	      dprintf(2, "\n-p option only accepts valid ports\n\n");
	      help_server();
	      exit(-1);
	    }
	  else
	    args->port = atoi(av[i + 1]);
	}
      i++;
    }
}

void    get_x(t_args *args, char **av)
{
  int   i;

  i = 0;
  while (av[i])
    {
      if (!strcmp(av[i], "-x"))
	{
	  if (!is_num(av[i + 1]) || atoi(av[i + 1]) < 10 || atoi(av[i + 1]) > 30)
	    {
	      dprintf(2, "\n-x option only accepts integer values between 10 and 30\n\n");
	      help_server();
	      exit(-1);
	    }
	  else
	    args->width = atoi(av[i + 1]);
	}
      i++;
    }
}

void    get_y(t_args *args, char **av)
{
  int   i;

  i = 0;
  while (av[i])
    {
      if (!strcmp(av[i], "-y"))
	{
	  if (!is_num(av[i + 1]) || atoi(av[i + 1]) < 10 || atoi(av[i + 1]) > 30)
	    {
	      dprintf(2, "\n-y option only accepts integer values between 10 and 30\n\n");
	      help_server();
	      exit(1);
	    }
	  else
	    args->height = atoi(av[i + 1]);
	}
      i++;
    }
}

void    get_c(t_args *args, char **av)
{
  int   i;

  i = 0;
  while (av[i])
    {
      if (!strcmp(av[i], "-c"))
	{
	  if (!is_num(av[i + 1]) || atoi(av[i + 1]) < 1)
	    {
	      dprintf(2, "\n-c option only accepts integer values greater or equal to 1\n\n");
	      help_server();
	      exit(1);
	    }
	  else
	    args->c_per_team = atoi(av[i + 1]);
	}
      i++;
    }
}

void    get_f(t_args *args, char **av)
{
  int   i;

  i = 0;
  while (av[i])
    {
      if (!strcmp(av[i], "-f"))
	{
	  if (!is_num(av[i + 1]) || atoi(av[i + 1]) < 2 || atoi(av[i + 1]) > 10000)
	    {
	      dprintf(2, "\n-f option only accepts integer values between 2 and 10000\n\n");
	      help_server();
	      exit(1);
	    }
	  else
	    args->f = atoi(av[i + 1]);
	}
      i++;
    }
}
