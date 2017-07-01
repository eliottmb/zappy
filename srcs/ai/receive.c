/*
** receive.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 28 19:36:07 2017 eliott m-barali
** Last update Sat Jul  1 16:20:39 2017 eliott m-barali
*/

#include "../../include/ai/zappy_ai.h"

int		receive_sharp(t_ai *ai)
{
  printf("sharp recu\n");
  return (0);
}

int		receive_ask_ress(char *str, t_ai *ai)
{
  int		*tab;
  
  printf("%s\n", cut_word(str, 3));
  tab = sort_int_tab(cut_word(str, 3));
  return (0);
}

int		receive_ask_player(char *str, t_ai *ai)
{
  printf("demande de joueurs recue\n");
  return (0);
}

int		receive_my_ress(char *str, t_ai *ai)
{
  printf("un joueur a les ressource\n");
  return (0);
}
