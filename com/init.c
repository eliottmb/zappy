/*
** init.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 28 19:46:38 2017 eliott m-barali
** Last update Thu Jun 29 18:02:38 2017 eliott m-barali
*/

#include "zappy_ai.h"
#include "incant_macro.h"

const int	one[] = {0, 1, 0, 0, 0, 0, 0, 1};
const int	two[] = {0, 1, 1, 1, 0, 0, 0, 2};
const int	three[] = {0, 2, 0, 1, 0, 2, 0, 2};
const int	four[] = {0, 1, 1, 2, 0, 1, 0, 4};
const int	five[] = {0, 1, 2, 1, 3, 0, 0, 4};
const int	six[] = {0, 1, 2, 3, 0, 1, 0, 6};
const int	seven[] = {0, 2, 2, 2, 2, 2, 1, 1};

int		*init_tab()
{
  int		*t;
  
  if ((t = malloc(sizeof(int) * 7)) == NULL)
    return (NULL);
  t[0] = 10;
  t[1] = 1;
  t[2] = 1;
  t[3] = 1;
  t[4] = 0;
  t[5] = 0;
  t[6] = 0;
  return (t);
}

int		init_ai(t_ai *ai, int x, int y, char *t)
{
  ai->fd = 0;
  ai->x_max = x;
  ai->lvl = 1;
  ai->y_max = y;
  ai->got_thy = 0;
  if ((ai->team = strdup(t)) == NULL)
    return (-1);
  ai->incantating = 0;
  ai->broadcasting = 0;
  ai->i = init_tab();
  return (0);
}

void		free_ai(t_ai *ai)
{
    free(ai);
}