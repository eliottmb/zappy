/*
** ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Wed Jun 21 17:34:27 2017 Albatard
** Last update Mon Jun 26 15:40:26 2017 Albatard
*/

#include <unistd.h>
#include <stdio.h>
#include "client.h"

void	look(int fd)
{
  write(fd, "Look\n", 5);
}

void	inventory(int fd)
{
  write(fd, "Inventory\n", 10);
}

void	forward(int fd)
{
  write(fd, "Forward\n", 8);
}

void	right(int fd)
{
  write(fd, "Right\n", 6);
}

void	left(int fd)
{
  write(fd, "Left\n", 5);
}

void	forkk(int fd)
{
  write(fd, "Fork\n", 5);
}

void	eject(int fd)
{
  write(fd, "Eject\n", 6);
}

void	take_object(int fd)
{
  write(fd, "Take object\n", 11);
}

void	set_object(int fd)
{
  write(fd, "Set object\n", 11);
}

void	incantation(int fd)
{
  write(fd, "Incantation\n", 12);
}

void	connect_nbr(int fd)
{
  write(fd, "Connect_nbr\n", 12);
}

void	broadcast_text(int fd)
{
  write(fd, "Broadcast text\n", 15);
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
