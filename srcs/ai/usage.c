/*
** usage.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 28 19:41:39 2017 eliott m-barali
** Last update Sat Jul  1 13:16:06 2017 eliott m-barali
*/

#include "../../include/ai/zappy_ai.h"

void		show_ress(int *t)
{
  int		i;

  i = 0;
  while (i != 7)
    {
      printf(" %d", t[i]);
      i = i + 1;
    }
  printf("\n");
}

void		show_struct(t_ai *ai)
{
  printf("%d & %d, %s,", ai->x_max, ai->y_max, ai->team);
  show_ress(ai->i);
}

int		*my_add_tab(int *to_ret, int *t1, int *t2)
{
  int		i;

  i = 0;
  if ((to_ret = malloc(sizeof(int) * 7)) == NULL)
    return (NULL);
  while (i != 7)
    {
      to_ret[i] = t1[i] + t2[i];
      i = i + 1;
    }
  return (to_ret);
}

int		*my_dif_tab(int *to_ret, int *t1, int *t2)
{
  int		i;

  i = 0;
  if ((to_ret = malloc(sizeof(int) * 7)) == NULL)
    return (NULL);
  while (i != 7)
    {
      to_ret[i] = t1[i] - t2[i];
      i = i + 1;
    }
  return (to_ret);
}
