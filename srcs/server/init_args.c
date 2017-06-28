/*
** init_args.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 20:42:04 2017 Romain HUET
** Last update Wed Jun 28 15:46:37 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

void	aff_args(t_args *args)
{
  int	i;

  i = 0;
  printf("port = %d\n", args->port);
  printf("map width = %d\n", args->width);
  printf("map height = %d\n", args->height);
  printf("there are %d teams\n", args->nb_of_teams);
  printf("their names are :\n");
  if (args->nb_of_teams != 0)
    {
      while (args->names[i])
	{
	  printf("%s\n", args->names[i]);
	  i++;
	}
    }
  printf("each teams has %d players\n", args->c_per_team);
  printf("f = 1/%d seconds\n", args->f);
}

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
