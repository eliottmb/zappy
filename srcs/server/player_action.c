/*
** player_action.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Thu Jun 22 16:49:51 2017 eliott m-barali
** Last update Tue Jun 27 19:22:42 2017 Romain HUET
*/

#include "server/zappy_server.h"

/* int	player_expell(void *player, void *server, int no) */
/* { */
/*   t_player	*tmp; */
/*   t_server	*serv; */

/*   no = no; */
/*   tmp = (t_player *)player; */
/*   serv = (t_server *)server; */
/*   dprintf(serv->graph_cli_fd, "pex #%d\n", tmp->n); */
/*   return (0); */
/* } */

/* int	player_broadcast(void *player, void *server, char *str, int no) */
/* { */
/*   t_player	*tmp; */
/*   t_server	*serv; */

/*   no = no; */
/*   tmp = (t_player *)player; */
/*   serv = (t_server *)server; */
/*   dprintf(serv->graph_cli_fd, "pbc #%d %s\n", tmp->n, str); */
/*   return (0); */
/* } */

/* int	player_begin_incantation(void *player, void *server, int j) */
/* { */
/*   int		i; */
/*   t_player	*tmp; */
/*   t_server	*serv; */

/*   i = 0; */
/*   tmp = (t_player *)player; */
/*   serv = (t_server *)server; */
/*   dprintf(serv->graph_cli_fd, "pic %d %d %d", tmp[j].x, tmp[j].y, tmp[j].lvl); */
/*   while (tmp[i].fd != -1) */
/*     { */
/*       if (tmp[i].x == tmp[j].x && tmp[i].y == tmp[j].y) */
/* 	  dprintf(fd, " #%d", tmp[i].n); */
/*       i = i + 1; */
/*     } */
/*   dprintf(fd, "\n"); */
/*   return (0); */
/* } */

/* int	player_end_incantation(int fd, void *player, int r) */
/* { */
/*   t_player	*tmp; */
  
/*   tmp = (t_player *)player; */
/*   dprintf(fd, "pie %d %d %d\n", tmp->x, tmp->y, r); */
/*   return (0); */
/* } */


/* int	player_spawn_egg(int fd, void *player) */
/* { */
/*   t_player	*tmp; */
  
/*   tmp = (t_player *)player; */
/*   dprintf(fd, "pfk #%d\n", tmp->n); */
/*   return (0); */
/* } */

/* int	player_take_ress(int fd, void *player, int i) */
/* { */
/*   t_player	*tmp; */
  
/*   tmp = (t_player *)player; */
/*   dprintf(fd, "pgt #%d %d\n", tmp->n, i); */
/*   return (0); */
/* } */

/* int	player_drop_ress(int fd, void *player, int i) */
/* { */
/*   t_player	*tmp; */
  
/*   tmp = (t_player *)player; */
/*   dprintf(fd, "pdr #%d %d\n", tmp->n, i); */
/*   return (0); */
/* } */

/* int	player_tragically_dies(int fd, void *player) */
/* { */
/*   t_player	*tmp; */
  
/*   tmp = (t_player *)player; */
/*   dprintf(fd, "pdi #%d\n", tmp->n); */
/*   return (0); */
/* } */
