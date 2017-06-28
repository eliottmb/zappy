/*
** strcmp.c for y in /home/goepfe_a/2emeAnnée/Système_Unix_Reseaux
** 
** Made by alexandre goepfert
** Login   <goepfe_a@epitech.net>
** 
** Started on  Tue May 16 15:59:48 2017 alexandre goepfert
** Last update Tue May 16 16:04:12 2017 alexandre goepfert
*/

int     my_strcmp(char *str, char *word, char sep)
{
  int   a;

  a = 0;
  while(str[a] == word[a] && word[a] != '\0')
    a++;
  if (str[a] == sep && word[a] == '\0')
    return(0);
  else
    return(-1);
}
