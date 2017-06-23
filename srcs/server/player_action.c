/*
** player_action.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Thu Jun 22 16:49:51 2017 eliott m-barali
** Last update Fri Jun 23 17:26:12 2017 eliott m-barali
*/

#include "server/zappy_server.h"

int	player_expell(int fd, void *player)
{
  t_player	*tmp;
  
  tmp = (t_player *)player;
  dprintf(fd, "pex #%d\n", tmp->id);
  return (0);
}

/* int	player_broadcast(int fd, void *player) */
/* { */
/*     t_player	*tmp;
       
       tmp = (t_player *)player;
       dprintf(fd, "pbc #%d %s\n", tmp->id); */
/*   return (0); */
/* } */

/* int	player_begin_incantation(int fd, void *player) */
/* { */
/*     t_player	*tmp;

  tmp = (t_player *)player;
dprintf(fd, "pbc #%d %s\n", tmp->id); */
/*   return (0); */
/* } */

/* int	player_end_incantation(int fd, void *player, int r) */
/* { */
/*   d  t_player	*tmp;

  tmp = (t_player *)player;
printf(fd, "pie %d %d %d\n", tmp->x, tmp->y, r); */
/*   return (0); */
/* } */


int	player_spawn_egg(int fd, void *player)
{
  t_player	*tmp;

  tmp = (t_player *)player;
  dprintf(fd, "pfk #%d\n", tmp->id);
  return (0);
}

int	player_take_ress(int fd, void *player, int i)
{
  t_player	*tmp;
  
  tmp = (t_player *)player;
  dprintf(fd, "pgt #%d %d\n", tmp->id, i);
  return (0);
}

int	player_drop_ress(int fd, void *player, int i)
{
  t_player	*tmp;
  
  tmp = (t_player *)player;
  dprintf(fd, "pdr #%d %d\n", tmp->id, i);
  return (0);
}

int	player_tragically_die(int fd, void *player)
{
  t_player	*tmp;
  
  tmp = (t_player *)player;
  dprintf(fd, "pdi #%d\n", tmp->id);
  return (0);
}

