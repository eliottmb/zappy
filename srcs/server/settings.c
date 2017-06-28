/*
** settings.c for  in /home/m-bara_e/rendu/PSU_2016_zappy
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Fri Jun 23 11:20:12 2017 eliott m-barali
** Last update Wed Jun 28 15:47:14 2017 Romain HUET
*/

#include "../../include/server/zappy_server.h"

int	server_time(int fd, void *server)
{
  t_server	*tmp;

  tmp = (t_server *)server;
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
  str = str;
  dprintf(fd, "suc\n");
  return (0);
}

int	server_bad_param(int fd, void *str)
{
  str = str;
  dprintf(fd, "sbp\n");
  return (0);
}

