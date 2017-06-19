/*
** player.h for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Mon Jun 19 18:55:07 2017 Médéric Unissart
** Last update Mon Jun 19 19:22:16 2017 Médéric Unissart
*/

#ifndef PLAYER_H_
# define PLAYER_H_

typedef struct	s_player
{
  int		x;
  int		y;
  int		life;
  int		direction;
  int		id;
  int		inventory[7];
  char		*team;
}		t_player;

typedef struct	s_egg
{
  int		x;
  int		y;
  int		countdown;
  char		*team;
}		t_egg;

t_player	*init_player(char *team, int x, int y);
int		player_is_alive(t_player *player);
t_egg		*new_egg(char *team, int x, int y);

#endif /* !PLAYER_H_ */
