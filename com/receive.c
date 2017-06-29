/*
** receive.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 28 19:36:07 2017 eliott m-barali
** Last update Thu Jun 29 18:36:24 2017 eliott m-barali
*/

#include "zappy_ai.h"

int		receive_got_thy(t_ai *ai)
{
  ai->got_thy = 1;
  printf("Thystame trouvé\n");
  return (0);
}

int		receive_ask_ress(char *str, t_ai *ai)
{
  printf("demande de ressource recue\n");
  return (0);
}

int		receive_ask_player(char *str, t_ai *ai)
{
  printf("demande de joueurs recue\n");
  return (0);
}

int		receive_omw(char *str, t_ai *ai)
{
  printf("un joueura les ressource\n");
  return (0);
}
