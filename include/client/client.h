/*
** client.h for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Mon Jun 19 18:01:57 2017 Albatard
** Last update Wed Jun 28 16:31:33 2017 Albatard
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "moniteur.h"

typedef struct	s_client
{
  int	port;
  char	*ip;
  char	*name;
}		client_info;

void	check_cmd(int fd, client_info *info);
int	check_number(char *str);
int	usage(int ac, char **av);
int	check_args(int ac, char **av);
int	my_error(int ac, char **av);
void	client_fd(int fd);
void	call(int fd);
char	*my_strtowordtab(char *str);

#endif /* !CLIENT_H_ */
