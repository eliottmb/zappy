/*
** main_ai.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 17:13:51 2017 eliott m-barali
** Last update Wed Jun 28 15:42:03 2017 eliott m-barali
*/

#include "../../include/ai/zappy_ai.h"

const int	one[] = {0, 1, 0, 0, 0, 0, 0, 1};
const int	two[] = {0, 1, 1, 1, 0, 0, 0, 2};
const int	three[] = {0, 2, 0, 1, 0, 2, 0, 2};
const int	four[] = {0, 1, 1, 2, 0, 1, 0, 4};
const int	five[] = {0, 1, 2, 1, 3, 0, 0, 4};
const int	six[] = {0, 1, 2, 3, 0, 1, 0, 6};
const int	seven[] = {0, 2, 2, 2, 2, 2, 1, 1};

int		init_ai(t_ai *ai, int x, int y, char *team)
{
  ai->fd = 0;
  if ((ai = malloc(sizeof(t_ai*))) == NULL)
    return (-1);;
  ai->x_max = x;
  ai->y_max = y;
  ai->i[0] = 10;
  ai->i[1] = 0;
  ai->i[2] = 0;
  ai->i[3] = 0;
  ai->i[4] = 0;
  ai->i[5] = 0;
  ai->i[6] = 0;
  ai->got_thy = 0;
  if ((ai->team = strdup(team)) == NULL)
    return (-1);
  ai->lvl = 1;
  ai->incantating = 0;
  ai->broadcasting = 0;
  return (0);
}

void		free_ai(t_ai *ai);
{
  free(ai->i);
  free(ai->team);
  free(ai);
}
