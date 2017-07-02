#include "moniteur.h"
#include <sys/socket.h>

int	receive2(t_bmp	*stru, int fd, char buffer[100])
{
int	i;
char	buff[1];


i = 1;
while(i != 100)
{
//printf("salut\n");
if (recv(fd, buff, 1, MSG_DONTWAIT) >= 0)
buffer[i] = buff[0];
if(buff[0] == '\n')
break;
i++;
   }
buffer[i] = '\0';
printf("%s\n", buffer);
if (my_strcmp(buffer, "ko", '\0') == 0)
return(1);
check(stru, my_strtowordtab(buffer, ' '));
return(0);
}


int    receive(t_bmp *stru, int     fd)
{
  char    buffer[100];
char    buff[1]; 
  int nb;

  nb = 0;
event(stru);
  while(nb != 100)
    {
      buffer[nb] = '\0';
      nb++;
    }
if ((nb = recv(fd, buff, 1, MSG_DONTWAIT)) >= 0)
    {
if (nb == 0)
exit(0);
buffer[0] = buff[0];
return(receive2(stru, fd, buffer));
}
}
