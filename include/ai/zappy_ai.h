/*
** zappy_ai.h for  in /home/romain.huet/rendu/Backup_Zappy
** 
** Made by Romain HUET
** Login   <romain.huet@epitech.net>
** 
** Started on  Mon Jun 19 11:58:40 2017 Romain HUET
** Last update Sat Jul  1 19:36:31 2017 Albatard
*/

#ifndef AI_H
# define AI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
** STRUCT
*/

typedef struct	s_ai
{
  int		fd;
  int		*i;	// inventaire
  int		num_player;
  char		*team;
  int		lvl;
  int		f;
  int		view[16][7];
  bool		incantating;
  bool		broadcasting;
  bool		got_thy;
}		t_ai;

/*
** // Fonctions //
*/

/* 
** HELP_AI.C
*/

void		help_client();

/*
** TALK.C
*/

void		ask_ress(t_ai *ai, int *ress);
void		ask_more_players(t_ai *ai, int *players);
void		my_ress(t_ai *ai, int *ress);
void		send_sharp(t_ai *ai);
int		got_broadcast(t_ai *ai, char *str);

/*
** RECEIVE.C
*/

int		receive_sharp(t_ai *ai);
int		receive_ask_ress(char *str, t_ai *ai);
int		receive_ask_player(char *str, t_ai *ai);
int		receive_my_ress(char *str, t_ai *ai);

/*
** USAGE.C
*/

void		show_ress(int *t);
void		show_struct(t_ai *ai);
int		*my_add_tab(int *to_ret, int *t1, int *t2);
int		*my_dif_tab(int *to_ret, int *t1, int *t2);
//int		*add_player(int *player, int num);

/*
** INIT.C
*/

int		*init_tab();
int		*init_player_tab();
int		init_ai(t_ai *ai, char *t);
void		free_ai(t_ai *ai);

/*
** TOOL.C
*/

char			*cut_word(char *str, int n);
int	*sort_int_tab(char *str);
#endif /* !AI_H */
