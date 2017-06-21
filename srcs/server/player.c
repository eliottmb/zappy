/*
** player.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Mon Jun 19 19:03:40 2017 Médéric Unissart
** Last update Wed Jun 21 16:42:24 2017 Médéric Unissart
*/

#include "player.h"

t_player		*init_player(char *team, int x, int y)
{
  t_player		*player;
  static int		id = 0;
  int			i;

  i = 0;
  player->x = x;
  player->y = y;
  player->life = 1260;
  player->direction = rand() % 4;
  player->team = team;
  player->id = id;
  while (i != 7)
    player->inventory[i++] = 0;
  return (player);
}

t_egg			*new_egg(char *team, int x, int y)
{
  t_egg			*egg;

  egg->countdown = 600;
  egg->x = x;
  egg->y = y;
  egg->team = team;
}

