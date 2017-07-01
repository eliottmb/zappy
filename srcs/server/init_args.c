/*
** init_args.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 20:42:04 2017 Romain HUET
** Last update Sat Jul  1 15:44:14 2017 Romain HUET
*/

#include "zappy_server.h"

int	init_args(t_args *args)
{
  args->port = 0;
  args->width = 20;
  args->height = 20;
  args->nb_of_teams = 4;
  args->names = NULL;
  if ((args->names = malloc(sizeof(char *) * 5)) == NULL)
    return (-1);
  if ((args->names[0] = strdup("Team1")) == NULL ||
      (args->names[1] = strdup("Team2")) == NULL ||
      (args->names[2] = strdup("Team3")) == NULL ||
      (args->names[3] = strdup("Team4")) == NULL)
    return (-1);
  args->names[4] = NULL;
  args->c_per_team = 8;
  args->f = 100;
  args->max_players = MAX_PLAYERS;
  return (0);
}
