/*
** init.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 28 19:46:38 2017 eliott m-barali
** Last update Sat Jul  1 18:12:08 2017 Albatard
*/

#include "../../include/ai/zappy_ai.h"
#include "../../include/ai/incant_macro.h"

const int	ONE[] = {0, 1, 0, 0, 0, 0, 0, 1};
const int	TWO[] = {0, 1, 1, 1, 0, 0, 0, 2};
const int	THREE[] = {0, 2, 0, 1, 0, 2, 0, 2};
const int	FOUR[] = {0, 1, 1, 2, 0, 1, 0, 4};
const int	FIVE[] = {0, 1, 2, 1, 3, 0, 0, 4};
const int	SIX[] = {0, 1, 2, 3, 0, 1, 0, 6};
const int	SEVEN[] = {0, 2, 2, 2, 2, 2, 1, 1};
const int	RESS_NEED[] = {0, 2, 2, 3, 3, 2, 1};

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

int		init_ai(t_ai *ai, char *t)
{
  ai->fd = 0;
  ai->lvl = 1;
  ai->got_thy = 0;
  ai->num_player = 0;
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
