/*
** player_inv.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 17:36:06 2017 Médéric Unissart
** Last update Wed Jun 21 17:45:53 2017 Médéric Unissart
*/

#include "player.h"

bool		player_take_item(t_player *player, t_map **map, int item)
{
  if (map[player->y][player->x].res[item] < 1)
    return (false);
  map[player->y][player->x].res[item] -= 1;
  player->inventory[item] += 1;
  return (true);
}

bool		player_drop_item(t_player *player, t_map **map, int item)
{
  if (player->inventory[item] < 1)
    return (false);
  map[player->y][player->x].res[item] += 1;
  player->inventory[item] -= 1;
  return (true);
}
