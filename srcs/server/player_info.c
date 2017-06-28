/*
** player_info.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 21 17:47:26 2017 eliott m-barali
** Last update Wed Jun 28 15:49:42 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

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

int	new_player_connection(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "pnw #%d %d %d %d %d %s\n", tmp->n, tmp->x, tmp->y, tmp->o, tmp->lvl, tmp->team);
  return (0);
}

int	player_position(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "ppo #%d %d %d %d\n", tmp->n, tmp->x, tmp->y, tmp->o);
  return (0);
}

int	player_level(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "plv #%d %d\n", tmp->n, tmp->lvl);
  return (0);
}

int	player_build(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "pin #%d %d %d %d %d %d %d %d %d %d\n", tmp->n,  tmp->x, tmp->y, tmp->i[0], tmp->i[1], tmp->i[2], tmp->i[3], tmp->i[4], tmp->i[5], tmp->i[6]);
  return (0);
}
