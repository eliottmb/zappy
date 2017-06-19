/*
** player.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Mon Jun 19 19:03:40 2017 Médéric Unissart
** Last update Mon Jun 19 19:19:59 2017 Médéric Unissart
*/

#include "player.h"

t_player		*init_player(char *team, int x, int y)
{
  t_player		*player;
  static int		id = 0;
  int			i;

  i = 1;
  player->x = x;
  player->y = y;
  player->life = 126;
  player->direction = rand() % 4;
  player->team = team;
  player->id = id;
  player->inventory[0] = 9;
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

int			player_is_alive(t_player *player)
{
  if (player->life <= 0 && player->inventory[0] >= 1)
    {
      player->life += 126;
      player->inventory[0] -= 1;
      return (1);
    }
  return (0);
}
