/*
** check.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Tue Jun 27 17:03:28 2017 Albatard
** Last update Tue Jun 27 19:13:13 2017 Albatard
*/

#include "client.h"

void                     check_cmd(int fd)
{
  char                  buffer[512];
  int                   a;
  char                  **tab;

  a = 0;
  while (42)
    {
      a = strlen(buffer);
      while (a >= 0)
	{
	  buffer[a] = '\0';
	  a--;
	}
      a = read(fd, buffer, 255);
      a = strlen(buffer);
      printf("%s", buffer);
      if (strcmp(buffer, "WELCOME\n") == 0)
	{
	  dprintf(fd, "GRAPHIC\n");
	  call(fd);
	}
      else if (strcmp(buffer, "ko\n") == 0)
	dprintf(fd, "Team1\n");
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
  if (strcmp(av[1], "-p") != 0 && check_number(av[2]) == 1)
    {
      fprintf(stderr, "Bad argument(s), -help for more information\n");
      return (1);
    }
  else if (strcmp(av[3], "-n") != 0)
    {
      fprintf(stderr, "Bad argument(s), -help for more information\n");
      return (1);
    }
  else if (strcmp(av[5], "-h") != 0)
    {
      fprintf(stderr, "Bad argument(s), -help for more information\n");
      return (1);
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
