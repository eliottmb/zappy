/*
** ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Wed Jun 21 17:34:27 2017 Albatard
** Last update Thu Jun 29 17:16:52 2017 Albatard
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

void	take_object(int fd)
{
  dprintf(fd, "Take 0\n");
}

void	set_object(int fd)
{
  dprintf(fd, "Set 0\n");
}

void	incantation(int fd)
{
  dprintf(fd, "Incantation\n");
}

void	connect_nbr(int fd)
{
  dprintf(fd, "Connect_nbr\n");
}

void	broadcast_text(int fd)
{
  dprintf(fd, "Broadcast text\n");
}

void	call(int fd)
{
  look(fd);
  inventory(fd);
  forward(fd);
  right(fd);
  left(fd);
  forkk(fd);
  eject(fd);
  take_object(fd);
  set_object(fd);
  incantation(fd);
  connect_nbr(fd);
  broadcast_text(fd);
}
