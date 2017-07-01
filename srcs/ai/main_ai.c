/*
** main_ai.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 17:13:51 2017 eliott m-barali
** Last update Sat Jul  1 13:53:30 2017 eliott m-barali
*/

#include "../../include/ai/zappy_ai.h"
#include "../../include/ai/incant_macro.h"


int		main(int argc, char **argv)
{
  t_ai		ai;
  int		*tab;
  int		*player;
  
  tab = malloc(sizeof(int) * 7);
  tab[0] = 0;
  tab[1] = 0;
  tab[2] = 0;
  tab[3] = 0;
  tab[4] = 1;
  tab[5] = 0;
  tab[6] = 0;
  init_ai(&ai, 10, 10, "lalalolo");
  ask_ress(&ai, ai.i);
  player = init_player_tab();
  player = add_player(player, 3);
  player = add_player(player, 4);
  player = add_player(player, 7);
  ask_more_players(&ai, player);
  my_ress(&ai, tab);
  send_sharp(&ai);
  got_broadcast(&ai, argv[1]);
  return (0);
}
