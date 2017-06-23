/*
** player_look.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 19:20:35 2017 Médéric Unissart
** Last update Fri Jun 23 18:31:43 2017 Médéric Unissart
*/

#include "player.h"

int	xtable[64] = {
  0,
  -1,
  0,
  1,
  -2,
  -1,
  0,
  1,
  2,
  -3,
  -2,
  -1,
  0,
  1,
  2,
  3,
  -4,
  -3,
  -2,
  -1,
  0,
  1,
  2,
  3,
  4,
  -5,
  -4,
  -3,
  -2,
  -1,
  0,
  1,
  2,
  3,
  4,
  5,
  -6,
  -5,
  -4,
  -3,
  -2,
  -1,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  -7,
  -6,
  -5,
  -4,
  -3,
  -2,
  -1,
  0,
  1,
  2,
  3,
  4,
  5,
  6,
  7
};

int	ytable[64] = {
  0,
  -1,
  -1,
  -1,
  -2,
  -2,
  -2,
  -2,
  -2,
  -3,
  -3,
  -3,
  -3,
  -3,
  -3,
  -3,
  -4,
  -4,
  -4,
  -4,
  -4,
  -4,
  -4,
  -4,
  -4,
  -5,
  -5,
  -5,
  -5,
  -5,
  -5,
  -5,
  -5,
  -5,
  -5,
  -5,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -6,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7,
  -7
};

static void	find_tiles_pos(t_player *player, int *pos, int tile)
{
  int		temp;
  int		x;
  int		y;

  x = xtable[tile];
  y = ytable[tile];
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
  pos[0] = player->x;
  pos[1] = player->y;
  printf("x:%d y:%d o:%d\n", x, y, player->o);
}

static void	look_a_tile(char *look, t_map **map, int *pos, int *ilook)
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

static void	fill_look_buffer(t_player *player, t_map **map, int tiles)
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
      find_tiles_pos(player, pos, find_tile);
      look_a_tile(look, map, pos, &ilook);
      (find_tile + 1 < tiles) ? (look[ilook++] = ',') : (0);
      ++find_tile;
    }
  look[ilook++] = ']';
  look[ilook] = '\n';
  printf("%s", look);
}

bool		player_look(t_player *player, t_map **map)
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

int main()
{
  t_player	*player;
  t_map		**map;

  player = init_player("rouge", 8, 8);
  map = init_map(10, 10, 12);
  player_look(player, map);

  int i = 0;
  while (i != 10)
    free(map[i++]);
  free(map);
  free(player);
}
