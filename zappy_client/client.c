/*
** client.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Mon Jun 19 18:02:14 2017 Albatard
** Last update Thu Jun 22 16:18:15 2017 Albatard
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "client.h"

//char			**my_strtowordtab(char *str, char);

void			call(int fd);

char                    *append(char *str1, char *str2)
{
  char                  *tmp;
  int                   i;
  int                   len;

  if (str2)
    {
      tmp = malloc(sizeof(char*) + strlen(str1) + strlen(str2) + 2);
      tmp[0] = '\0';
      strcat(tmp, str1);
      strcat(tmp, str2);
      i = strlen(tmp);
      tmp[i] = '\0';
      if (tmp[i-1] == '\n')
	tmp[i-1] = '\0';
    }
  else
    fprintf(stderr, "You must add a Name\n");
  return (tmp);
}

int                     check_cmd(int fd)
{
  char                  buffer[255];
  char                  *tmp;
  int                   a;
  int                   b;
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
      a = read(0, buffer, 255);
      a = strlen(buffer);
      buffer[a-1] = '\0';
      write(fd, buffer, strlen(buffer));
      write(fd, "\n", 1);
      //      tab = my_strtowordtab(buffer, ' ');
    }
  free(tmp);
  free(buffer);
  return (1);
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

int	usage(int ac, char **av)
{
  if (ac == 2 && strcmp(av[1], "-help") == 0)
    {
      printf("USAGE: ./zappy_client -p port -n name -h machine\n\tport\tis the port number\n\tname\tis the name of the team\n\tmachine\tis the name of the machine; localhost by default\n");
      return 1;
    }
  return 0;
}

int	check_args(int ac, char **av)
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

int	my_error(int ac, char **av)
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

void			add_info(client_info *info, char **av)
{
  info->port = atoi(av[2]);
  info->name = malloc(sizeof(char*) + strlen(av[4]) + 1);
  info->name = av[4];
  info->name = malloc(sizeof(char*) + strlen(av[6]) + 1);
  info->ip = av[6];
}

int			main(int ac, char **av)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  client_info		info;

  if (my_error(ac, av) == 1)
    return 1;
  else
    add_info(&info, av);
  port = atoi(av[2]);
  pe = getprotobyname("TCP");
  if (!pe)
    return (1);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    return (1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(info.ip);
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      perror("Sorry we can't connect you ");
      return (1);
    }
  printf("Connected, OK\n");
  call(fd);
  check_cmd(fd);
  if (close(fd) == -1)
    return (1);
  return (0);
}
