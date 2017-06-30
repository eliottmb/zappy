/*
** sighandling.c for zappy in /home/mederic.unissart/rendu/zappy/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 28 17:10:24 2017 Médéric Unissart
** Last update Fri Jun 30 16:56:43 2017 Médéric Unissart
*/

#include "zappy_server.h"

void		sigusr_handling(int signum, siginfo_t *info, void *context)
{
  t_serv_msg	*serv_msg;

  if (signum != SIGUSR1)
    return ;
  context = context;
  serv_msg = info->si_value.sival_ptr;
  dprintf(serv_msg->player_fd, "%s\n", serv_msg->msg);
  free(serv_msg);
}

bool			init_sigact()
{
  struct sigaction	act;

  act.sa_sigaction = &sigusr_handling;
  act.sa_flags = SA_SIGINFO;
  if (sigaction(SIGUSR1, &act, NULL) == -1)
    return (false);
  return (true);
}

bool			msg_timer(int player_fd,
				  int frequence,
				  int cmd_cycle,
				  char *msg)
{
  timer_t		timerid;
  struct sigevent	sevp;
  struct itimerspec	its;
  t_serv_msg		*serv_msg;

  if (!(serv_msg = malloc(sizeof(*serv_msg))))
    return (false);
  serv_msg->msg = msg;
  serv_msg->player_fd = player_fd;
  sevp.sigev_notify = SIGEV_SIGNAL;
  sevp.sigev_signo = SIGUSR1;
  sevp.sigev_value.sival_ptr = serv_msg;
  if (timer_create(CLOCK_REALTIME, &sevp, &timerid) == -1)
    return (false);
  its.it_value.tv_sec = cmd_cycle / frequence;
  its.it_value.tv_nsec =
    (long)((float)1000000000*(cmd_cycle%frequence)/frequence);
  its.it_interval.tv_sec = 0;
  its.it_interval.tv_nsec = 0;
  if (timer_settime(timerid, 0, &its, NULL) == -1)
    return (false);
  return (true);
}
