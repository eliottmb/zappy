/*
** receive.c for y in /home/goepfe_a/graphic
** 
** Made by alexandre goepfert
** Login   <goepfe_a@epitech.net>
** 
** Started on  Sun Jul  2 19:11:13 2017 alexandre goepfert
** Last update Sun Jul  2 19:11:45 2017 alexandre goepfert
*/

#include "moniteur.h"
#include <sys/socket.h>

int	receive2(t_bmp	*stru, int fd, char buffer[100])
{
  int	i;
  char	buff[1];

  i = 1;
  while(i != 100)
    {
      if (recv(fd, buff, 1, MSG_DONTWAIT) >= 0)
	buffer[i] = buff[0];
      if(buff[0] == '\n')
	break;
      i++;
    }
  buffer[i] = '\0';
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
	free_all(stru);
      buffer[0] = buff[0];
      return(receive2(stru, fd, buffer));
    }
return(0);
}

void	display_back(t_bmp  *struc)
{
SDL_Surface     *trantor;
SDL_Surface     *bouftou;
SDL_Rect	position;

trantor = SDL_LoadBMP("srcs/client/graphic/imgs/canvas.bmp");
bouftou = SDL_LoadBMP("srcs/client/graphic/imgs/bouftou.bmp");
SDL_SetColorKey(trantor, SDL_SRCCOLORKEY, SDL_MapRGB(trantor->format, 0, 0, 0));
SDL_SetColorKey(bouftou, SDL_SRCCOLORKEY, SDL_MapRGB(bouftou->format, 0, 0, 0));
position.x = 13;
position.y = 10;
SDL_BlitSurface(bouftou, NULL, struc->ecran, &position);
position.x = 1400;
position.y = 10;
SDL_BlitSurface(trantor, NULL, struc->ecran, &position);
}