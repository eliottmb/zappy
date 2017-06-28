/*
** args_manager.c for  in /home/romain.huet/rendu/Backup_Zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 17:43:17 2017 Romain HUET
** Last update Wed Jun 28 15:45:19 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

int     count_teams(char **av)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (av[i] && strcmp(av[i], "-n"))
    i++;
  i++;
  while (av[i] && av[i][0] != '-')
    {
      i++;
      j++;
    }
  return (j);
}

int     check_doublons(char **names)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (names[i])
    {
      j = i + 1;
      while (names[j])
	{
	  if (!strcmp(names[i], names[j]))
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

char	**get_team_names(int nb_teams, char **av, int *i)
{
  char	**names;
  int	j;

  j = 0;
  if ((names = malloc(sizeof(char *) * nb_teams + 1)) == NULL)
    return (NULL);
  (*i)++;
  while (av[*i] && av[*i][0] != '-')
    {
      if ((names[j] = strdup(av[*i])) == NULL)
	return (NULL);
      j++;
      (*i)++;
    }
  names[j] = NULL;
  (*i)--;
  if (check_doublons(names))
    {
      printf("-n option only accepts unique team names\n");
      exit(-1);
    }
  return (names);
}

int     get_args(t_args *args, char **av)
{
  int   i;
  
  i = 0;
  get_p(args, av);
  get_x(args, av);
  get_y(args, av);
  get_c(args, av);
  get_f(args, av);
  while (av[i])
    {
      if (!strcmp(av[i], "-n") && av[i + 1])
	{
	  args->nb_of_teams = count_teams(av);
	  if ((args->names = get_team_names(args->nb_of_teams, av, &i)) == NULL)
	    return (-1);
	}
      i++;
    }
  args->max_players = MAX_PLAYERS;
  return (0);
}

void    free_args(t_args *args)
{
  int   i;

  i = 0;
  while (args->names[i])
    {
      free(args->names[i]);
      i++;
    }
  free(args->names);
}
