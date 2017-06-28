/*
** list.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_myirc
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Wed May 31 16:34:23 2017 Albatard
** Last update Wed Jun 28 16:04:45 2017 Romain HUET
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../../include/client/moniteur.h"

t_user		*create_node(int x, int y, int number)
{
  t_user	*user = malloc(sizeof(t_user));
  
user->x = x;
user->y = y;
user->number = number;
  user->name = NULL;  
  user->next = NULL;
  return (user);
}

int		list_add_elem_at_back(t_list *front_ptr, int x, int y, int number)
{
  t_user	*new_user;
  t_list	list;

  new_user = create_node(x, y, number);
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
    return list_del_elem_at_front(front_ptr);
  cpy = previous->next;
  while (cpy)
    {
      if (cpy->number == fd)
	{
	  if (cpy->next != NULL)
	    {
	      previous->next = cpy->next;
	      free(cpy);
	      return (0);
	    }
	  else
	    {
	      free(cpy);
	      return (0);
	    }
	}
      previous = cpy;
      cpy = cpy->next;
    }
  return (-1);
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

int	list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  t_list	previous;
  t_list	list;

  if (position == 0)
    {
      printf("front\n");
      return list_del_elem_at_front(front_ptr);
    }
  previous = *front_ptr;
  list = previous->next;
  if (!*front_ptr)
    return (1);
  while (--position)
    {
      if (!list)
	return (1);
      previous = list;
      list = list->next;
    }
  if (list)
    previous->next = list->next;
  free(list);
  return (0);
}

int	list_del_elem_at_back(t_list *front_ptr)
{
  t_list	list;
  t_list	previous;

  list = *front_ptr;
  previous = NULL;
  if (!list)
    return(1);
  while (list->next)
    {
      previous = list;
      list = list->next;
    }
  if (previous)
    previous->next = NULL;
  else
    *front_ptr = NULL;
  free(list);
  return (0);
}

int		list_is_empty(t_user *list)
{
  if (list)
    return (1);
  else
    return (0);

}

unsigned int	list_get_size(t_user *list)
{
  unsigned int	size = 0;
  
  while (list)
    {
      size++;
      list = list->next;
    }
  return (size);
}

int		list_get_elem_at_position(t_user *list, unsigned int position)
{
  if (!list)
    return (0);
  while (position--)
    {
      list = list->next;
      if (!list)
	return (0);
    }
  return (list->fd);
}

t_user		*list_get_first_node_with_value(t_user *list, char *name)
{
  while (list)
    {
      if (list->name == name)
	return (list);
      list = list->next;
    }
  return (NULL);
}
