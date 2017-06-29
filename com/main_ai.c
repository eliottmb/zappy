/*
** main_ai.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 17:13:51 2017 eliott m-barali
** Last update Thu Jun 29 18:11:18 2017 eliott m-barali
*/

#include "zappy_ai.h"
#include "incant_macro.h"


int		main()
{
  t_ai		*ai;
  int		*tab;
  
  if ((ai = malloc(sizeof(t_ai*))) == NULL)
    return (-1);
  tab = malloc(sizeof(int) * 7);
  init_ai(ai, 10, 10, "lalalolo");
  show_ress(ai->i);
  ask_ress(ai, ai->i);
  ask_lvl(ai);
  ask_more_players(ai, 3);
  answer_lvl(ai);
  o_m_w(ai);
  got_thy(ai);
  return (0);
}
