/*
** cycle_time.c for zappy in /home/mederic.unissart/rendu/zappy/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Sun Jul  2 19:20:51 2017 Médéric Unissart
** Last update Sun Jul  2 21:54:21 2017 Médéric Unissart
*/

#include "zappy_server.h"

void			dead_player(t_server *server,
				    t_player *player)
{
  dprintf(player->fd, "dead\n");
  dprintf(server->graph_cli_fd, "pdi %d\n", player->n);
  close(player->fd);
  --server->map[player->y][player->x].nb_players;
  player->fd = -1;
}

void			cycle_food(t_server *server,
				   t_player *players,
				   int i)
{
  i = 0;
  while (i < MAX_PLAYERS)
    {
      if (players[i].fd > 2)
	{
	  if (players[i].life > 0)
	    --players[i].life;
	  else
	    {
	      if (players[i].i[0] > 0)
		{
		  --players[i].i[0];
		  players[i].life += 126;
		}
	      else
		dead_player(server, &players[i]);
	    }
	}
      ++i;
    }
}

bool				cycle_set_time(t_server *server, t_player *players)
{
  static struct timespec	ori;
  struct timespec		cur;
  static bool			st = false;
  static float			diff = 0;

  if (st == false)
    {
      clock_gettime(CLOCK_REALTIME, &ori);
      st = true;
      return (true);
    }
  clock_gettime(CLOCK_REALTIME, &cur);
  diff += cur.tv_sec * 1000000000 + cur.tv_nsec
    - ori.tv_sec * 1000000000 - ori.tv_nsec;
  while (diff / (int)(1000000000 / server->f) >= 1)
    {
      diff -= (int)(1000000000 / server->f);
      cycle_food(server, players, 0);
    }
  ori = cur;
  return (true);
}

/* bool			cycle_set_time(t_server *server, t_player *players) */
/* { */
/*   t_serv_msg		*msg; */
/*   timer_t		timerid; */
/*   struct sigevent	sevp; */
/*   struct itimerspec	its; */

/*   if (!(msg = malloc(sizeof(*msg)))) */
/*     return (false); */
/*   msg->server = server; */
/*   msg->player = players; */
/*   msg->res = -8; */
/*   msg->go_to_cmd = &cycle_food; */
/*   sevp.sigev_notify = SIGEV_SIGNAL; */
/*   sevp.sigev_signo = SIGUSR1; */
/*   sevp.sigev_value.sival_ptr = msg; */
/*   if (timer_create(CLOCK_REALTIME, &sevp, &timerid) == -1) */
/*     return (false); */
/*   its.it_value.tv_sec = 4; */
/*   its.it_value.tv_nsec = 0; */
/*   its.it_interval.tv_sec = 0; */
/*   its.it_interval.tv_nsec = (long)((float)1000000000/server->f); */
/*   if (timer_settime(timerid, 0, &its, NULL) == -1) */
/*     return (false); */
/*   return (true); */
/* } */
