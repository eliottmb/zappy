/*
** zappy_ai.h for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 11:58:40 2017 Romain HUET
** Last update Thu Jun 29 15:19:00 2017 Romain HUET
*/

#ifndef AI_H
# define AI_H

#include "../server/zappy_server.h"


typedef struct	s_ai
{
  int		fd;
  int		x_max;
  int		y_max;
  int		*i;	// inventaire
  int		**cdv;  // champs de vision, penser à le realloc selon le niveau de l'ia !
  char		*team;
  int		lvl;
  bool		incantating;
  bool		broadcasting;
  bool		got_thy;
}		t_ai;

#endif /* !AI_H */
