#include <stdlib.h>
#include "../../../include/client/moniteur.h"
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>

t_func  g_cmd[3] =
 {
    {"msz", &init_case},
    {"bct", &init_map},
    {"pnw", &add_player},
//    {"pdi", &list_del_elem},
 };

void lpause()
{
    int continuer = 1;
    SDL_Event event;
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
} 

void drawEmptyRect(SDL_Surface * surf,int posX, int posY, int width, int length)
{
	SDL_Rect ligneHaut;
	ligneHaut.x = posX-1;
	ligneHaut.y = posY-1;
	ligneHaut.w = length;
	ligneHaut.h = 1;
 
	SDL_FillRect(surf, &ligneHaut, SDL_MapRGB(surf->format, 255, 255, 0));
 
	SDL_Rect ligneDroite;
	ligneDroite.x = posX+length-1;
	ligneDroite.y = posY-1;
	ligneDroite.w = 1;
	ligneDroite.h = width;
 
	SDL_FillRect(surf, &ligneDroite, SDL_MapRGB(surf->format, 255, 255, 0));
 
	SDL_Rect ligneGauche;
	ligneGauche.x = posX-1;
	ligneGauche.y = posY-1;
	ligneGauche.w = 1;
	ligneGauche.h = width;
 
	SDL_FillRect(surf, &ligneGauche, SDL_MapRGB(surf->format, 255, 255, 0));
 
	SDL_Rect ligneBas;
	ligneBas.x = posX-1;
	ligneBas.y = posY+width-1;
	ligneBas.w = length;
	ligneBas.h = 1;
 
	SDL_FillRect(surf, &ligneBas, SDL_MapRGB(surf->format, 255, 255, 0));
}

void     splitRect(int a, int i, SDL_Surface *ecran, int tx, int ty)
{
float   x;
float	y;
float	n;
int     e;

e = 0;
n = 0;
x = a / tx;
y = i / ty;
	while(e != tx + 1)
{		
drawEmptyRect(ecran, 197, 30 + n, 1, i);
n = n + y;
e++;
}
n = 0;
e = 0;
     while(e != ty + 1)
{               
drawEmptyRect(ecran, 197 + n, 30, i, 1);
n = n + x;
e++;
}
}

void	init_gemme(t_bmp *pic)
{
int	i;

i = 0;
pic->gemme[0] = SDL_LoadBMP("srcs/client/graphic/imgs/pomme.bmp");
pic->gemme[1] = SDL_LoadBMP("srcs/client/graphic/imgs/gemme-jaune.bmp");
pic->gemme[2] = SDL_LoadBMP("srcs/client/graphic/imgs/gemme-violet.bmp");
pic->gemme[3] = SDL_LoadBMP("srcs/client/graphic/imgs/gemme-rouge.bmp");
pic->gemme[4] = SDL_LoadBMP("srcs/client/graphic/imgs/gemme-blanc.bmp");
pic->gemme[5] = SDL_LoadBMP("srcs/client/graphic/imgs/gemme-verte.bmp");
pic->gemme[6] = SDL_LoadBMP("srcs/client/graphic/imgs/gemme-bleu.bmp");
while (i != 7)
{
SDL_SetColorKey(pic->gemme[i], SDL_SRCCOLORKEY, SDL_MapRGB(pic->gemme[i]->format, 0, 0, 0));
i++;
}


}

void	init_maprss(t_bmp *pic)
{
int	i;
int	a;
int	n;

i = 0;
a = 0;
n = 0;
while(i != 30)
{
	while(a != 30)
	{	
		while(n != 7)
		{
		//pic->maprss[i][a].rss[n] = 0;
		n++;
		}
	n = 0;
	a++;
	}
a = 0;
i++;
}


}

void	init_sdl(t_bmp *pic)
{
pic->x = 0;
pic->y = 0;
pic->positionFond.x = 0;
pic->positionFond.y = 0;
SDL_Init(SDL_INIT_VIDEO);
 pic->ecran = SDL_SetVideoMode(2000, 2000, 32, SDL_HWSURFACE);
pic->imageDeFond = SDL_LoadBMP("srcs/client/graphic/imgs/grass.bmp");
pic->toad = SDL_LoadBMP("srcs/client/graphic/imgs/toad.bmp");
SDL_SetColorKey(pic->toad, SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad->format, 0, 0, 0));
pic->trantor = SDL_LoadBMP("srcs/client/graphic/imgs/canvas.bmp");
pic->postrantor.x = 1640;
 pic->postrantor.y = 0;
SDL_BlitSurface(pic->trantor, NULL, pic->ecran, &pic->postrantor);
init_maprss(pic);
}

void	add_rss(int	rss[7], int x, int y, t_bmp *pic)
{
int	i;

i = 0;
while (i != 7)
{
pic->maprss[x][y].rss[i] = rss[i];
i++;
}

}



void	display_rss(int  x, int y, int n, t_bmp *pic)
{
if (n == 0 || n == 1 || n == 2)
{
pic->gemmeR[n].x = 197 + x * 98 + 33 * n;
pic->gemmeR[n].y = 30 + y * 98;

}

if (n == 3 || n == 4)
{
pic->gemmeR[n].x = 197 + x * 98 + 33 * (n - 3);
pic->gemmeR[n].y = 30 + y * 98 + 33;

}

if(n == 5 || n == 6)
{
pic->gemmeR[n].x = 197 + x * 98 + 33 * (n - 5);
pic->gemmeR[n].y = 30 + y * 98 + 66;
}
}

