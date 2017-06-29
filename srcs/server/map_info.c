/*
** map_info.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 21 17:12:41 2017 eliott m-barali
** Last update Thu Jun 29 17:16:56 2017 Romain HUET
*/

#include "zappy_server.h"

int	map_size(int fd, void **map)
{
  t_tile	**tmp;

  tmp = (t_tile **)map;
  dprintf(fd, "msz %d %d\n", tmp[0][0].x_max, tmp[0][0].y_max);
  return (0);
}

int	one_tile_content(int fd, void *tile)
{
  t_tile	*tmp;

  tmp = (t_tile *)tile;
  dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n", tmp->x, tmp->y, tmp->res[0], tmp->res[1], tmp->res[2], tmp->res[3], tmp->res[4], tmp->res[5], tmp->res[6]);
  return (0);
}

int	many_tile_content(int fd, void **map)
{
  int	i;
  int	j;
  t_tile	**tmp;

  i = 0;
  tmp = (t_tile **)map;
 while (i != tmp[0][0].y_max)
    {
      j = 0;
      while (j != tmp[0][0].x_max)
	{
	  one_tile_content(fd, &tmp[i][j]);
	  j = j + 1;
	}
      i = i + 1;
    }
 return (0);
}
