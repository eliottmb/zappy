#ifndef MONITEUR_H
# define MONITEUR_H
#include <SDL/SDL.h>


typedef struct  s_maprss
{
int		rss[7];
int		X;
int		Y;
}		t_maprss;

typedef struct  s_user
{
int		x;
int		y;
int		number;
int		level;
int		fd;
char		*name;
int		rss[7];
struct s_user	*next;
}		t_user;

typedef t_user  *t_list;

typedef struct  s_info
{
int		X;
int		Y;
t_list		us;

}		t_info;

typedef struct  s_bmp
{
SDL_Surface	*ecran;
SDL_Surface	*trantor;
SDL_Surface	*toad;
SDL_Surface	*imageDeFond;
SDL_Surface	*gemme[7];
SDL_Rect	postoad;
SDL_Rect	positionFond;
SDL_Rect	postrantor;
SDL_Rect	posgemme;
SDL_Rect	gemmeR[7];
int		x;
int		y;
t_maprss        maprss[30][30];
t_info		inf;
}		t_bmp;

typedef struct  s_func
{
  char          *name;
  void          (*ptrfunc)(t_bmp *, char **buffer);
}               t_func;

char		**my_strtowordtab(char *, char);
void		init_case(t_bmp *, char **buffer);
int		my_strcmp(char *, char *, char);
int		my_getnbr(char *);
void		init_map(t_bmp *struc, char **buffer);
int		list_del_elem_at_front(t_list *front_ptr);
//void    show_char(int  x, int y, t_bmp *pic);
int		graph(int);
t_user          *create_node(int x, int y, int number, char *team);
int		list_add_elem_at_back(t_list *front_ptr, char**);
void		add_pos(t_bmp *, char **buffer);
void	        add_player(t_bmp *, char **buffer);
int		list_del_elem(t_list*, int);
void    add_rss_to_player(t_bmp *struc, char **buffer);
void drawEmptyRect2(SDL_Surface * surf,int posX, int posY, int width, int length);
void     fullRect(int a, int i, SDL_Surface *ecran, int tx, int ty);
#endif
