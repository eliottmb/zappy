/*
** map.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:33:55 2017 eliott m-barali
** Last update Mon Jun 19 14:52:25 2017 eliott m-barali
*/

#include "map.h"

t_map		*fill_map(t_map *map, int nb_tiles)
{
  int		food;
  int		i;
  int		j;

  food = 60 * nb_tiles;
  i = 0;
  j = 0;
  srand(time(NULL));
  while (i <= food * LIN_RATE / 100)
    {
      j = rand() % nb_tiles;
      map[j].lin = map[j].lin + 1;
      i = i + 1;
    }
  return (map);
}

t_map		*init_map(int x_size, int y_size, int nb_player_max)
{
  t_map		*map;
  int		i;

  i = 0;
  if ((map = malloc(sizeof(t_map) * x_size * y_size)) == NULL)
    return (NULL);
  while (i != x_size * y_size)
    {
      map[i].x_max = x_size;
      map[i].y_max = y_size;
      map[i].x = i%x_size - 1;
      map[i].y = i/x_size;
      map[i].lin = 0;
      map[i].der = 0;
      map[i].sib = 0;
      map[i].men = 0;
      map[i].phi = 0;
      map[i].thy = 0;
      map[i].food = 0;
      ++i;
    }
  fill_map(map, x_size * y_size);
  return (map);
}

int		main()
{

  return (0);
}
