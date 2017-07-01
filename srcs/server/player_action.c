/*
** player_action.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Thu Jun 22 16:49:51 2017 eliott m-barali
** Last update Sat Jul  1 17:50:49 2017 Romain HUET
*/

#include "zappy_server.h"

void	player_expell(void *player, void *server, int no)
{
  t_player	*tmp;
  t_server	*serv;

  no = no;
  tmp = (t_player *)player;
  serv = (t_server *)server;
  dprintf(serv->graph_cli_fd, "pex #%d\n", tmp->n);
}

void	player_spawn_egg(void *player, void *server, int no)
{
  t_player	*tmp;
  t_server	*serv;
  
  tmp = (t_player *)player;
  serv = (t_server *)server;
  no = no;
  dprintf(serv->graph_cli_fd, "pfk #%d\n", tmp->n);
}

void	player_take_ress(void *player, void *server, int id)
{
  t_player	*tmp;
  t_server	*serv;
  
  tmp = (t_player *)player;
  serv = (t_server *)server;
  if (serv->map[tmp->x][tmp->y].res[id] > 0)
    {
      tmp->i[id]++;
      serv->map[tmp->x][tmp->y].res[id]--;
      dprintf(serv->graph_cli_fd, "pgt #%d %d\n", tmp->n, id);
      player_build(tmp, serv);
      one_tile_content(serv->graph_cli_fd, &serv->map[tmp->x][tmp->y]);
      dprintf(tmp->fd, "ok\n");
    }
  else
    dprintf(tmp->fd, "ko\n");
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
      serv->map[tmp->x][tmp->y].res[id]++;
      dprintf(serv->graph_cli_fd, "pdr #%d %d\n", tmp->n, id);
      player_build(tmp, serv);
      one_tile_content(serv->graph_cli_fd, &serv->map[tmp->x][tmp->y]);
      dprintf(tmp->fd, "ok\n");
    }
  else
    dprintf(tmp->fd, "ko\n");    
}

int	player_tragically_dies(int fd, void *player)
{
  t_player	*tmp;
  
  tmp = (t_player *)player;
  dprintf(fd, "pdi #%d\n", tmp->n);
  return (0);
}
