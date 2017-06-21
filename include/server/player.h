/*
** player.h for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Mon Jun 19 18:55:07 2017 Médéric Unissart
** Last update Wed Jun 21 17:45:40 2017 Médéric Unissart
*/

#ifndef PLAYER_H_
# define PLAYER_H_
# include <stdlib.h>
# include <stdbool.h>
# include "map.h"

typedef enum	s_dir
  {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
  }		e_dir;

typedef struct	s_player
{
  int		x;
  int		y;
  int		life;
  e_dir		dir;
  int		id;
  int		inventory[7];
  char		*team;
  int		lvl;
  bool		incantating;
  bool		broadcasting;
}		t_player;

typedef struct	s_egg
{
  int		x;
  int		y;
  int		countdown;
  char		*team;
}		t_egg;

/* player.c */

t_player	*init_player(char *team, int x, int y);
t_egg		*new_egg(char *team, int x, int y);

/* player_move.c */

void		player_turn_left(t_player *player);
void		player_turn_right(t_player *player);
void		player_forward(t_player *player, t_map **map);

/* player_in.c */

bool		player_take_item(t_player *player, t_map **map, int item);
bool		player_drop_item(t_player *player, t_map **map, int item);

#endif /* !PLAYER_H_ */
