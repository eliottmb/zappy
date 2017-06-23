/*
** settings.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Fri Jun 23 11:20:12 2017 eliott m-barali
** Last update Fri Jun 23 17:32:20 2017 eliott m-barali
*/

#include "server/zappy_server.h"

int	server_time(int fd, void *args)
{
  t_args	*tmp;

  tmp = (t_args *)args;
  dprintf(fd, "sgt %d\n", tmp->f);
  return (0);
}

int	server_game_win(int fd, void *str)
{
  char	*tmp;

  tmp = (char *)str;
  dprintf(fd, "seg %s\n", tmp);
  return (0);
}

int	server_message(int fd, void *str)
{
  char	*tmp;

  tmp = (char *)str;
  dprintf(fd, "smg %s\n", tmp);
  return (0);
}

int	server_unknown_command(int fd, void *str)
{
  dprintf(fd, "suc\n");
  return (0);
}

int	server_bad_param(int fd, void *str)
{
  dprintf(fd, "sbp\n");
  return (0);
}

