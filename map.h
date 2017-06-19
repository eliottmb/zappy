/*
** map.h for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Mon Jun 19 13:29:13 2017 eliott m-barali
** Last update Mon Jun 19 17:40:33 2017 Médéric Unissart
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
