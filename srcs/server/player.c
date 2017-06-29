/*
** player.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Mon Jun 19 19:03:40 2017 Médéric Unissart
** Last update Thu Jun 29 17:18:05 2017 Romain HUET
*/

#include "player.h"
#include "zappy_server.h"

t_egg			*new_egg(char *team, int x, int y)
{
  t_egg			*egg;

  if (!(egg = malloc(sizeof(*egg))))
    return (NULL);
  egg->countdown = 600;
  egg->x = x;
  egg->y = y;
  egg->team = team;
  return (egg);
}
