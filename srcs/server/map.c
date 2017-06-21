/*
** map.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:33:55 2017 eliott m-barali
** Last update Wed Jun 21 15:09:53 2017 Médéric Unissart
*/

#include "../../include/server/map.h"

void		show_map(t_map *map)
{
  int		i;

  i = 0;
  while (i < map[0].x_max * map[0].y_max)
    {
      printf("case n°%d: x = %d, y = %d, nb_lin = %d, nb_der = %d, nb_sib = %d,\
nb_men = %d, nb_phi = %d, nb_thy = %d, nb_food = %d\n", i\
	     , map[i].x, map[i].y, map[i].res[1], map[i].res[2], map[i].res[3], map[i].res[4]
	     , map[i].res[5], map[i].res[6], map[i].res[0]);
      i = i + 1;
    }
}

void		fill_map(t_map *map, int nb_tiles, int food)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i <= food * LIN_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].[1];
      ++i;
    }
  i = 0;
  while (i <= food * DER_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].[2];
      ++i;
    }
  i = 0;
  while (i <= food * SIB_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].[3];
      ++i;
    }
}

void		fill(t_map *map, int nb_tiles, int food)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i <= food * MEN_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].res[4];
      ++i;
    }
  i = 0;
  while (i <= food * PHI_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].[5];
      ++i;
    }
  i = 0;
  while (i <= food * THY_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].[6];
      ++i;
    }
}

void		food(t_map *map, int nb_tiles, int food)
{
  int		i;
  int		j;
  
  i = 0;
  j = 0;
  while (i <= food)
    {
      j = rand() % nb_tiles;
      ++map[j].res[0];
      ++i;
    }
}

t_map		*init_map(int x_size, int y_size, int nb_player_max)
{
  t_map		*map;
  int		i;
  int		o;

  i = 0;
  srand(time(NULL));
  if ((map = malloc(sizeof(t_map) * x_size * y_size)) == NULL)
    return (NULL);
  while (i != x_size * y_size)
    {
      map[i].x_max = x_size;
      map[i].y_max = y_size;
      map[i].x = i%x_size;
      map[i].y = i/x_size;
      o = 0;
      while (o != 7)
	map[i].res[o++] = 0;
      ++i;
    }
  fill_map(map, x_size * y_size, 60 * nb_player_max);
  fill(map, x_size * y_size, 60 * nb_player_max);
  food(map, x_size * y_size, 60 * nb_player_max);
  return (map);
}

int		main()
{
  t_map		*map;

  map = init_map(20, 20, 16);
  show_map(map);
  return (0);
}
