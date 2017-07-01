/*
** get_nth_word.c for  in /home/romain.huet/rendu/PSU/PSU_2016_myirc/romain
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Wed May 31 16:35:33 2017 Romain HUET
** Last update Sat Jul  1 13:59:14 2017 eliott m-barali
*/

#include "../include/server/zappy_server.h"

int     is_separator(char c)
{
  if (c == ' ' ||
            c == '\t' ||
            c == '\n' ||
      c == '\0')
    return (1);
  return (0);
}

int	count_words(char *s)
{
  int	i;
  int	count;

  if (s == NULL)
    return (0);
  i = 0;
  count = 0;
  while (s[i])
    {
      if (is_separator(s[i]))
	count++;
      i++;
    }
  return (count);
}

char    *get_nth_word(char *s, int n)
{
  int   i;
  int   j;
  int   nb_sep;
  char  buf[64];
  char  *word;

  i = 0;
  j = 0;
  nb_sep = 0;
  while (s[i] && nb_sep < n - 1)
    {
      if (is_separator(s[i]))
	nb_sep++;
      i++;
    }
  if (!s[i])
    return (NULL);
  while (s[i] && !is_separator(s[i]))
    {
      buf[j] = s[i];
      i++;
      j++;
    }
  buf[j] = 0;
  word = strdup(buf);
  return (word);
}
