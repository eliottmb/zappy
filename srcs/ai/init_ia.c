/*
** init_ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/srcs/ai
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 30 19:25:50 2017 Albatard
** Last update Fri Jun 30 19:47:07 2017 Albatard
*/

#include <stdio.h>
#include "client.h"

void	lvl1(int fd, client_info *info)
{
  

}

void	begin(int fd, client_info *info)
{
  broadcast_text(fd, "%s 1 HELLO");
  if (read_cmd("Hello I'm Your Chief") == 1)
    //CHEFDEGROUPE;
  else
    lvl1(fd, info);
    //IADEBASE;
}
