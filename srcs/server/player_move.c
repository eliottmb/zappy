/*
** player_interaction.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 17:15:09 2017 Médéric Unissart
** Last update Wed Jun 21 17:49:24 2017 Médéric Unissart
*/

#include "player.h"

void		player_turn_left(t_player *player)
{
  if (player->dir == NORTH)
    player->dir = WEST;
  else
    player->dir -= 1;
}

void		player_turn_right(t_player *player)
{
  if (player->dir == WEST)
    player->dir = NORTH;
  else
    player->dir += 1;
}

void		player_forward(t_player *player, t_map **map)
{
  if (player->dir == NORTH || player->dir == SOUTH)
    (player->dir == NORTH) ? (player->y -= 1) : (player->y += 1);
  else
    (player->dir == WEST) ? (player->x -= 1) : (player->x += 1);
  (player->x < 0) ? (player->x = map[0][0].x_max - 1) : (0);
  (player->x > map[0][0].x_max - 1) ? (player->x = 0) : (0);
  (player->y < 0) ? (player->y = map[0][0].y_max - 1) : (0);
  (player->y > map[0][0].y_max - 1) ? (player->y = 0) : (0);
}
