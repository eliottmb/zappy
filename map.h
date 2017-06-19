/*
** map.h for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:29:13 2017 eliott m-barali
** Last update Mon Jun 19 14:52:59 2017 eliott m-barali
*/

#ifndef __MAP_H__
# define __MAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define LIN_RATE 23
# define DER_RATE 20
# define SIB_RATE 26
# define MEN_RATE 13
# define PHI_RATE 15
# define THY_RATE 3

typedef struct	s_map
{
  int		x_max;
  int		y_max;
  int		x;
  int		y;
  int		lin;
  int		der;
  int		sib;
  int		men;
  int		phi;
  int		thy;
  int		food;
  //joueur	*lolo;
}		t_map;

#endif /* __MAP_H__ */