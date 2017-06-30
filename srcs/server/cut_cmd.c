/*
** cut_cmd.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Fri Jun 30 18:49:07 2017 Romain HUET
** Last update Fri Jun 30 19:42:14 2017 Romain HUET
*/

#include "zappy_server.h"

void	aff_tab(char **tab)
{
  int	i;

  i = 0;
  printf("DANS AFFTAB\n");
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      i++;
    }
  printf("DANS AFFTAB\n");
}

char	**cut_cmd(char *s)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 0;
  k = 0;
  if (count_words(s) == 1)
    return (NULL);
  if ((tab = calloc(11, sizeof(char *))) == NULL)
    return (NULL);
  while (i < 11)
    {	  
      if ((tab[i] = calloc(64, 1)) == NULL)
	return (NULL);
      i++;
    }
  tab[i] = NULL;
  i = 0;
  while (tab[i])
    {
      j = 0;
      while (s[k] && s[k] != '\n')
	{
	  tab[i][j] = s[k];
	  k++;
	  j++;
	}
      k++;
      if (s[k] == 0)
	break ;
      i++;
    }
  aff_tab(tab);
  return (tab);
}
