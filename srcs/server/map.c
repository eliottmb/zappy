/*
** map.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:33:55 2017 eliott m-barali
** Last update Wed Jun 28 15:48:44 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

static void	fill_map_lindersib(t_tile **map, int nb_tiles, int food)
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

static void	fill_map_menphithy(t_tile **map, int nb_tiles, int food)
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

static void	fill_map_food(t_tile **map, int nb_tiles, int food)
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

static void	init_map_by_line(t_tile **map, int x_size, int y_size, int y)
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

t_tile		**init_map(int x_size, int y_size, int nb_player_max)
{
  t_tile	**map;
  int		y;

  srand(time(NULL));
  if (!(map = malloc(sizeof(t_tile *) * y_size)))
    return (NULL);
  y = 0;
  while (y != y_size)
    {
      if (!(map[y] = malloc(sizeof(t_tile) * x_size)))
	return (NULL);
      init_map_by_line(map, x_size, y_size, y);
      ++y;
    }
  fill_map_lindersib(map, x_size * y_size, 60 * nb_player_max);
  fill_map_menphithy(map, x_size * y_size, 60 * nb_player_max);
  fill_map_food(map, x_size * y_size, 60 * nb_player_max);
  return (map);
}
