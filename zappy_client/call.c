/*
** ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Wed Jun 21 17:34:27 2017 Albatard
** Last update Tue Jun 27 13:43:44 2017 Albatard
*/

#include <unistd.h>
#include <stdio.h>
#include "client.h"

void	look(int fd)
{
  dprintf(fd, "Look\n");
}

void	inventory(int fd)
{
  dprintf("Inventory\n");
}

void	forward(int fd)
{
  dprintf("Forward\n");
}

void	right(int fd)
{
  dprintf("Right\n");
}

void	left(int fd)
{
  dprintf("Left\n");
}

void	forkk(int fd)
{
  dprintf("Fork\n");
}

void	eject(int fd)
{
  dprintf("Eject\n");
}

void	take_object(int fd)
{
  dprintf("Take object\n");
}

void	set_object(int fd)
{
  dprintf("Set object\n");
}

void	incantation(int fd)
{
  dprintf("Incantation\n");
}

void	connect_nbr(int fd)
{
  dprintf("Connect_nbr\n");
}

void	broadcast_text(int fd)
{
  dprintf("Broadcast text\n");
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
