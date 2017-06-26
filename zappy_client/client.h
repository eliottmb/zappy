/*
** client.h for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Mon Jun 19 18:01:57 2017 Albatard
** Last update Mon Jun 26 17:41:24 2017 Albatard
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef struct	s_client
{
  int	port;
  char	*ip;
  char	*name;
}		client_info;

void	client_fd(int fd);
void	call(int fd);
char	*my_strtowordtab(char *str);

#endif /* !CLIENT_H_ */
