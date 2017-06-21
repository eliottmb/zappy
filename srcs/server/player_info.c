/*
** player_info.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Wed Jun 21 17:47:26 2017 eliott m-barali
** Last update Wed Jun 21 19:37:38 2017 eliott m-barali
*/

#include "../../include/server/player.h"

int	team_name(int fd, t_player *player)
{

  return (0);
}

int	new_player_connection(int fd, t_player *player)
{
  dprintf(fd, "pnw #%d %d %d %d %d %s\n", player->id, player->x, player->y, player->dir, player->lvl, player->team);
  return (0);
}

int	player_position(int fd, t_player *player)
{
  dprintf(fd, "ppo #%d %d %d %d\n", player->id, player->x, player->y, player->dir);
  return (0);
}

int	player_level(int fd, t_player *player)
{
  dprintf(fd, "plv #%d %d\n", player->id, player->lvl);
  return (0);
}

int	player_build(int fd, t_player *player)
{
  dprintf(fd, "pin #%d %d %d %d %d %d %d %d %d %d\n", player->id,  player->x, player->y, player->inventory[0], player->inventory[1], player->inventory[2], player->inventory[3], player->inventory[4], player->inventory[5], player->inventory[6]);
  return (0);
}

int	main()
{
  t_player	*player;

  player =  init_player("lolo", 3, 8);
  new_player_connection(1, player);
  player_position(1, player);
  player_level(1, player);
  player_build(1, player);
  return (0);
}
