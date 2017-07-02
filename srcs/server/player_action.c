/*
** player_action.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Thu Jun 22 16:49:51 2017 eliott m-barali
** Last update Sun Jul  2 16:15:53 2017 Médéric Unissart
*/

#include "zappy_server.h"

void	player_expell(void *player, void *server, int no)
{
  t_player	*tmp;
  t_server	*serv;

  no = no;
  tmp = (t_player *)player;
  serv = (t_server *)server;
  dprintf(serv->graph_cli_fd, "pex %d\n", tmp->n);
}

void	player_spawn_egg(void *player, void *server, int no)
{
  t_player	*tmp;
  t_server	*serv;
  
  tmp = (t_player *)player;
  serv = (t_server *)server;
  no = no;
  dprintf(serv->graph_cli_fd, "pfk %d\n", tmp->n);
}

void	player_take_ress(void *player, void *server, int id)
{
  t_player	*tmp;
  t_server	*serv;
  
  tmp = (t_player *)player;
  serv = (t_server *)server;
  if (serv->map[tmp->y][tmp->x].res[id] > 0)
    {
      tmp->i[id]++;
      serv->map[tmp->y][tmp->x].res[id]--;
    }
  else
    id = -1;
  init_msg_timer(server, player, 6, id);
}

void	player_drop_ress(void *player, void *server, int id)
{
  t_player	*tmp;
  t_server	*serv;
  
  tmp = (t_player *)player;
  serv = (t_server *)server;
  if (tmp->i[id] > 0)
    {
      tmp->i[id]--;
      serv->map[tmp->y][tmp->x].res[id]++;
    }
  else
    id = -1;
  init_msg_timer(server, player, 7, id);
}

int	player_tragically_dies(int fd, void *player)
{
  t_player	*tmp;
  
  tmp = (t_player *)player;
  dprintf(fd, "pdi %d\n", tmp->n);
  return (0);
}
