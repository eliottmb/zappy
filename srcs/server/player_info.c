/*
** player_info.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 21 17:47:26 2017 eliott m-barali
** Last update Fri Jun 23 17:33:58 2017 eliott m-barali
*/

#include "server/zappy_server.h"
#include "server/com.h"

int	team_name(int fd, void *args)
{
  int	i;
  t_args *tmp;
  
  i = 0;
  tmp = (t_args *)args;
  while (i != /*args*/tmp->nb_of_teams)
    {
      dprintf(fd, "tna %s\n", /*args*/tmp->names[i]);
      i = i + 1;
    }  
  return (0);
}

int	new_player_connection(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "pnw #%d %d %d %d %d %s\n", tmp->id, tmp->x, tmp->y, tmp->direction, tmp->lvl, tmp->team);
  return (0);
}

int	player_position(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "ppo #%d %d %d %d\n", tmp->id, tmp->x, tmp->y, tmp->direction);
  return (0);
}

int	player_level(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "plv #%d %d\n", tmp->id, tmp->lvl);
  return (0);
}

int	player_build(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "pin #%d %d %d %d %d %d %d %d %d %d\n", tmp->id,  tmp->x, tmp->y, tmp->inventory[0], tmp->inventory[1], tmp->inventory[2], tmp->inventory[3], tmp->inventory[4], tmp->inventory[5], tmp->inventory[6]);
  return (0);
}
