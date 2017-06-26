/*
** my_strtowordtab.c for Project-Master in /home/albatard/rendu/SystemeUnix/Reseaux/PSU_2016_myirc
** 
** Made by Albatard
** Login   <nicolas.albanel@epitech.eu>
** 
** Started on  Tue May 30 16:59:11 2017 Albatard
** Last update Wed May 31 17:52:52 2017 Albatard
*/

#include <stdlib.h>
#include <unistd.h>

int     my_strword(char *str, char sep)
{
  int   count;
  int   word;
  int   indic;

  count = 0;
  word = 0;
  indic = 1;
  while (str[count] != '\0')
    {
      if (str[count] != sep)
	{
	  if (indic)
	    ++word;
	  count++;
	  indic = 0;
	}
      else
	{
	  count++;
	  indic = 1;
	}
    }
  return (word);
}

int     my_count(char *str, int strcount, char sep)
{
  int   count;

  count = 0;
  while (str[strcount] != '\0')
    {
      if (str[strcount] == sep)
	return (count);
      else
	{
	  count++;
	  strcount++;
	}
      if (str[strcount] == '\0')
	return (count);
    }
}

char    **my_strtowordtab2(char *str, char **temp, char sep)
{
  int   count;
  int   wordcount;
  int   arraycount;
  int   strcount;

  strcount = 0;
  arraycount = 0;
  wordcount = 0;
  while (wordcount != my_strword(str, sep))
    {
      count = 0;
      arraycount = my_count(str, strcount, sep);
      if ((temp[wordcount] = malloc(sizeof(char) * arraycount + 1)) == NULL)
	return (NULL);
      while (count < arraycount)
	temp[wordcount][count++] = str[strcount++];
      temp[wordcount][count] = '\0';
      wordcount++;
      strcount++;
    }
  temp[wordcount] = '\0';
  return (temp);
}

char    **my_strtowordtab(char *str, char sep)
{
  char  **temp;
  int	count;

  count = 0;
  if (str == NULL)
    return (NULL);
  else
    {
      count = my_strword(str, sep);
      if ((temp = malloc(sizeof(char*) * (my_strword(str, sep) + 1))) == NULL)
	return (NULL);
      temp = my_strtowordtab2(str, temp, sep);
      return (temp);
    }
}
