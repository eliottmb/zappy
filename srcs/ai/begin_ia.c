/*
** init_ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/srcs/ai
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 30 19:25:50 2017 Albatard
** Last update Sun Jul  2 21:07:43 2017 Albatard
*/

#include <stdio.h>
#include "client.h"

void	loinv(char *str, t_ai *joueur, t_inv *inv, int fd)
{
  if (str[1] == ' ')
    parse_inventory(str, inv);
  else
    parse_look(str, joueur, inv, fd);
}

void	ia(t_ai *joueur, t_inv *inv)
{
  int	i;
  char	*str;

  i = 0;
  str = malloc(sizeof(char) * 1048);
  while (42)
    {
      take_object(joueur->fd, "food");
      str = calloc(1048, 1);
      str = read_cmd(joueur->fd);
      if (strcmp(str, "Error") == 0)
	break;
      else
	{
	  printf("--->%s\n", str);
	  if (str[0] == '[')
	    loinv(str, joueur, inv, joueur->fd);
	}
      look(joueur->fd);
      inventory(joueur->fd);
      take_object(joueur->fd, "thystame");
      take_object(joueur->fd, "deraumere");
      take_object(joueur->fd, "sibur");
      take_object(joueur->fd, "mendiane");
      take_object(joueur->fd, "phiras");
      turn_around(joueur->fd);
      turn_left(joueur->fd);
      turn_right(joueur->fd);
    }
  free(str);
}

void	takeoncase(int fd, t_ai *joueur, t_inv *inv)
{
  int	j;

  j = 0;
  while (joueur->view[0][j])
    {
      if (joueur->view[0][j] >= 1)
	take_object(fd, inv[j].ndr);
      j++;
    }
}

void	lvl1(int fd, t_ai *joueur, t_inv *inv)
{
  char	*str;

  str = malloc(1048);
  while (joueur->lvl != 2)
    {
      str = calloc(1048, 1);
      str = read_cmd(fd);
      if (strcmp(str, "Error") != 0)
	{
	  printf("--->%s\n", str);
	  if (str[0] == '[')
	    loinv(str, joueur, inv, fd);
	}
      look(fd);
      take_object(fd, inv[0].ndr);
      inventory(fd);
      look(joueur->fd);
      printf("%d\n", joueur->lvl);
    }
  printf("LVL2\n");
  free(str);
}

void	begin(int fd, client_info *info, t_ai *joueur, t_inv *inv)
{
  dprintf(fd, "Broadcast %s %d Hello\n", info->name, joueur->lvl);
  /*  if (read_broadcast("Hello I'm your Chief", joueur->fd) == 1)
    ;//IA

    else*/
    lvl1(fd, joueur, inv);
  dprintf(fd, "Broadcast %s %d Hello\n", info->name, joueur->lvl);
  /*  if (read_broadcast("Hello I'm your Chief", joueur->fd) == 1)
    ;//IA
  else
  ;//CHEFDEGROUPE*/
  dprintf(fd, "Broadcast %s %d %d\n", info->name, joueur->lvl, inv[0].i);
}
