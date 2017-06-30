/*
** check.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Tue Jun 27 17:03:28 2017 Albatard
** Last update Fri Jun 30 19:47:05 2017 Albatard
*/

#include "client.h"

int			read_cmd(char *str, int fd)
{
  char			buffer[1024];

  if (read(fd, buffer, 1024) > 0)
    {
      if (strcmp(buffer, str) == 0)
	return 1;
    }
  return 0;
}

void                     check_cmd(int fd, client_info *info)
{
  char			*buffer;
  int                   a;

  a = 0;
  while (42)
    {
      buffer = calloc(1024, 1);
      a = read(fd, buffer, 1024);
      printf("%s", buffer);
      if (a > 0)
	{
	  if (strcmp(buffer, "WELCOME\n") == 0)
	    {
	      if (graph(fd) == 1)
		{
		  printf("IA\n");
		  dprintf(fd, "%s\n", info->name);
		  //	  begin(fd, info);
		  call(fd);
		}
	    }
	}
      else
	break;
    }
  free(buffer);
}

int    check_number(char *str)
{
  int   a = 0;

  while (str[a] != '\0')
    {
      if (str[a] >= 48 && str[a] <= 57)
	a++;
      else
	return 1;
    }
  return 0;
}

int     usage(int ac, char **av)
{
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    {
      printf("USAGE: ./zappy_client -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name ofthe team\n\tmachine\tis the name of the machine; localhost by default\n");
      return 1;
    }
  return 0;
}

int     check_args(char **av)
{
  int	i;
  int	ok;

  ok = 0;
  i = 1;
  while (av[i] != '\0')
    {
      if (strcmp(av[i], "-p") == 0 && check_number(av[i+1]) == 0)
	{
	  ok = 1;
	  i = i + 2;
	}
      else if ((strcmp(av[i], "-n") == 0) ||
	       (strcmp(av[i], "-h") == 0))
	i = i + 2;
      else
	{
	  fprintf(stderr, "Bad argument(s), -help for more information\n");
	  return (1);
	}
    }
  if (ok != 0)
    return (0);
  fprintf(stderr, "Bad argument(s), -help for more information\n");
  return (1);
}

int     my_error(int ac, char **av)
{
  if (usage(ac, av) == 1)
    return 1;
  else
    {
      if ((ac != 7) &&
	  (ac != 5) &&
	  (ac != 3))
	{
	  fprintf(stderr, "Bad number of arguments, -help for more information\n");
	  return 1;
	}
      else if (check_args(av) == 1)
	return 1;
    }
  return 0;
}
