/*
** map.h for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:29:13 2017 eliott m-barali
** Last update Thu Jun 22 18:19:05 2017 Romain HUET
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
}		t_map;

t_map		**init_map(int x_size, int y_size, int nb_player_max);
void		show_map(t_map **map);

#endif /* __MAP_H__ */
