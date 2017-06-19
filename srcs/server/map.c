/*
** map.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:33:55 2017 eliott m-barali
** Last update Mon Jun 19 18:17:06 2017 eliott m-barali
*/

#include "../../include/server/map.h"

void		show_map(t_map *map)
{
  int		i;

  i = 0;
  while (i < map[0].x_max * map[0].y_max)
    {
      printf("case n°%d: x = %d, y = %d, nb_lin = %d, nb_der = %d, nb_sib = %d,\
nb_men = %d, nb_phi = %d, nb_thy = %d, nb_food = %d, nb_ress_par_case = %d\n", i\
	     , map[i].x, map[i].y, map[i].lin, map[i].der, map[i].sib, map[i].men\
	     , map[i].phi, map[i].thy, map[i].food, map[i].lin + map[i].der + \
	     map[i].sib + map[i].men + map[i].phi + map[i].thy + map[i].food);
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
      ++map[j].lin;
      ++i;
    }
  i = 0;
  while (i <= food * DER_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].der;
      ++i;
    }
  i = 0;
  while (i <= food * SIB_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].sib;
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
      ++map[j].men;
      ++i;
    }
  i = 0;
  while (i <= food * PHI_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].phi;
      ++i;
    }
  i = 0;
  while (i <= food * THY_RATE)
    {
      j = rand() % nb_tiles;
      ++map[j].thy;
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
      ++map[j].food;
      ++i;
    }
}

t_map		*init_map(int x_size, int y_size, int nb_player_max)
{
  t_map		*map;
  int		i;

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
      map[i].lin = 0;
      map[i].der = 0;
      map[i].sib = 0;
      map[i].men = 0;
      map[i].phi = 0;
      map[i].thy = 0;
      map[i++].food = 0;
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
