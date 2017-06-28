/*
** client.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Mon Jun 19 18:02:14 2017 Albatard
** Last update Wed Jun 28 17:54:36 2017 Albatard
*/

#include "../../include/client/client.h"

void			add_info(client_info *info, char **av, int ac)
{
  int			i;

  i = 1;
  info->name = malloc(sizeof(char*) + 5);
  info->name = "Team1";
  info->ip = malloc(sizeof(char*) + 1);
  info->ip = "0";
  while (av[i] != '\0')
    {
      printf("%s\n", av[i]);
      if (strcmp(av[i], "-p") == 0)
	info->port = atoi(av[i+1]);
      else if (strcmp(av[i], "-h") == 0)
	{
	  info->ip = realloc(info->name, sizeof(char*) + strlen(av[i+1]) - 5 + 1);
	  info->ip = av[i+1];
	}
      else if (strcmp(av[i], "-n") == 0)
	{
	  info->name = realloc(info->name, sizeof(char*) + strlen(av[i+1]));
	  info->name = av[i+1];
	}
      else
	break;
      i = i + 2;
    }
}

int			sock(struct protoent *pe, struct sockaddr_in s_in, client_info *info, int fd, char *pp)
{
  info->port = atoi(pp);
  pe = getprotobyname("TCP");
  if (!pe)
    return (1);
  fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (fd == -1)
    return (1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(info->port);
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
    add_info(&info, av, ac);
  if (sock(pe, s_in, &info, fd, av[2]) == 1)
    return 1;
  if (close(fd) == -1)
    return (1);
  return (0);
}
