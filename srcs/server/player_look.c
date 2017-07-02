/*
** player_look.c for zappy in /home/mederic.unissart/rendu/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 21 19:20:35 2017 Médéric Unissart
** Last update Sun Jul  2 16:25:44 2017 Médéric Unissart
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
  int		o;
  char		*res[7];

  res[0] = "food";
  res[1] = "linemate";
  res[2] = "deraumere";
  res[3] = "sibur";
  res[4] = "mendiane";
  res[5] = "phiras";
  res[6] = "thystame";
  i = 0;
  while (i++ < map[pos[1]][pos[0]].nb_players)
    *ilook += *ilook == 1 ? sprintf(&look[*ilook], "player"):
      sprintf(&look[*ilook], " player");
  i = 0;
  while (i != 7)
    {
      o = 0;
      while (o++ < map[pos[1]][pos[0]].res[i])
	*ilook += *ilook == 1 ?
	  sprintf(&look[*ilook], "%s", res[i]) :
	  sprintf(&look[*ilook], " %s", res[i]);
      ++i;
    }
}

static void	fill_look_buffer(t_player *player,
				 t_tile **map,
				 int tiles,
				 t_server *server)
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
  player->look = strdup(look);
  init_msg_timer(server, player, 3, -1);
}

void		player_look(void *player, void *server, int undefined)
{
  int		tiles;
  int		i;
  t_server	*serv;
  t_player	*p;

  serv = (t_server *)server;
  p = (t_player *)player;
  tiles = 0;
  i = 0;
  undefined = undefined;
  while (i <= p->lvl)
    tiles += i++ * 2 + 1;
  fill_look_buffer(p, serv->map, tiles, server);
}
