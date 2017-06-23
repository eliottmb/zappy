/*
** player_action.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Thu Jun 22 16:49:51 2017 eliott m-barali
** Last update Thu Jun 22 18:31:07 2017 eliott m-barali
*/

int	player_expell(int fd, t_player *player)
{
  dprintf(fd, "pex #%d\n", player->id);
  return (0);
}

/* int	player_broadcast(int fd, t_player *player) */
/* { */
/*   dprintf(fd, "pbc #%d %s\n", player->id); */
/*   return (0); */
/* } */

/* int	player_begin_incantation(int fd, t_player *player) */
/* { */
/*   dprintf(fd, "pbc #%d %s\n", player->id); */
/*   return (0); */
/* } */

/* int	player_end_incantation(int fd, t_player *player, int r) */
/* { */
/*   dprintf(fd, "pie %d %d %d\n", player->x, player->y, r); */
/*   return (0); */
/* } */


int	player_spawn_egg(int fd, t_player *player)
{
  dprintf(fd, "pfk #%d\n", player->id);
  return (0);
}

int	player_take_ress(int fd, t_player *player, int i)
{
  dprintf(fd, "pgt #%d %d\n", player->id, i);
  return (0);
}

int	player_drop_ress(int fd, t_player *player, int i)
{
  dprintf(fd, "pdr #%d %d\n", player->id, i);
  return (0);
}

int	player_tragically_die(int fd, t_player *player)
{
  dprintf(fd, "pdi #%d\n", player->id);
  return (0);
}

