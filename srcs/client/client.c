/*
** client.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Mon Jun 19 18:02:14 2017 Albatard
** Last update Wed Jun 28 15:15:13 2017 Albatard
*/

#include "client.h"

void			add_info(client_info *info, char **av)
{
  info->port = atoi(av[2]);
  info->name = malloc(sizeof(char*) + strlen(av[4]) + 1);
  info->name = av[4];
  info->name = malloc(sizeof(char*) + strlen(av[6]) + 1);
  info->ip = av[6];
}

int			sock(struct protoent *pe, struct sockaddr_in s_in, client_info *info, int fd, char *pp)
{
  int			port;

  port = atoi(pp);
  pe = getprotobyname("TCP");
  if (!pe)
    return (1);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    return (1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(info->ip);
  if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    {
      perror("Sorry we can't connect you ");
      return (1);
    }
  else
    {
      printf("Connected, OK\n");
      check_cmd(fd, info);
    }
  return (0);
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
  if (sock(pe, s_in, &info, fd, av[2]) == 1)
    return 1;
  if (close(fd) == -1)
    return (1);
  return (0);
}
