/*
** player_look.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 19:20:35 2017 Médéric Unissart
** Last update Mon Jun 26 18:08:22 2017 Romain HUET
*/

#include "zappy_server.h"

static void	fill_xytables(int *xytable)
{
  int		i;
  int		o;
  int		y;
  int		lvl;

  lvl = 0;
  o = 0;
  while (lvl != 8)
    {
      i = 0;
      y = -lvl;
      while (i < lvl * 2 + 1)
	{
	  xytable[o + 64] = -lvl;
	  xytable[o++] = y++;
	  ++i;
	}
      ++lvl;
    }
}

static void	find_tiles_pos(t_player *player,
			       int *pos,
			       int tile,
			       t_tile **map)
{
  int		temp;
  int		x;
  int		y;
  int		xytable[128];

  fill_xytables(xytable);
  x = xytable[tile];
  y = xytable[tile + 64];
  if (player->o == SOUTH)
    {
      x *= -1;
      y *= -1;
    }
  else if (player->o == EAST)
    y *= -1;
  if (player->o == WEST || player->o == EAST)
    {
      temp = x;
      x = y;
      y = temp;
    }
  pos[0] = player->x + x < 0 ? player->x + x + map[0][0].x_max : player->x + x;
  pos[1] = player->y + y < 0 ? player->y + y - map[0][0].y_max : player->y + y;
  pos[0] = pos[0] > map[0][0].x_max ? pos[0] - map[0][0].x_max : pos[0];
  pos[1] = pos[1] > map[0][0].y_max ? pos[1] - map[0][0].y_max : pos[1];
}

static void	look_a_tile(char *look, t_tile **map, int *pos, int *ilook)
{
  int		i;
  char		*res[7] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"};

  if (map[pos[1]][pos[0]].nb_players > 0)
    *ilook += sprintf(&look[*ilook], " player %d",
		      map[pos[1]][pos[0]].nb_players);
  i = 0;
  while (i != 7)
    {
      if (map[pos[1]][pos[0]].res[i] > 0)
	(*ilook == 1) ?
	  (*ilook += sprintf
	   (&look[*ilook], "%s %d", res[i], map[pos[1]][pos[0]].res[i])):
	  (*ilook += sprintf
	   (&look[*ilook], " %s %d", res[i], map[pos[1]][pos[0]].res[i]));
      ++i;
    }
}

static void	fill_look_buffer(t_player *player, t_tile **map, int tiles)
{
  char		look[tiles * 81 + 2];
  int		pos[2];
  int		ilook;
  int		find_tile;

  ilook = 0;
  find_tile = 0;
  look[ilook++] = '[';
  while (find_tile < tiles)
    {
      find_tiles_pos(player, pos, find_tile, map);
      look_a_tile(look, map, pos, &ilook);
      (find_tile + 1 < tiles) ? (look[ilook++] = ',') : (0);
      ++find_tile;
    }
  look[ilook++] = ']';
  look[ilook++] = '\n';
  look[ilook++] = '\0';
  printf("%s", look);
}

bool		player_look(t_player *player, t_tile **map)
{
  int		tiles;
  int		i;

  tiles = 0;
  i = 0;
  while (i <= player->lvl)
    tiles += i++ * 2 + 1;
  fill_look_buffer(player, map, tiles);
  return (true);
}
