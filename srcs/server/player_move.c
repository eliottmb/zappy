/*
** player_interaction.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 17:15:09 2017 Médéric Unissart
** Last update Wed Jun 28 15:50:30 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

void		player_turn_left(t_player *player)
{
  if (player->o == NORTH)
    player->o = WEST;
  else
    player->o -= 1;
}

void		player_turn_right(t_player *player)
{
  if (player->o == WEST)
    player->o = NORTH;
  else
    player->o += 1;
}

void		player_forward(t_player *player, t_tile **map)
{
  if (player->o == NORTH || player->o == SOUTH)
    (player->o == NORTH) ? (player->y -= 1) : (player->y += 1);
  else
    (player->o == WEST) ? (player->x -= 1) : (player->x += 1);
  (player->x < 0) ? (player->x = map[0][0].x_max - 1) : (0);
  (player->x > map[0][0].x_max - 1) ? (player->x = 0) : (0);
  (player->y < 0) ? (player->y = map[0][0].y_max - 1) : (0);
  (player->y > map[0][0].y_max - 1) ? (player->y = 0) : (0);
}
