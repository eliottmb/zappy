/*
** help_serv.c for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 11:45:39 2017 Romain HUET
** Last update Thu Jun 29 17:15:15 2017 Romain HUET
*/

#include "zappy_server.h"

void	help_server()
{
  printf("USAGE:  ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
  printf("\tport\t  is the port number\n");
  printf("\twidth\t  is the width of the world\n");
  printf("\theight\t  is the height of the world\n");
  printf("\tnameX\t  is the name if the team X\n");
  printf("\tclientsNb is the number of authorized clients per team\n");
  printf("\tfreq\t  is the reciprocal of time unit for execution of actions\n\n");
}
