/*
** show_map.c for  in /home/romain.huet/rendu/PSU_2016_zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Thu Jun 22 18:37:39 2017 Romain HUET
** Last update Thu Jun 29 17:22:35 2017 Romain HUET
*/

#include "zappy_server.h"

void            show_map(t_tile **map)
{
  int           i;

  i = 0;
  while (i < map[0][0].x_max * map[0][0].y_max)
    {
      printf("case n°%d: x = %d, y = %d, nb_lin = %d, nb_der = %d, nb_sib = %d,"
	     "nb_men = %d, nb_phi = %d, nb_thy = %d, nb_food = %d\n", i,
	     map[i / map[0][0].x_max][i % map[0][0].x_max].x,
	     map[i / map[0][0].x_max][i % map[0][0].x_max].y,
	     map[i / map[0][0].x_max][i % map[0][0].x_max].res[1],
	     map[i / map[0][0].x_max][i % map[0][0].x_max].res[2],
	     map[i / map[0][0].x_max][i % map[0][0].x_max].res[3],
	     map[i / map[0][0].x_max][i % map[0][0].x_max].res[4],
	     map[i / map[0][0].x_max][i % map[0][0].x_max].res[5],
	     map[i / map[0][0].x_max][i % map[0][0].x_max].res[6],
	     map[i / map[0][0].x_max][i % map[0][0].x_max].res[0]);
      i = i + 1;
    }
}
