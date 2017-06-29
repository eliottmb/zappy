/*
** main_ai.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 17:13:51 2017 eliott m-barali
** Last update Thu Jun 29 18:58:44 2017 eliott m-barali
*/

#include "zappy_ai.h"
#include "incant_macro.h"


int		main(int argc, char **argv)
{
  t_ai		*ai;
  int		*tab;
  
  if ((ai = malloc(sizeof(t_ai*))) == NULL)
    return (-1);
  tab = malloc(sizeof(int) * 7);
  init_ai(ai, 10, 10, "lalalolo");
  show_ress(ai->i);
  ask_ress(ai, ai->i);
  ask_more_players(ai, 3);
  o_m_w(ai);
  got_thy(ai);
  printf("jusqu'ici sa va\n");
  got_broadcast(ai, argv[1]);
  return (0);
}
