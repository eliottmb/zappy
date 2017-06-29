/*
** player_action.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Thu Jun 22 16:49:51 2017 eliott m-barali
** Last update Thu Jun 29 16:47:56 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

void	player_expell(void *player, void *server, int no)
{
  t_player	*tmp;
  t_server	*serv;

  no = no;
  tmp = (t_player *)player;
  serv = (t_server *)server;
  dprintf(serv->graph_cli_fd, "pex #%d\n", tmp->n);
}

/* //PAS DANS LE TAB */
/* int	player_broadcast(t_player *player, t_server *server, char *str, int no) */
/* { */
/*   // C MEDERIC QUI SEN OCCUPE LOL */
/*   return (0); */
/* } */

/* //PAS DANS LE TAB */
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
/* 	  dprintf(serv->graph_cli_fd, " #%d", tmp[i].n); */
/*       i = i + 1; */
/*     } */
/*   dprintf(serv->graph_cli_fd, "\n"); */
/*   return (0); */
/* } */

/* int	player_end_incantation(int fd, void *player, int r) */
/* { */
/*   t_player	*tmp; */
  
/*   tmp = (t_player *)player; */
/*   dprintf(fd, "pie %d %d %d\n", tmp->x, tmp->y, r); */
/*   return (0); */
/* } */

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

      
      /* char	*buff = calloc(128, 1);     // TIMING GROS */
      /* sprintf(buff, "pgt #%d %d\n");	    // */
      /* msg_timer(tmp->fd, serv->f, 7, buff); // */
      
      dprintf(serv->graph_cli_fd, "pgt #%d %d\n", tmp->n, id);
      dprintf(tmp->fd, "ok\n");
    }
  else
    {
      /* msg_timer(tmp->fd, serv->f, 7, "ko\n");       // A TESTER */
      dprintf(tmp->fd, "ko\n");
    }
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
      dprintf(tmp->fd, "ok\n");
    }
  else
    dprintf(tmp->fd, "ko\n");    
}

/* int	player_tragically_dies(int fd, void *player) */
/* { */
/*   t_player	*tmp; */
  
/*   tmp = (t_player *)player; */
/*   dprintf(fd, "pdi #%d\n", tmp->n); */
/*   return (0); */
/* } */
