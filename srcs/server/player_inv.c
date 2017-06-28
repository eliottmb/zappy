/*
** player_inv.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 17:36:06 2017 Médéric Unissart
** Last update Wed Jun 28 15:49:50 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

bool		player_take_item(t_player *player, t_tile **map, int item)
{
  if (map[player->y][player->x].res[item] < 1)
    return (false);
  map[player->y][player->x].res[item] -= 1;
  player->i[item] += 1;
  return (true);
}

bool		player_drop_item(t_player *player, t_tile **map, int item)
{
  if (player->i[item] < 1)
    return (false);
  map[player->y][player->x].res[item] += 1;
  player->i[item] -= 1;
  return (true);
}

char		*player_ask_inventory(t_player *player)
{
  char		*inv;
  char		check[128];
  int		i;

  i = sprintf(check, "[food %d, linemae %d, deraumere %d, sibur %d, mendiane"
	      " %d, phiras %d, thystame %d]\n", player->i[0],
	      player->i[1], player->i[2], player->i[3],
	      player->i[4], player->i[5], player->i[6]);
  if (!(inv = malloc(sizeof(char) * (i + 1))))
    return (NULL);
  sprintf(inv, "[food %d, linemae %d, deraumere %d, sibur %d, mendiane %d"
	  ", phiras %d, thystame %d]\n", player->i[0],
	  player->i[1], player->i[2], player->i[3],
	  player->i[4], player->i[5], player->i[6]);
  return (inv);
}
