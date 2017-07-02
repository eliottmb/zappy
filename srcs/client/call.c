/*
** ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Wed Jun 21 17:34:27 2017 Albatard
** Last update Sun Jul  2 23:14:45 2017 Albatard
*/

#include "client.h"

void	connect_nbr(int fd)
{
  dprintf(fd, "Connect_nbr\n");
}

void	broadcast_text(int fd, char *str)
{
  dprintf(fd, "Broadcast %s\n", str);
}

void	turn_around(int fd)
{
  left(fd);
  left(fd);
  forward(fd);
}

void	turn_right(int fd)
{
  forward(fd);
  right(fd);
}

void	call(int fd)
{
  turn_around(fd);
  forward(fd);
  right(fd);
  left(fd);
  //  look(fd);
  inventory(fd);
  take_object(fd, "food");
  //  look(fd);
  inventory(fd);
  incantation(fd);
  connect_nbr(fd);
  broadcast_text(fd, "IT'S A TEST");
  forkk(fd);
  eject(fd);
  turn_right(fd);
  turn_around(fd);
}
