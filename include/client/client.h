/*
** client.h for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Mon Jun 19 18:01:57 2017 Albatard
** Last update Sat Jul  1 23:58:23 2017 Albatard
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
#include "../ai/zappy_ai.h"

typedef struct	s_inv
{
  char		*ndr;
  int		i;
}		t_inv;

typedef struct	s_client
{
  int	port;
  char	*ip;
  char	*name;
}		client_info;

/*
 *
 *CALL
 *
 */

void	look(int);
void	inventory(int);
void	forward(int);
void	right(int);
void	left(int);
void	forkk(int);
void	eject(int);
void	take_object(int, char*);
void	set_object(int, char*);
void	incantation(int);
void	connect_nbr(int);
void	broadcast_text(int, char*);
void	turn_around(int);
void	turn_right(int);
void	turn_left(int);
     

/*
 *
 *CMD
 *
 */
int	read_broadcast(char *str, int fd);
char	*read_cmd(int fd);
void	check_cmd(int fd, client_info *info);
t_inv	*fill(t_inv *);
void    begin(int fd, client_info *info, t_ai *, t_inv *);
/*
 *
 *CHECK
 *
 */

int	check_number(char *str);
int	usage(int ac, char **av);
int	check_args(char **av);
int	my_error(int ac, char **av);
void	client_fd(int fd);
void	call(int fd);

/*
 *
 *LOOK
 *
 */


void	parse(char *str, t_ai *joueur, t_inv *inv, int j);
int	nut(char *str, t_ai *joueur, t_inv *inv, int j);
void    parse_look(char *str, t_ai *joueur, t_inv *inv, int fd);
void    parse_inventory(char *str, t_inv *inv);
void    in(char *str, t_inv **inv);

#endif /* !CLIENT_H_ */
