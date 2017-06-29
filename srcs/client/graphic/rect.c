#include "../../../include/client/moniteur.h"
void drawEmptyRect2(SDL_Surface * surf,int posX, int posY, int width, int length)
{
SDL_Rect ligneHaut;
SDL_Rect ligneDroite;
SDL_Rect ligneGauche;
SDL_Rect ligneBas;

ligneHaut.x = posX-1;
ligneHaut.y = posY-1;
ligneHaut.w = length;
ligneHaut.h = 1; 
SDL_FillRect(surf, &ligneHaut, SDL_MapRGB(surf->format, 0, 0, 0));
ligneDroite.x = posX+length-1;
ligneDroite.y = posY-1;
ligneDroite.w = 1;
ligneDroite.h = width;
SDL_FillRect(surf, &ligneDroite, SDL_MapRGB(surf->format, 0, 0, 0));
ligneGauche.x = posX-1;
ligneGauche.y = posY-1;
ligneGauche.w = 1;
ligneGauche.h = width;
SDL_FillRect(surf, &ligneGauche, SDL_MapRGB(surf->format, 0, 0, 0));
ligneBas.x = posX-1;
ligneBas.y = posY+width-1;
ligneBas.w = length;
ligneBas.h = 1;
 SDL_FillRect(surf, &ligneBas, SDL_MapRGB(surf->format, 0, 0, 0));
}

void     fullRect(int a, int i, SDL_Surface *ecran, int tx, int ty)
{
float   x;
float   y;
float   n;
int     e;

e = 0;
n = 0;
x = a / tx;
y = i / ty;
        while(e != 980)
{               
drawEmptyRect2(ecran, 197, 30 + e, 1, i);
n = n + y;
e++;
}
n = 0;
e = 0;
     while(e != 980)
{               
drawEmptyRect2(ecran, 197 + e, 30, i, 1);
n = n + x;
e++;
}
}