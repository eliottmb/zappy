/*
** parse.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 23 15:28:08 2017 Albatard
** Last update Sun Jul  2 01:32:27 2017 Albatard
*/

#include "client.h"

void	parse(char *str, t_ai *joueur, t_inv *inv, int j)
{
  int	i;

  i = 0;
  while (i <= 6)
    {
      if (strcmp(inv[i].ndr, str) == 0)
	joueur->view[j][i]++;
      i++;
    }
}

t_inv	*fill(t_inv *inv)
{
  inv = malloc(sizeof(t_inv) * 7);
  inv[0].ndr = strdup("food");
  inv[0].i = 0;
  inv[1].ndr = strdup("linemate");
  inv[1].i = 0;
  inv[2].ndr = strdup("deraumere");
  inv[2].i = 0;
  inv[3].ndr = strdup("sibur");
  inv[3].i = 0;
  inv[4].ndr = strdup("mendiane");
  inv[4].i = 0;
  inv[5].ndr = strdup("phiras");
  inv[5].i = 0;
  inv[6].ndr = strdup("thystame");
  inv[6].i = 0;
  return (inv);
}

void	check_l(t_ai *joueur, int i)
{
  printf("%d\n", i);
  if (i == 1)
    turn_left(joueur->fd);
  else if (i == 2)
    forward(joueur->fd);
  else if (i == 2)
    turn_right(joueur->fd);
  joueur->lvl++;
  look(joueur->fd);
  incantation(joueur->fd);
}

int	nut(char *str, t_ai *joueur, t_inv *inv, int j)
{
  int	i;
  char	**tab;

  i = 0;
  tab = my_strtowordtab(str, ' ');
  while (tab[i])
    {
      if (strcmp(tab[i], "linemate") == 0 && joueur->lvl == 1)
	{
	  check_l(joueur, i);
	  return 1;
	}
      parse(tab[i], joueur, inv, j);
      i++;
    }
  free(tab);
  return 0;
}

void	parse_look(char *str, t_ai *joueur, t_inv *inv, int fd)
{
  int	i;
  char	**tab;

  i = 0;
  tab = my_strtowordtab(str, ',');
  if (strcmp(tab[0], "linemate") == 0 && joueur->lvl == 1)
    {
      incantation(fd);
      joueur->lvl++;
    }
  else
    {
      while (tab[i] != '\0')
	{
	  if (nut(tab[i], joueur, inv, i) == 1)
	    break;
	  i++;
	}
    }
}
