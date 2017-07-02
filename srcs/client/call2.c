/*
** call2.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Sun Jul  2 22:37:24 2017 Albatard
** Last update Sun Jul  2 22:37:45 2017 Albatard
*/

#include "client.h"

void    look(int fd)
{
  dprintf(fd, "Look\n");
}

void    inventory(int fd)
{
  dprintf(fd, "Inventory\n");
}

void    forward(int fd)
{
  dprintf(fd, "Forward\n");
}

void    right(int fd)
{
  dprintf(fd, "Right\n");
}

void    left(int fd)
{
  dprintf(fd, "Left\n");
}
