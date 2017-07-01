/*
** tool.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Sat Jul  1 15:43:00 2017 eliott m-barali
** Last update Sat Jul  1 16:21:51 2017 eliott m-barali
*/

#include "../../include/ai/zappy_ai.h"

char	*cut_word(char *str, int n)
{
  int	i;
  int	j;
  int	stop;
  char	*to_ret;
  
  i = 0;
  j = 0;
  stop = 0;
  while (str[i] != '\0' && stop == 0)
    {
      if (str[i] == ' ')
	n = n - 1;
      if (n == 0)
	stop = 1;
      i = i + 1;
    }
  i = i + 2;
  to_ret = malloc(sizeof(char) * (strlen(str) - i ));
  while (str[i])
      to_ret[j++] = str[i++];
  to_ret[j] = '\0';
  return (to_ret);
}

int	*sort_int_tab(char *str)
{
  int	i;
  int	*tab;

  i = 0;
  if ((tab = malloc(sizeof(int) * 7)) == NULL)
    return (NULL);
  while (i != 7)
    {
      printf("i = %d et n = %d et c = %c\n", i, atoi(get_nth_word(str, i)), str[i]);
      tab[i] = atoi(get_nth_word(str, i));
      i = i + 1;
    }
  //show_ress(tab);
  return (tab);
}
