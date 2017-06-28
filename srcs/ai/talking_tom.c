/*
** talking_tom.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/ai
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 20:03:49 2017 eliott m-barali
** Last update Wed Jun 28 15:42:02 2017 eliott m-barali
*/

void		got_thy_que(t_ai *ai)
{
  dprintf(ai->fd, "%s #\n", ai->team);
}

int		got_broadcast(t_ai *ai, char *str)
{
  if (strcpy(get_nth_word(str, 1), ai->team) != 0)
    return (-1);
  if (strcpy(get_nth_word(str, 2), "#") != 0)
    receive_got
  else if (strcpy(get_nth_word(str, 2), "") != 0)

}


int		receive_got_thy(t_ai *ai)
{
    ai->got_thy = 1;
}
