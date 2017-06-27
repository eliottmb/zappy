#include <stdlib.h>
#include "moniteur.h"
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>

void	init_case(t_bmp	*struc, char **buffer)
{
struc->inf.X = my_getnbr(buffer[1]);
struc->inf.Y = my_getnbr(buffer[2]);
}


void    init_map(t_bmp *struc, char **buffer)
{
int	x;
int	y;
int	i;
int	rss[7];

i = 0;
x = my_getnbr(buffer[1]);
y = my_getnbr(buffer[2]);
while(i != 7)
{
struc->maprss[x][y].rss[i] = my_getnbr(buffer[i + 3]);
i++;
}
}

void    add_pos(t_bmp *struc, char **buffer)
{
if(struc->inf.us == NULL)
struc->inf.us = create_node(my_getnbr(buffer[2]), my_getnbr(buffer[3]), my_getnbr(buffer[1]));
else
list_add_elem_at_back(&struc->inf.us, my_getnbr(buffer[2]), my_getnbr(buffer[3]), my_getnbr(buffer[1]));
}

void    add_player(t_bmp *struc, char **buffer)
{
if(struc->inf.us == NULL)
struc->inf.us = create_node(my_getnbr(buffer[2]), my_getnbr(buffer[3]), my_getnbr(buffer[1]));
else
list_add_elem_at_back(&struc->inf.us, my_getnbr(buffer[2]), my_getnbr(buffer[3]), my_getnbr(buffer[1]));
}