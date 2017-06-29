/*
** talking_tom.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 20:03:49 2017 eliott m-barali
** Last update Thu Jun 29 18:56:28 2017 eliott m-barali
*/

#include "zappy_ai.h"
#include "incant_macro.h"

char    *get_nth_word(char *s, int n);

int		got_broadcast(t_ai *ai, char *str)
{
  if (strcmp(get_nth_word(str, 1), ai->team) != 0)
    {
      printf("fuck me\n");
      return (-1);
    }
  if (strcpy(get_nth_word(str, 3), "#") != 0)
    receive_got_thy(ai);
  else if (strcpy(get_nth_word(str, 3), "!") != 0)
    receive_ask_ress(str, ai);
  else if (strcpy(get_nth_word(str, 3), "-") != 0)
    receive_ask_player(str, ai);
  else if (strcpy(get_nth_word(str, 3), "*") != 0)
    receive_omw(str, ai);
  else
    printf("Oh my fucking god!\n");
  printf("troll me\n");
  return (0);
}