void    show_char(int  x, int y, t_bmp *pic)
{
  int     i;
  int     a; 

t_list	cpy;
cpy = pic->inf.us;
  i = x;
  a = y;
  while(cpy)
    {
      //if (pic->inf.us->x > x - 1 && pic->inf.us->x < x + 10)
      if (cpy->x > 0 + x - 1 && cpy->x < x + 10 && cpy->y > 0 + y - 1 && cpy->y < y + 10)
{
      pic->postoad.x = 197 + (cpy->x - 1 - x) * 98 + 150;
      pic->postoad.y = 30 + (cpy->y - y) * 98 + 33;
      cpy = cpy->next;
      SDL_BlitSurface(pic->toad, NULL, pic->ecran, &pic->postoad);
} 
   }

}

void	show_rss(int  x, int y, t_bmp *pic)
{
  int     i;
  int     a;
  int     n;

  i = x;
  a = y;
  n = 0;
  while(i != 10 + x && i != 30)
    {
      while(a != 10 + y && a != 30)
        {       
	  while(n != 7)
	    {
	      if (pic->maprss[i][a].rss[n] > 0)
		{
		  display_rss(i - x, a - y, n, pic);
		  SDL_BlitSurface(pic->gemme[n], NULL, pic->ecran, &pic->gemmeR[n]);
		}
	      n++;
	    }
	  n = 0;
	  a++;
        }
      a = y;
      i++;
    }
}


void	check(t_bmp   *pic, char **buffer)
{
int	i;

i = 0;
while(i != 3)
{
 
if (my_strcmp(buffer[0], g_cmd[i].name, '\0') == 0)
{
g_cmd[i].ptrfunc(pic, buffer);
}
i++;
}

 /*if(my_strcmp(buffer[0], "msz", '\0') == 0)
    init_case(pic, buffer);
  if(my_strcmp(buffer[0], "bct", '\0') == 0)
    init_map(pic, buffer);
if(my_strcmp(buffer[0], "pnw", '\0') == 0)
add_player(pic, buffer);
*/

if(my_strcmp(buffer[0], "pdi", '\0') == 0)

{
list_del_elem(&pic->inf.us, atoi(buffer[1]));
 
}
// if(my_strcmp(buffer[0], "ppo", '\0') == 0)
    //{
  //    add_pos(pic, buffer);
      //printf("CCCC : %d\n", pic->inf.us->x);
    //}
}

void	event(t_bmp *stru)
{
SDL_Event event;

SDL_PollEvent(&event);
if(event.key.keysym.sym == SDLK_UP && stru->y > 0)
stru->y--;
if(event.key.keysym.sym == SDLK_DOWN && stru->y < 29)
stru->y++;
if(event.key.keysym.sym == SDLK_RIGHT && stru->x < 29)
stru->x++;
if(event.key.keysym.sym == SDLK_LEFT && stru->x > 0)
stru->x--;
}

int    receive(t_bmp *stru, int     fd)
{
  char    buffer[100];
char	buff[1]; 
  char	**stock;
  int i;
  int nb;

//buffer = malloc(sizeof(char) * 1000);
  i = 1;
  nb = 0;
event(stru);
  while(nb != 100)
    {
      buffer[nb] = '\0';
      nb++;
    }
if (recv(fd, buff, 1, MSG_DONTWAIT) >= 0)
    {
buffer[0] = buff[0];
while(i != 100)
{
printf("oka\n");
recv(fd, buff, 1, MSG_DONTWAIT);
buffer[i] = buff[0];
if(buff[0] == '\n')
break;
i++;
   }
buffer[i] = '\0';
stock = my_strtowordtab(buffer, ' ');
      printf("BUFFER : %sAAAaA\n", buffer);
if ((my_strcmp(buffer, "ko", '\0')) == 0)
return(1);
   check(stru, stock);
return(0);
}
}
 

int graph(int fd)
{
int	i;
t_bmp	pic;

i = 0;
printf("OK\n");
dprintf(fd, "GRAPHIC\n");
pic.x = 0;
pic.y = 0;
  pic.inf.us = NULL;
if(receive(&pic, fd) == 1)
return(1);
  init_sdl(&pic);
  SDL_BlitSurface(pic.imageDeFond, NULL, pic.ecran, &pic.positionFond);
pic.ecran = SDL_SetVideoMode(2000, 2000, 32, SDL_HWSURFACE);
  init_gemme(&pic);
  SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
 splitRect(980, 980, pic.ecran, 10, 10);
  SDL_Flip(pic.ecran); 
  SDL_FreeSurface(pic.trantor); 
 SDL_Flip(pic.ecran);
  while(42)    {
SDL_FillRect(pic.ecran, NULL, SDL_MapRGB(pic.ecran->format, 0, 0, 0));
splitRect(980, 980, pic.ecran, 10, 10);
receive(&pic, fd);
//printf("%d %d\n", pic.x, pic.y);     
 show_char(pic.x, pic.y, &pic);
     show_rss(pic.x,pic.y, &pic);
      SDL_Flip(pic.ecran);
    }
  //lpause(); /* On libère la surface */
  SDL_Quit();
  return EXIT_SUCCESS;
}
