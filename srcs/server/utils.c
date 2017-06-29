/*
** utils.c for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 20:10:31 2017 Romain HUET
** Last update Thu Jun 29 17:22:44 2017 Romain HUET
*/

#include "zappy_server.h"

int	is_num(char *s)
{
  int	i;

  i = 0;
  if (!s)
    return (0);
  while (s[i])
    {
      if (s[i] < '0' || s[i] > '9')
	return (0);
      i++;
    }
  return (1);
}


