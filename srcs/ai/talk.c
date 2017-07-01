/*
** talk.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/com
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Fri Jun 30 19:23:20 2017 eliott m-barali
** Last update Sat Jul  1 14:01:20 2017 eliott m-barali
*/

#include "../../include/ai/zappy_ai.h"

char    *get_nth_word(char *s, int n);

void		ask_ress(t_ai *ai, int *ress)
{
  int		i;

  i = 0;
  dprintf(ai->fd, "%s %d %d !", ai->team, ai->lvl, ai->num_player);
  while (i != 7)
    {
      dprintf(ai->fd, " %d", ress[i]);
      i = i + 1;
    }
  dprintf(ai->fd, "\n");
}

void		ask_more_players(t_ai *ai, int *players)
{
  int		i;

  i = 0;
  dprintf(ai->fd, "%s %d %d -", ai->team, ai->lvl, ai->num_player);
  while (i != 20)
    {
      if (players[i] > 0 && players[i] < 8)
	dprintf(ai->fd, " %d", players[i]);
      i = i + 1;
    }
  dprintf(ai->fd, "\n");
}

void		my_ress(t_ai *ai, int *ress)
{
  int		i;

  i = 0;
  dprintf(ai->fd, "%s %d %d *", ai->team, ai->lvl, ai->num_player);
  while (i != 7)
    {
      dprintf(ai->fd, " %d", ress[i]);
      i = i + 1;
    }
  dprintf(ai->fd, "\n");
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


