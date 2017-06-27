/*
** com.h for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Fri Jun 23 15:42:17 2017 eliott m-barali
** Last update Tue Jun 27 20:15:06 2017 Romain HUET
*/

#ifndef __COM_H__
# define __COM_H__

/*
** MAP_INFO.C
*/

int	map_size(int fd, void **map);
int	one_tile_content(int fd, void *tile);
int	many_tile_content(int fd, void **map);

/*
** PLAYER_INFO.C
*/

int	team_name(int fd, void *args);
int	new_player_connection(int fd, void *player);
int	player_position(int fd, void *player);
int	player_level(int fd, void *player);
int	player_build(int fd, void *player);

/*
** PLAYER_ACTION.C
*/

int	player_spawn_egg(int fd, void *player);
int	player_tragically_die(int fd, void *player);

/*
** SETTINGS.C
*/

int	server_time(int fd, void *args);
int	server_game_win(int fd, void *str);
int	server_message(int fd, void *str);
int	server_unknown_command(int fd, void *str);
int	server_bad_param(int fd, void *str);


#endif /* __COM_H__ */
