/*
** init_args.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 20:42:04 2017 Romain HUET
** Last update Thu Jun 22 13:32:07 2017 Romain HUET
*/

#include "server/zappy_server.h"

int	init_args(t_args *args)
{
  args->port = 0;
  args->width = 20;
  args->height = 20;
  args->nb_of_teams = 2;
  args->names = NULL;
  if ((args->names = malloc(sizeof(char *) * 2)) == NULL)
    return (-1);
  if ((args->names[0] = strdup("Team_Epi")) == NULL ||
      (args->names[1] = strdup("Team_Tek")) == NULL)
    return (-1);
  args->c_per_team = 8;
  args->f = 100;
  args->max_players = args->c_per_team * args->nb_of_teams;
  return (0);
}
