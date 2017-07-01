/*
** cut_cmd.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Fri Jun 30 18:49:07 2017 Romain HUET
** Last update Sat Jul  1 12:02:27 2017 Romain HUET
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

char    *cut_first_word(char *str)
{
  int   i;
  int   j;
  char  *to_ret;

  i = 0;
  j = 0;
  while (str[i] != ' ')
    i = i + 1;
  i = i + 1;
  if ((to_ret = malloc(sizeof(char) * (strlen(str) - i ))) == NULL)
    return (NULL);
  while (str[i])
    {
      to_ret[j] = str[i];
      i = i + 1;
      j = j + 1;
    }
  to_ret[j] = '\0';
  return (to_ret);
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
