/*
** look.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/srcs/client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 30 20:13:00 2017 Albatard
** Last update Sat Jul  1 17:47:06 2017 Albatard
*/

#include "client.h"

void	in(char *str, t_inv **inv)
{
  char	**tmp;
  int	i;

  tmp = my_strtowordtab(str, ' ');
  printf("%s-%s\n", tmp[0], tmp[1]);
  while (inv[i])
    {
      if (strcmp(inv[i]->ndr, tmp[1]) == 0)
	inv[i]->i = atoi(tmp[2]);
      i++;
    }
  free(tmp);
}

void	parse_inventory(char *str, t_inv *inv)
{
  int	i;
  char	**tab;

  i = 0;
  tab = my_strtowordtab(str, ',');
  while (tab[i] != '\0')
    {
      in(tab[i], &inv);
      i++;
    }
}
