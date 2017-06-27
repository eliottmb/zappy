#include <stdlib.h>
#include "moniteur.h"
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>

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
pic->gemme[0] = SDL_LoadBMP("pomme.bmp");
pic->gemme[1] = SDL_LoadBMP("gemme-jaune.bmp");
pic->gemme[2] = SDL_LoadBMP("gemme-violet.bmp");
pic->gemme[3] = SDL_LoadBMP("gemme-rouge.bmp");
pic->gemme[4] = SDL_LoadBMP("gemme-blanc.bmp");
pic->gemme[5] = SDL_LoadBMP("gemme-verte.bmp");
pic->gemme[6] = SDL_LoadBMP("gemme-bleu.bmp");
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
pic->positionFond.x = 0;
pic->positionFond.y = 0;
SDL_Init(SDL_INIT_VIDEO);
 pic->ecran = SDL_SetVideoMode(2000, 2000, 32, SDL_HWSURFACE);
pic->imageDeFond = SDL_LoadBMP("grass.bmp");
pic->toad = SDL_LoadBMP("toad.bmp");
SDL_SetColorKey(pic->toad, SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad->format, 0, 0, 0));
pic->trantor = SDL_LoadBMP("canvas.bmp");
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

  i = x;
  a = y;
  while(pic->inf.us)
    {
      //if (pic->inf.us->x > x - 1 && pic->inf.us->x < x + 10)
      printf("ok\n");
      pic->postoad.x = 197 + (pic->inf.us->x - 1) * 98 + 150;
      pic->postoad.y = 30 + pic->inf.us->y * 98 + 33;

      pic->inf.us = pic->inf.us->next;
      SDL_BlitSurface(pic->toad, NULL, pic->ecran, &pic->postoad);
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
  if(my_strcmp(buffer[0], "msz", '\0') == 0)
    init_case(pic, buffer);
  if(my_strcmp(buffer[0], "bct", '\0') == 0)
    init_map(pic, buffer);
  if(my_strcmp(buffer[0], "ppo", '\0') == 0)
    {
      add_pos(pic, buffer);
      //printf("CCCC : %d\n", pic->inf.us->x);
    }
}

void    receive(t_bmp *stru, int     fd)
{
  char    buffer[32];
  int     len;
  char	**stock;
  int i;
  int nb;

  i = 0;

  nb = 0;
  while(nb != 32)
    {
      buffer[nb] = '\0';
      nb++;

    }
  printf("KKKK\n");
  if ((len = read(fd, buffer, 32)) > 0)
    {
      buffer[len - 1] = '\0';
      stock = my_strtowordtab(buffer, ' ');
      printf("BUFFER :%s\n", buffer);
      check(stru, stock);
    }
  i++;



} 

int main(int argc, char *argv[])
{
  t_bmp	pic;

  pic.inf.us = NULL;
  receive(&pic, 0);
  init_sdl(&pic);
  SDL_BlitSurface(pic.imageDeFond, NULL, pic.ecran, &pic.positionFond);
  pic.ecran = SDL_SetVideoMode(2000, 2000, 32, SDL_HWSURFACE);

  init_gemme(&pic);

  show_char(0,0, &pic);
  show_rss(0,0, &pic);
  SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
  splitRect(980, 980, pic.ecran, 10, 10);
  SDL_Flip(pic.ecran); 
  SDL_FreeSurface(pic.trantor);
  SDL_Flip(pic.ecran);

  while(42)
    {
      receive(&pic, 0);
      show_char(0,0, &pic);
      show_rss(0,0, &pic);
      SDL_Flip(pic.ecran);
    }

  lpause(); /* On libère la surface */
  SDL_Quit();
  return EXIT_SUCCESS;
}
