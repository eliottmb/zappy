/*
** list.c for y in /home/goepfe_a/graphic
** 
** Made by alexandre goepfert
** Login   <goepfe_a@epitech.net>
** 
** Started on  Sun Jul  2 19:05:58 2017 alexandre goepfert
** Last update Sun Jul  2 19:10:03 2017 alexandre goepfert
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../../include/client/moniteur.h"

t_user		*create_node(int x, int y, int number, char *team)
{
  t_user	*user = malloc(sizeof(t_user));
  
  user->x = x;
  user->y = y;
  user->number = number;
  user->rss[0] = 0;
  user->rss[1] = 0;
  user->rss[2] = 0;
  user->rss[3] = 0;
  user->rss[4] = 0;
  user->rss[5] = 0;
  user->rss[6] = 0;
  user->name = strdup(team);
  user->name = NULL;  
  user->next = NULL;
  user->num = rand() % 7;
  return (user);
}

int		list_add_elem_at_back(t_list *front_ptr, char **buffer)
{
  t_user	*new_user;
  t_list	list;
  
  new_user = create_node(atoi(buffer[2]), atoi(buffer[3]), atoi(buffer[1]), buffer[4]);
  list = *front_ptr;
  if (!new_user)
    return (1);
  if (!list)
    *front_ptr = new_user;
  else
    {
      list = *front_ptr;
      while (list->next)
	list = list->next;
      list->next = new_user;
    }
  return (0);
}

int		list_del_elem(t_list *front_ptr, int fd)
{
  t_list	cpy;
  t_list	previous;
  
  previous = *front_ptr;
  if (previous->number == fd)
	return(list_del_elem_at_front(front_ptr));
  cpy = previous->next;
  while (cpy)
    {
      if (cpy->number == fd)
	{
	  free(cpy->name);
	  if (cpy->next != NULL)
	    {
	      previous->next = cpy->next;
	      free(cpy->name);	  
cpy->x = 40;
cpy->y = 40;	     
 return(0);
	    }
	  else
	    {
	 //     free(cpy);
	      return(0);	    
	    }
	}
      previous = cpy;
      cpy = cpy->next;
    }
return(-1);
}

int          list_del_elem_at_front(t_list *front_ptr)
{
  t_list        list = *front_ptr;

  if (!list)
    return (-1);
  *front_ptr = list->next;
  free(list);
  return (0);
}
