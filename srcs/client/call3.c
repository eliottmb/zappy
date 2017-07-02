/*
** call3.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Sun Jul  2 22:38:10 2017 Albatard
** Last update Sun Jul  2 22:38:53 2017 Albatard
*/

#include "client.h"

void    forkk(int fd)
{
  dprintf(fd, "Fork\n");
}

void    eject(int fd)
{
  dprintf(fd, "Eject\n");
}

void    take_object(int fd, char *str)
{
  dprintf(fd, "Take %s\n", str);
}

void    set_object(int fd, char *str)
{
  dprintf(fd, "Set %s\n", str);
}

void    incantation(int fd)
{
  dprintf(fd, "Incantation\n");
}
