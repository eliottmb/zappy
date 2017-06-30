/*
** talk.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/com
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Fri Jun 30 19:23:20 2017 eliott m-barali
** Last update Fri Jun 30 20:10:59 2017 eliott m-barali
*/

#include "zappy_ai.h"

char    *get_nth_word(char *s, int n);

void		ask_ress(t_ai *ai, int *ress)
{
  dprintf(ai->fd, "%s %d %d ! %d %d %d %d %d %d %d\n", ai->team, ai->lvl, ai->num_player, ress[0], ress[1], ress[2], ress[3], ress[4], ress[5], ress[6]);
}

void		ask_more_players(t_ai *ai, char *str)
{
  dprintf(ai->fd, "%s %d %d - %s\n", ai->team, ai->lvl, ai->num_player, str);
}

void		my_ress(t_ai *ai, int *ress)
{
  dprintf(ai->fd, "%s %d %d * %d %d %d %d %d %d %d\n", ai->team, ai->lvl, ai->num_player, ress[0], ress[1], ress[2], ress[3], ress[4], ress[5], ress[6]);
}

void		send_sharp(t_ai *ai)
{
  dprintf(ai->fd, "%s %d %d #\n", ai->team, ai->lvl, ai->num_player);
}

int	got_broadcast(t_ai *ai, char *str)
{
  printf("cmp : %s & %s\n", get_nth_word(str, 1), ai->team);
  if (strcmp(get_nth_word(str, 1), ai->team) != 0)
    {
      printf("fuck me\n");
      return (-1);
    }
  printf("jusqu'ici sa va : %s\n", get_nth_word(str, 4));
  if (strcmp(get_nth_word(str, 4), "#") == 0)
    receive_sharp(ai);
  else if (strcmp(get_nth_word(str, 4), "!") == 0)
    receive_ask_ress(str, ai);
  else if (strcmp(get_nth_word(str, 4), "-") == 0)
    receive_ask_player(str, ai);
  else if (strcmp(get_nth_word(str, 4), "*") == 0)
    receive_my_ress(str, ai);
  else
    printf("Oh my fucking god!\n");
  return (0);
}


