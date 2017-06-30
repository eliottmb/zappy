#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SDL/SDL.h>
#include "../../../include/client/moniteur.h"



void	init_case(t_bmp	*struc, char **buffer)
{
struc->inf.X = atoi(buffer[1]);
struc->inf.Y = atoi(buffer[2]);
printf("%d %d\n", struc->inf.X, struc->inf.Y);
}


void    init_map(t_bmp *struc, char **buffer)
{
int	x;
int	y;
int	i;
//int	rss[7];

i = 0;
x = my_getnbr(buffer[1]);
y = my_getnbr(buffer[2]);
while(i != 7)
{
struc->maprss[x][y].rss[i] = my_getnbr(buffer[i + 3]);
i++;
}
}

void	add_rss_to_player(t_bmp *struc, char **buffer)
{
t_list	cpy;

cpy = struc->inf.us;

while(cpy)
{
if(cpy->number == atoi(buffer[1]))
{
cpy->x = atoi(buffer[2]);
cpy->y = atoi(buffer[3]);
cpy->rss[0] = atoi(buffer[4]);
cpy->rss[1] = atoi(buffer[5]);
cpy->rss[2] = atoi(buffer[6]);
cpy->rss[3] = atoi(buffer[7]);
cpy->rss[4] = atoi(buffer[8]);
cpy->rss[5] = atoi(buffer[9]);
cpy->rss[6] = atoi(buffer[10]);

}
cpy = cpy->next;
}

}

void    add_pos(t_bmp *struc, char **buffer)
{
t_list  cpy;

cpy = struc->inf.us;

while(cpy)
{
if(cpy->number == atoi(buffer[1]))
{
cpy->x = atoi(buffer[2]);
cpy->y = atoi(buffer[3]);
}
cpy = cpy->next;
}
}

void    add_player(t_bmp *struc, char **buffer)
{
if(struc->inf.us == NULL)
struc->inf.us = create_node(my_getnbr(buffer[2]), my_getnbr(buffer[3]), my_getnbr(buffer[1]), buffer[4]);
else
list_add_elem_at_back(&struc->inf.us, buffer);
}
