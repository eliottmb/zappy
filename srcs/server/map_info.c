/*
** map_info.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 21 17:12:41 2017 eliott m-barali
** Last update Thu Jun 22 18:41:33 2017 Romain HUET
*/

#include "server/zappy_server.h"

int	map_size(int fd, t_tile **map)
{
  dprintf(fd, "msz %d %d\n", map[0][0].x_max, map[0][0].y_max);
  return (0);
}

int	one_tile_content(int fd, t_tile tile)
{
  dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n", tile.x, tile.y, tile.res[0], tile.res[1], tile.res[2], tile.res[3], tile.res[4], tile.res[5], tile.res[6]);
  return (0);
}

int	many_tile_content(int fd, t_tile **map)
{
  int	i;
  int	j;

  i = 0;
  while (i != map[0][0].y_max)
    {
      j = 0;
      while (j != map[0][0].x_max)
	{
	  one_tile_content(fd, map[i][j]);
	  j = j + 1;
	}
      i = i + 1;
    }
}

/* int	main() */
/* { */
/*   t_map	**map; */

/*   map = init_map(5, 5, 1); */
/*   map_size(1, map); */
/*   many_tile_content(1, map); */
/*   return (0); */
/* } */
