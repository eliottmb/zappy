#include "moniteur.h"

void    show_char(int  x, int y, t_bmp *pic)
{
t_list  cpy;
cpy = pic->inf.us;
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

void    show_rss(int  x, int y, t_bmp *pic)
{
  int     i;
  int     a;
  int     n;

  i = x;
  a = y;
  n = 0;
  while(i < 10 + x && i < 30)
    {
      while(a < 10 + y && a < 30)
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

void	event(t_bmp *stru)
{
SDL_Event event;

SDL_PollEvent(&event);
if(event.key.keysym.sym == SDLK_UP && stru->y > 0)
stru->y--;
if(event.key.keysym.sym == SDLK_DOWN && stru->y < stru->inf.Y - 10)
stru->y++;
if(event.key.keysym.sym == SDLK_RIGHT && stru->x < stru->inf.X - 10)
stru->x++;
if(event.key.keysym.sym == SDLK_LEFT && stru->x > 0)
stru->x--;
}
