/*
** ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Wed Jun 21 17:34:27 2017 Albatard
** Last update Sat Jul  1 19:06:57 2017 Albatard
*/

#include "client.h"

void	look(int fd)
{
  dprintf(fd, "Look\n");
}

void	inventory(int fd)
{
  dprintf(fd, "Inventory\n");
}

void	forward(int fd)
{
  dprintf(fd, "Forward\n");
}

void	right(int fd)
{
  dprintf(fd, "Right\n");
}

void	left(int fd)
{
  dprintf(fd, "Left\n");
}

void	forkk(int fd)
{
  dprintf(fd, "Fork\n");
}

void	eject(int fd)
{
  dprintf(fd, "Eject\n");
}

void	take_object(int fd, char *str)
{
  dprintf(fd, "Take %s\n", str);
}

void	set_object(int fd, char *str)
{
  dprintf(fd, "Set %s\n", str);
}

void	incantation(int fd)
{
  dprintf(fd, "Incantation\n");
}

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

void	turn_left(int fd)
{
  forward(fd);
  left(fd);
}

void	turn_right(int fd)
{
  forward(fd);
  right(fd);
}

void	call(int fd)
{
  forward(fd);
  right(fd);
  left(fd);
  set_object(fd, "deraumere");
  look(fd);
  inventory(fd);
  take_object(fd, "food");
  look(fd);
  inventory(fd);
  incantation(fd);
  connect_nbr(fd);
  broadcast_text(fd, "OKOK");
  forkk(fd);
  eject(fd);

}
