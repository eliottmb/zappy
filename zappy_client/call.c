/*
** ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/zappy_client
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Wed Jun 21 17:34:27 2017 Albatard
** Last update Thu Jun 22 15:36:42 2017 Albatard
*/

#include <unistd.h>
#include <stdio.h>
#include "client.h"

void	look(int fd)
{
  write(fd, "Look", 4);
}

void	inventory(int fd)
{
  write(fd, "Inventory", 9);
}

void	forward(int fd)
{
  write(fd, "Forward", 9);
}

void	right(int fd)
{
  write(fd, "Right", 5);
}

void	left(int fd)
{
  write(fd, "Left", 5);
}

void	forkk(int fd)
{
  write(fd, "Fork", 4);
}

void	eject(int fd)
{
  write(fd, "Eject", 5);
}

void	take_object(int fd)
{
  write(fd, "Take object ", 11);
}

void	set_object(int fd)
{
  write(fd, "Set object", 10);
}

void	incantation(int fd)
{
  write(fd, "Incantation", 11);
}

void	connect_nbr(int fd)
{
  write(fd, "Connect_nbr", 11);
}

void	broadcast_text(int fd)
{
  write(fd, "Broadcast text", 14);
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
