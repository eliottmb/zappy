/*
** map.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:33:55 2017 eliott m-barali
** Last update Wed Jun 21 19:39:49 2017 eliott m-barali
*/

#include "../../include/server/map.h"

void		show_map(t_map **map)
{
  int		i;

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

static void	fill_map_lindersib(t_map **map, int nb_tiles, int food)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i <= food * LIN_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j / map[0][0].x_max][j % map[0][0].x_max].res[1];
      ++i;
    }
  i = 0;
  while (i <= food * DER_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j / map[0][0].x_max][j % map[0][0].x_max].res[2];
      ++i;
    }
  i = 0;
  while (i <= food * SIB_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j / map[0][0].x_max][j % map[0][0].x_max].res[3];
      ++i;
    }
}

static void	fill_map_menphithy(t_map **map, int nb_tiles, int food)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (i <= food * MEN_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j / map[0][0].x_max][j % map[0][0].x_max].res[4];
      ++i;
    }
  i = 0;
  while (i <= food * PHI_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j / map[0][0].x_max][j % map[0][0].x_max].res[5];
      ++i;
    }
  i = 0;
  while (i <= food * THY_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j / map[0][0].x_max][j % map[0][0].x_max].res[6];
      ++i;
    }
}

static void	fill_map_food(t_map **map, int nb_tiles, int food)
{
  int		i;
  int		j;
  
  i = 0;
  j = 0;
  while (i <= food)
    {
      j = rand() % nb_tiles;
      ++map[j / map[0][0].x_max][j % map[0][0].x_max].res[0];
      ++i;
    }
}

static void	init_map_by_line(t_map **map, int x_size, int y_size, int y)
{
  int		x;
  int		o;

  x = 0;
  while (x != x_size)
    {
      o = 0;
      while (o != 7)
	map[y][x].res[o++] = 0;
      map[y][x].x = x;
      map[y][x].y = y;
      map[y][x].x_max = x_size;
      map[y][x++].y_max = y_size;
    }
}

t_map		**init_map(int x_size, int y_size, int nb_player_max)
{
  t_map		**map;
  int		y;

  srand(time(NULL));
  if (!(map = malloc(sizeof(t_map *) * y_size)))
    return (NULL);
  y = 0;
  while (y != y_size)
    {
      if (!(map[y] = malloc(sizeof(t_map) * x_size)))
	return (NULL);
      init_map_by_line(map, x_size, y_size, y);
      ++y;
    }
  fill_map_lindersib(map, x_size * y_size, 60 * nb_player_max);
  fill_map_menphithy(map, x_size * y_size, 60 * nb_player_max);
  fill_map_food(map, x_size * y_size, 60 * nb_player_max);
  return (map);
}

/* int		main() */
/* { */
/*   t_map		**map; */

/*   map = init_map(10, 10, 16); */
/*   show_map(map); */
/*   return (0); */
/* } */
