/*
** init_ia.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_zappy/srcs/ai
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Fri Jun 30 19:25:50 2017 Albatard
** Last update Sun Jul  2 22:16:50 2017 Albatard
*/

#include <stdio.h>
#include "client.h"

void	loinv(char *str, t_ai *joueur, t_inv *inv)
{
  if (str[1] != ' ')
    parse_look(str, joueur, inv);
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

void	lvl1(t_ai *joueur, t_inv *inv)
{
  char	*str;

  printf("LVL1");
  str = malloc(1048);
  while (joueur->lvl != 2)
    {
      str = calloc(1048, 1);
      str = read_cmd(joueur->fd);
      if (strcmp(str, "Error") != 0)
	{
	  printf("%s\n", str);
	  if (str[0] == '[')
	    loinv(str, joueur, inv);
	}
      look(joueur->fd);
      //      take_object(joueur->fd, inv[0].ndr);
      //      inventory(joueur->fd);
      turn_around(joueur->fd);
      printf("%d\n", joueur->lvl);
    }
  printf("LVL2\n");
  free(str);
}

void	begin(int fd, client_info *info, t_ai *joueur, t_inv *inv)
{
  look(joueur->fd);
  printf("LEVEL1-%d\n", joueur->fd);
  dprintf(fd, "Broadcast %s %d Hello\n", info->name, joueur->lvl);
  lvl1(joueur, inv);
  printf("LEVEL2\n");
  dprintf(fd, "Broadcast %s %d I'm LEVEL 2 Yeah yeah yeah !!!!\n", info->name, joueur->lvl);
}
