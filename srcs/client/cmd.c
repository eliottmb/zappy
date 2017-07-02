/*
** cmd.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/srcs/client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Sat Jul  1 13:55:19 2017 Albatard
** Last update Sun Jul  2 23:09:30 2017 Albatard
*/

#include "client.h"

int                     read_broadcast(char *str, int fd)
{
  char                  buffer[1024];
  char			**tab;

  if (read(fd, buffer, 1024) > 0)
    {
      tab = my_strtowordtab(buffer, ' ');
      if (strcmp(tab[1], str) == 0)
	return 1;
    }
  return 0;
}

char                    *read_cmd(int fd)
{
  char                  buffer[10480];
  char			*str;

  if (read(fd, buffer, 10480) > 0)
    {
      str = strdup(buffer);
      return (str);
    }
  return ("Error");
}

void                     check_cmd(int fd, client_info *info)
{
  char                  *buffer;
  int                   a;

  a = 0;
  while (42)
    {
      buffer = calloc(1024, 1);
      a = read(fd, buffer, 1024);
      if (a > 0)
	{
	  printf("%s", buffer);
	  if (strcmp(buffer, "WELCOME\n") == 0)
	    {
	      if (graph(fd) == 1)
		{
		  printf("IA\n");
		  dprintf(fd, "%s\n", info->name);
		}
	    }
	}
      else
	break;
    }
  free(buffer);
}
