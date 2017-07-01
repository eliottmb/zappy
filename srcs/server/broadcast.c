/*
** broadcast.c for zappy in /home/mederic.unissart/rendu/zappy/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Thu Jun 29 16:39:11 2017 Médéric Unissart
** Last update Sat Jul  1 16:22:25 2017 Romain HUET
*/

#include "zappy_server.h"

static void	fill_k_nine(int *k)
{
  k[0] = 2;
  k[1] = 1;
  k[2] = 8;
  k[3] = 3;
  k[4] = 0;
  k[5] = 7;
  k[6] = 4;
  k[7] = 5;
  k[8] = 6;
}

static int	get_k_each_player(t_player *rec, t_player *em)
{
  int		k[9];
  int		x;
  int		y;

  if (rec->x == em->x && rec->y == em->y)
    return (0);
  if ((x = em->x - rec->x) < 0)
    x = -1;
  else if (x > 0)
    x = 1;
  if ((y = em->y - rec->y) < 0)
    y = -1;
  else if (y > 0)
    y = 1;
  x += 1;
  y += 1;
  fill_k_nine(k);
  if ((k[y * 3 + x] + 2 * rec->o) == 8)
    return (8);
  return ((k[y * 3 + x] + 2 * rec->o) % 8);
}

int		player_broadcast(t_player *players,
				 t_server *server,
				 char *msg,
				 int id)
{
  int		i;
  int		k;
  char		*bc_msg;

  i = 0;
  msg = cut_first_word(msg);
  if (!(bc_msg = malloc(sizeof(*bc_msg) * 13 + strlen(msg))))
    return (-1);
  while (i < MAX_PLAYERS)
    {
      if (i != id && players[i].fd > 2)
	{
	  k = get_k_each_player(&players[i], &players[id]);
	  sprintf(bc_msg, "message %d, %s\n", k, msg);
	  msg_timer(players[id].fd, server->f, C_TIM7, bc_msg);
	}
      ++i;
    }
  if (!(bc_msg = realloc(bc_msg, 2)))
    return (-1);
  bc_msg = "ok";
  msg_timer(players[id].fd, server->f, C_TIM7, bc_msg);
  printf("message %d, %s\n", k, msg);
  return (0);
}
