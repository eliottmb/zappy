
/*
** player_interaction.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 17:15:09 2017 Médéric Unissart
** Last update Sun Jul  2 16:01:55 2017 Médéric Unissart
*/

#include "zappy_server.h"

void		player_turn_left(void *player, void *server, int no)
{
  t_player	*p;
  t_server	*serv;

  no = no;
  p = (t_player *)player;
  serv = (t_server *)server;
  if (p->o == NORTH)
    p->o = WEST;
  else
    p->o -= 1;
  init_msg_timer(serv, player, 2, -1);
}

void		player_turn_right(void *player, void *server, int no)
{
  t_player	*p;
  t_server	*serv;

  no = no;
  p = (t_player *)player;
  serv = (t_server *)server;
  if (p->o == WEST)
    p->o = NORTH;
  else
    p->o += 1;
  init_msg_timer(serv, player, 1, -1);
}

void		player_forward(void *player, void *server, int no)
{
  t_player	*p;
  t_server	*serv;

  no = no;
  p = (t_player *)player;
  serv = (t_server *)server;
  serv->map[p->y][p->x].nb_players--;
  if (p->o == NORTH || p->o == SOUTH)
    (p->o == NORTH) ? (p->y -= 1) : (p->y += 1);
  else
    (p->o == WEST) ? (p->x -= 1) : (p->x += 1);
  (p->x < 0) ? (p->x = serv->map[0][0].x_max - 1) : (0);
  (p->x > serv->map[0][0].x_max - 1) ? (p->x = 0) : (0);
  (p->y < 0) ? (p->y = serv->map[0][0].y_max - 1) : (0);
  (p->y > serv->map[0][0].y_max - 1) ? (p->y = 0) : (0);
  serv->map[p->y][p->x].nb_players++;
  init_msg_timer(server, player, 0, -1);
}
