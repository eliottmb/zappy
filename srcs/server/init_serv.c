/*
** init_server.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 17:56:36 2017 Romain HUET
** Last update Thu Jun 29 17:15:42 2017 Romain HUET
*/

#include "zappy_server.h"

int	tablen(char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return (0);
  while (tab[i])
    i++;
  return (i);
}

void	init_serv_teams(t_server *server, t_args *args)
{
  int	i;

  i = 0;
  if ((server->teams = calloc(args->nb_of_teams, sizeof(t_team))) == NULL)
    return ;
  while (i < args->nb_of_teams)
    {
      if ((server->teams[i].name = strdup(args->names[i])) == NULL)
	return ;
      server->teams[i].room_left = args->c_per_team;
      i++;
    }
}

int     init_server(t_server *server, t_args *args)
{
  server->s_in_size = sizeof(server->s_in_client);
  server->port = args->port;
  if ((server->pe = getprotobyname("TCP")) == NULL)
    return (-1);
  if ((server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto)) == -1)
    return (-1);
  server->s_in.sin_family = AF_INET;
  server->s_in.sin_port = htons(server->port);
  server->s_in.sin_addr.s_addr = INADDR_ANY;
  if (bind_serv(server) == -1 ||
      listen_serv(server) == -1)
    return (-1);
  server->map = init_map(args->width, args->height, MAX_PLAYERS / 4);
  server->f = args->f;
  server->graph_cli_fd = -1;
  server->nb_of_teams = args->nb_of_teams;
  init_serv_teams(server, args);
  return (0);
}

int     bind_serv(t_server *server)
{
  if (bind(server->fd, (const struct sockaddr *)&server->s_in, sizeof(server->s_in)) == -1)
    {
      close(server->fd);
      dprintf(2, "[ERROR] : bind : Permission denied\n");
      return (-1);
    }
  return (0);
}

int     listen_serv(t_server *server)
{
  if (listen(server->fd, MAX_PLAYERS) == -1)
    {
      close(server->fd);
      return (-1);
    }
  return (0);
}
