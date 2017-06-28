/*
** check.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Tue Jun 27 17:03:28 2017 Albatard
** Last update Wed Jun 28 16:29:39 2017 Albatard
*/

#include "../../include/client/client.h"

void                     check_cmd(int fd, client_info *info)
{
  char			*buffer;
  int                   a;
  char                  **tab;

  a = 0;
  while (42)
    {
      buffer = calloc(1024, 1);
      a = read(fd, buffer, 1024);
      printf("%s", buffer);
      if (a >= 0)
	{
	  if (strcmp(buffer, "WELCOME\n") == 0)
	    {
	      graph(fd);
	      if (read(fd, buffer, 1024) > 0)
		{
		  printf("deuxieme if\n");
		  if (strcmp(buffer, "ko\n") == 0)
		    {
		      //// et si c'est ko, le prog de NICO reprend la main mode IA
		      dprintf(fd, "%s\n", info->name);
		      call(fd);
		    }
		}
	    }
	}
    }
  free(buffer);
}

int    check_number(char *str)
{
  int   a = 0;

  while (str[a] != '\0')
    {
      while (str[a] != '\0')
	{
	  if (str[a] >= 48 && str[a] <= 57)
	    a++;
	  else
	    return 1;
	}
      a++;
    }
  return 0;
}

int     usage(int ac, char **av)
{
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    {
      printf("USAGE: ./zappy_client -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name of\
 the team\n\tmachine\tis the name of the machine; localhost by default\n");
      return 1;
    }
  return 0;
}

int     check_args(int ac, char **av)
{
  int	i;

  i = 0;
  while (av[i] != '\0')
    {
      if (strcmp(av[i], "-p") != 0 && check_number(av[i+1]) == 1)
	{
	  fprintf(stderr, "Bad argument(s), -help for more information\n");
	  return (1);
	}
      else if (strcmp(av[i], "-n") != 0)
	{
	  fprintf(stderr, "Bad argument(s), -help for more information\n");
	  return (1);
	}
      else if (strcmp(av[i], "-h") != 0)
	{
	  fprintf(stderr, "Bad argument(s), -help for more information\n");
	  return (1);
	}
      i = i + 2;
    }
  return (0);
}

int     my_error(int ac, char **av)
{
  if (usage(ac, av) == 1)
    return 1;
  else
    {
      if (ac != 7)
	{
	  fprintf(stderr, "Bad number of arguments, -help for more information\n");
	  return 1;
	}
      else if (check_args(ac, av) == 1)
	return 1;
    }
  return 0;
}
