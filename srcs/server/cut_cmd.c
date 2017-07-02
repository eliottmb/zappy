/*
** cut_cmd.c for  in /home/romain.huet/rendu/PSU_2016_zappy/srcs/server
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Fri Jun 30 18:49:07 2017 Romain HUET
** Last update Sun Jul  2 22:24:45 2017 Médéric Unissart
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

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
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
  if ((to_ret = malloc(sizeof(char) * (strlen(str) - i + 1))) == NULL)
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
