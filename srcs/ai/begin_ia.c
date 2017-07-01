/*
** init_ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/srcs/ai
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 30 19:25:50 2017 Albatard
** Last update Sun Jul  2 01:26:22 2017 Albatard
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

  while (joueur->lvl != 2)
    {
      look(fd);
      take_object(fd, inv[0].ndr);
      inventory(fd);
      str = read_cmd(fd);
      printf("%s\n", str);
      if (str[0] == '[')
	loinv(str, joueur, inv, fd);
      turn_around(fd);
      turn_right(fd);
      turn_left(fd);
    }
  
}

void	begin(int fd, client_info *info, t_ai *joueur, t_inv *inv)
{
  dprintf(fd, "Broadcast %s 1 Hello\n", info->name);
  if (read_broadcast("Hello I'm Your Chief", fd) == 1)
    ;//IA
  else
    lvl1(fd, joueur, inv);
  dprintf(fd, "Broadcast %s 2 %d\n", info->name, inv[0].i);
  if (read_broadcast("Hello I'm Your Chief", fd) == 1)
    ;//IA
  else
    ;//CDG
}
