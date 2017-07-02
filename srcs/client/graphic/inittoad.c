/*
** inittoad.c for y in /home/goepfe_a/graphic
** 
** Made by alexandre goepfert
** Login   <goepfe_a@epitech.net>
** 
** Started on  Sun Jul  2 19:04:51 2017 alexandre goepfert
** Last update Sun Jul  2 19:05:24 2017 alexandre goepfert
*/

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

void	displayxy(t_bmp *pic)
{
  SDL_Surface	*texte;
  TTF_Font	*police;
  SDL_Rect	position;
  SDL_Color	couleur;

  police = TTF_OpenFont("angelina.ttf", 100);
  texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", couleur);
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(texte, NULL, pic->ecran, &position);
}