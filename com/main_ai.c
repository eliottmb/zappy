/*
** main_ai.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 17:13:51 2017 eliott m-barali
** Last update Wed Jun 28 19:48:56 2017 eliott m-barali
*/

#include "../../include/ai/zappy_ai.h"
#include "../../include/ai/incant_macro.h"


int		main()
{
  t_ai		*ai;
  t_ai		*a;
  int		*tab;
  if ((ai = malloc(sizeof(t_ai*))) == NULL)
    return (-1);
  if ((a = malloc(sizeof(t_ai*))) == NULL)
    return (-1);
  tab = malloc(sizeof(int) * 7);
  init_ai(ai, 10, 10, "lalalolo");
  init_ai(a, 8, 8, "trolillolilol");
  tab = my_add_tab(tab, ai->i, a->i);
  show_ress(tab);
  tab = my_add_tab(tab, tab, a->i);
  show_ress(tab);
  tab = my_dif_tab(tab, tab, a->i);
  show_ress(tab);
  return (0);
}
