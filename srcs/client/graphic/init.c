#include "moniteur.h"

void    init_case(t_bmp *struc, char **buffer)
{
struc->inf.X = atoi(buffer[1]);
struc->inf.Y = atoi(buffer[2]);
}


void    init_music(t_bmp *struc)
{
struc->x = 0;
struc->y = 0;
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
   {
      printf("%s", Mix_GetError());
   }

   Mix_Music *musique;
   musique = Mix_LoadMUS("srcs/client/graphic/imgs/zelda.mp3");
   Mix_PlayMusic(musique, -1);
}

void    init_maprss(t_bmp *pic)
{
int     i;
int     a;
int     n;

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

void    init_sdl(t_bmp *pic)
{
pic->x = 0;
pic->y = 0;
pic->inf.X = 0;
pic->inf.Y = 0;
pic->positionFond.x = 0;
pic->positionFond.y = 0;
SDL_Init(SDL_INIT_VIDEO);
 pic->ecran = SDL_SetVideoMode(2000, 2000, 32, SDL_HWSURFACE);
pic->imageDeFond = SDL_LoadBMP("srcs/client/graphic/imgs/grass.bmp");
init_toad(pic);
//pic->toad = SDL_LoadBMP("srcs/client/graphic/imgs/toad.bmp");
//SDL_SetColorKey(pic->toad, SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad->format, 0, 0, 0));

pic->trantor = SDL_LoadBMP("srcs/client/graphic/imgs/canvas.bmp");
pic->postrantor.x = 1640;
pic->postrantor.y = 0;
SDL_BlitSurface(pic->trantor, NULL, pic->ecran, &pic->postrantor);
SDL_BlitSurface(pic->imageDeFond, NULL, pic->ecran, &pic->positionFond);
pic->ecran = SDL_SetVideoMode(2000, 2000, 32, SDL_HWSURFACE);
  init_gemme(pic);
  SDL_WM_SetCaption("ZAPPY GAME", NULL);
 splitRect(980, 980, pic->ecran, 10, 10);
  SDL_Flip(pic->ecran); 
init_maprss(pic);
}

void    init_map(t_bmp *struc, char **buffer)
{
int     x;
int     y;
int     i;

i = 0;
x = my_getnbr(buffer[1]);
y = my_getnbr(buffer[2]);
while(i != 7)
{
struc->maprss[x][y].rss[i] = my_getnbr(buffer[i + 3]);
i++;
}
}