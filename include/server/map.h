/*
** map.h for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:29:13 2017 eliott m-barali
** Last update Wed Jun 21 15:07:33 2017 Médéric Unissart
*/

#ifndef __MAP_H__
# define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define LIN_RATE 0.23
# define DER_RATE 0.20
# define SIB_RATE 0.26
# define MEN_RATE 0.13
# define PHI_RATE 0.15
# define THY_RATE 0.03

typedef struct	s_map
{
  int		x_max;
  int		y_max;
  int		x;
  int		y;
  int		res[7];
  //joueur	*lolo;
}		t_map;

t_map		*init_map(int x_size, int y_size, int nb_player_max);
void		food(t_map *map, int nb_tiles, int food);
void		fill(t_map *map, int nb_tiles, int food);
void		fill_map(t_map *map, int nb_tiles, int food);
void		show_map(t_map *map);

#endif /* __MAP_H__ */
