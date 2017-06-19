/*
** help_serv.c for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 11:45:39 2017 Romain HUET
** Last update Mon Jun 19 11:50:28 2017 Romain HUET
*/

void	help_server()
{
  printf("USAGE:\t./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq\n");
  printf("\tport\tis the port number\n");
  printf("\twidth\tis the width of the world\n");
  printf("\theight\tis the height of the world\n");
  printf("\tnameX\tis the name if the team X\n");
  printf("\tclientsNb\tis the number of authorized clients per team\n");
  printf("\tfreq\tis the reciprocal of time unit for execution of actions\n");
}
