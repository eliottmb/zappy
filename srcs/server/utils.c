/*
** utils.c for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 20:10:31 2017 Romain HUET
** Last update Wed Jun 28 15:47:21 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

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


