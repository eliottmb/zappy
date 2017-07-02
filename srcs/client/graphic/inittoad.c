#include "moniteur.h"

void	init_toad(t_bmp *pic)
{
pic->toad[0] = SDL_LoadBMP("srcs/client/graphic/imgs/toad.bmp");
SDL_SetColorKey(pic->toad[0], SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad[0]->format, 0, 0, 0));
pic->toad[1] = SDL_LoadBMP("srcs/client/graphic/imgs/1toad.bmp");
SDL_SetColorKey(pic->toad[1], SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad[1]->format, 0, 0, 0));
pic->toad[2] = SDL_LoadBMP("srcs/client/graphic/imgs/2toad.bmp");
SDL_SetColorKey(pic->toad[2], SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad[2]->format, 0, 0, 0));
pic->toad[3] = SDL_LoadBMP("srcs/client/graphic/imgs/3toad.bmp");
SDL_SetColorKey(pic->toad[3], SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad[3]->format, 0, 0, 0));
pic->toad[4] = SDL_LoadBMP("srcs/client/graphic/imgs/4toad.bmp");
SDL_SetColorKey(pic->toad[4], SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad[4]->format, 0, 0, 0));
pic->toad[5] = SDL_LoadBMP("srcs/client/graphic/imgs/5toad.bmp");
SDL_SetColorKey(pic->toad[5], SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad[5]->format, 0, 0, 0));
pic->toad[6] = SDL_LoadBMP("srcs/client/graphic/imgs/6toad.bmp");
SDL_SetColorKey(pic->toad[6], SDL_SRCCOLORKEY, SDL_MapRGB(pic->toad[6]->format, 0, 0, 0));
}