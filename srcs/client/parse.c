/*
** parse.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 23 15:28:08 2017 Albatard
** Last update Wed Jun 28 16:07:19 2017 Romain HUET
*/

#include <stdio.h>
#include <stdlib.h>

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

void	nut(char *str)
{
  if (strcmp(str, "food") == 0)
    ;
  else if (strcmp(str, "thystame") == 0)
    ;
  else
    nut2(str);  
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
