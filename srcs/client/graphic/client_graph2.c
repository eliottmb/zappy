#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../../../include/client/moniteur.h"


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

void    add_rss(int     rss[7], int x, int y, t_bmp *pic)
{
int     i;

i = 0;
while (i != 7)
{
pic->maprss[x][y].rss[i] = rss[i];
i++;
}
}

void    display_rss(int  x, int y, int n, t_bmp *pic)
{
if (n == 0 || n == 1 || n == 2)
{
pic->gemmeR[n].x = 197 + x * 98 + 33 * n;
pic->gemmeR[n].y = 30 + y * 98;

}

if (n == 3 || n == 4)
{
pic->gemmeR[n].x = 197 + x * 98 + 33 * (n - 3);
pic->gemmeR[n].y = 30 + y * 98 + 33;

}

if(n == 5 || n == 6)
{
pic->gemmeR[n].x = 197 + x * 98 + 33 * (n - 5);
pic->gemmeR[n].y = 30 + y * 98 + 66;
}
}