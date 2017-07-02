/*
** client_graph.c for y in /home/goepfe_a/graphic
** 
** Made by alexandre goepfert
** Login   <goepfe_a@epitech.net>
** 
** Started on  Sun Jul  2 18:59:37 2017 alexandre goepfert
** Last update Sun Jul  2 19:00:52 2017 alexandre goepfert
*/

#include <stdlib.h>
#include "moniteur.h"
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>

t_func  g_cmd[5] =
{
  {"msz", &init_case},
  {"bct", &init_map},
  {"pnw", &add_player},
  {"ppo", &add_pos},
  {"pin", &add_rss_to_player},
};

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

void	check(t_bmp   *pic, char **buffer)
{
  int	i;

  i = 0;
  while(i != 5)
    { 
      if (my_strcmp(buffer[0], g_cmd[i].name, '\0') == 0)
	g_cmd[i].ptrfunc(pic, buffer);
      i++;
    }
  if(my_strcmp(buffer[0], "pdi", '\0') == 0)
    list_del_elem(&pic->inf.us, atoi(buffer[1]));
}

int graph(int fd)
{
  t_bmp	pic;
  
  dprintf(fd, "GRAPHIC\n");
  pic.inf.us = NULL;
  srand(time(NULL));
  if(receive(&pic, fd) == 1)
    return(1);
  init_sdl(&pic);
  init_music(&pic); 
  while(42)
    {
      SDL_FillRect(pic.ecran, NULL, SDL_MapRGB(pic.ecran->format, 240, 166, 166));
      fullRect(980, 980, pic.ecran, 10, 10);
      splitRect(980, 980, pic.ecran, 10, 10);
      if(receive(&pic, fd) == 1)
	{
	  SDL_Quit();
	  return(1);
	}
      show_char(pic.x, pic.y, &pic);
      show_rss(pic.x,pic.y, &pic);
//      displayxy(&pic);
      SDL_Flip(pic.ecran);
    }
  SDL_Quit();
  return EXIT_SUCCESS;
}
