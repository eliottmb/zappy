/*
** parse.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 23 15:28:08 2017 Albatard
** Last update Thu Jun 29 15:33:25 2017 Albatard
*/

#include <stdio.h>
#include <stdlib.h>
#include "client.h"

void	nut3(char *str)
{
  if (strcmp(str, "phiras") == 0)
    ;
  else if (strcmp(str, "mendiane") == 0)
    ;
  else if (strcmp(str, "sybur") == 0)
    ;
}

void	nut2(char *str)
{
  if (strcmp(str, "linemate") == 0)
    ;
  else if (strcmp(str, "deraumere") == 0)
    ;
  else
    nut3(str);  
}

void	parse(char *str, t_ai *joueur)//struct joueur, dedans mettre un tableau de case visibles
{
  t_ptr	index[7];
  int	i;
  int	j;

  j = 0;
  while (jouer.cdv[j])
    {
      i = 0;
      while (index[i])
	{
	  if (strcmp(index[i].ndr, str) == 0)
	    joueur.cdv[j][i]++;
	  i++;
	}
      j++;
    }
}

t_ptr	*fill(t_ptr *index)
{
  index[0]->ndr = stdup("Food");
  index[0]->i = 0;
  index[1]->ndr = strdup("Linemate");
  index[1]->i = 0;
  index[2]->ndr = strdup("Deraumere");
  index[2]->i = 0;
  index[3]->ndr = strdup("Sibur");
  index[3]->i = 0;
  index[3]->ndr = strdup("Sibur");
  index[3]->i = 0;
}

void	parse_look(char *str)
{
  int	i;
  int	a;
  char	**tab;

  i = 0;
  tab = my_strtowordtab(str, ',');
  while (tab[i] != '\0')
    {
      while (tab[i][a] != '\0')
	{
	  if (strcmp(tab[i][a], "player") == 0)
	    ;
	  else if (strcmp(tab[i][a], "") == 0)
	    ;
	  else
	    nut(tab[i][a]);
	  a++;
	}
      i++;
    }
}

void	play(char *str)
{
  char	**tab;

  tab = my_strtowordtab(str, ",");
  parse_look(str);
}
