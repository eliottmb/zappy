/*
** talk_to_me_jeffrey.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 19:29:01 2017 eliott m-barali
** Last update Thu Jun 29 18:45:47 2017 eliott m-barali
*/

#include "zappy_ai.h"

void		ask_ress(t_ai *ai, int *ress)
{
  dprintf(ai->fd, "%s %d ! %d %d %d %d %d %d %d\n", ai->team, ai->lvl, ress[0], ress[1], ress[2], ress[3], ress[4], ress[5], ress[6]);
}

void		ask_more_players(t_ai *ai, int i)
{
  dprintf(ai->fd, "%s %d - %d\n", ai->team, ai->lvl, i);
}

void		o_m_w(t_ai *ai)
{
  dprintf(ai->fd, "%s %d * %d %d %d %d %d %d %d\n", ai->team, ai->lvl, ai->i[0], ai->i[1], ai->i[2], ai->i[3], ai->i[4], ai->i[5], ai->i[6]);
}

void		got_thy(t_ai *ai)
{
  dprintf(ai->fd, "%s %d #\n", ai->team, ai->lvl);
}

