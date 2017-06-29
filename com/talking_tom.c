/*
** talking_tom.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 20:03:49 2017 eliott m-barali
** Last update Thu Jun 29 17:21:00 2017 eliott m-barali
*/

#include "zappy_ai.h"
#include "incant_macro.h"

char    *get_nth_word(char *s, int n);

void		got_thy(t_ai *ai)
{
  dprintf(ai->fd, "%s #\n", ai->team);
}

int		receive_omw(char *str, t_ai *ai)
{

  return (0);
}

int		got_broadcast(t_ai *ai, char *str)
{
  if (strcpy(get_nth_word(str, 1), ai->team) != 0)
    return (-1);
  if (strcpy(get_nth_word(str, 2), "#") != 0)
    receive_got_thy(ai);
  else if (strcpy(get_nth_word(str, 2), "?") != 0)
    receive_ask_level(ai);
  else if (strcpy(get_nth_word(str, 2), "!") != 0)
    receive_ask_ress(str, ai);
  else if (strcpy(get_nth_word(str, 2), "-") != 0)
    receive_ask_player(str, ai);
  else if (strcpy(get_nth_word(str, 2), "_") != 0)
    receive_answer_lvl(str, ai);
  else if (strcpy(get_nth_word(str, 2), "*") != 0)
    receive_omw(str, ai);
  else
    printf("Oh my fucking god!\n");
  return (0);
}


