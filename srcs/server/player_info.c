/*
** player_info.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 21 17:47:26 2017 eliott m-barali
** Last update Sun Jul  2 16:16:20 2017 Médéric Unissart
*/

#include "zappy_server.h"

int		team_name(int fd, void *server)
{
  int		i;
  t_server	*tmp;
  
  i = 0;
  tmp = (t_server *)server;
  while (tmp->teams[i].name != NULL)
    {
      dprintf(fd, "tna %s\n", tmp->teams[i].name);
      i = i + 1;
    }  
  return (0);
}

int		new_player_connection(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "pnw %d %d %d %d %d %s\n", tmp->n, tmp->y,
	  tmp->x, tmp->o, tmp->lvl, tmp->team);
  return (0);
}

int		player_position(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "ppo %d %d %d %d\n", tmp->n, tmp->y, tmp->x, tmp->o);
  return (0);
}

int		player_level(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "plv %d %d\n", tmp->n, tmp->lvl);
  return (0);
}

void		player_build(void *player, void *server)
{
  t_player	*tmp;
  t_server	*serv;

  tmp = (t_player *)player;
  serv = (t_server *)server;
  dprintf(serv->graph_cli_fd, "pin %d %d %d %d %d %d %d %d %d %d\n",
	  tmp->n,  tmp->y, tmp->x, tmp->i[0], tmp->i[1], tmp->i[2],
	  tmp->i[3], tmp->i[4], tmp->i[5], tmp->i[6]);
}

void		player_inventory(void *player, void *server, int no)
{
  t_player	*p;

  p = (t_player *)player;
  server = server;
  no = no;
  init_msg_timer(server, p, 4, -1);
}
