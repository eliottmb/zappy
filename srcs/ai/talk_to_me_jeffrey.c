/*
** talk_to_me_jeffrey.c for  in /home/m-bara_e/rendu/PSU_2016_zappy/srcs/server
** 
** Made by eliott m-barali
** Login   <m-bara_e@epitech.net>
** 
** Started on  Tue Jun 27 19:29:01 2017 eliott m-barali
** Last update Wed Jun 28 02:50:26 2017 eliott m-barali
*/

void		ask_lvl(t_ai *ai)
{
  dprintf(ai->fd, "%s ?\n", ai->team);
}

void		ask_ress(t_ai *ai, int *ress)
{
  dprintf(ai->fd, "%s ! %d %d %d %d %d %d %d\n", ai->team, ress[0], ress[1], ress[2], ress[3], ress[4], ress[5], ress[6]);
}

void		ask_more_players(t_ai *ai, int i)
{
  dprintf(ai->fd, "%s - %d\n", ai->team, i);
}


void		answer_lvl(t_ai *ai)
{
  dprintf(ai->fd, "%s _ %d\n", ai->team, ai->lvl);
}

void		o_m_w(t_ai *ai)
{
    dprintf(ai->fd, "%s * %d %d %d %d %d %d %d\n", ai->team, ress[0], ress[1], ress[2], ress[3], ress[4], ress[5], ress[6]);
}