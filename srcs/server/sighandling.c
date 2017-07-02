/*
** sighandling.c for zappy in /home/mederic.unissart/rendu/zappy/PSU_2016_zappy
** 
** Made by Médéric Unissart
** Login   <mederic.unissart@epitech.net>
** 
** Started on  Wed Jun 28 17:10:24 2017 Médéric Unissart
** Last update Sun Jul  2 20:41:55 2017 Médéric Unissart
*/

#include "zappy_server.h"

void		sigusr_handling(int signum, siginfo_t *info, void *context)
{
  t_serv_msg	*msg;

  if (signum != SIGUSR1)
    return ;
  context = context;
  msg = info->si_value.sival_ptr;
  msg->go_to_cmd(msg->server, msg->player, msg->res);
  if (msg->res != -8)
    free(msg);
}

bool			init_sigact()
{
  struct sigaction	act;

  act.sa_sigaction = &sigusr_handling;
  act.sa_flags = SA_SIGINFO;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGUSR1);
  if (sigaction(SIGUSR1, &act, NULL) == -1)
    return (false);
  return (true);
}

bool			msg_timer(t_serv_msg *msg,
				  int frequence,
				  int cmd_cycle)
{
  timer_t		timerid;
  struct sigevent	sevp;
  struct itimerspec	its;

  sevp.sigev_notify = SIGEV_SIGNAL;
  sevp.sigev_signo = SIGUSR1;
  sevp.sigev_value.sival_ptr = msg;
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

bool			init_msg_timer(t_server *server,
				       t_player *player,
				       int cmd,
				       int res)
{
  t_serv_msg		*msg;
  void			(*go_to_cmd[10])(t_server *, t_player *, int);
  int			time;

  (cmd == 8) ? (time = C_TIM300) : (time = C_TIM7);
  (cmd == 5) ? (time = C_TIM42) : (time = C_TIM7);
  (cmd == 4) ? (time = C_TIM1) : (time = C_TIM7);
  go_to_cmd[0] = &timed_forward;
  go_to_cmd[1] = &timed_right;
  go_to_cmd[2] = &timed_left;
  go_to_cmd[3] = &timed_look;
  go_to_cmd[4] = &timed_inventory;
  go_to_cmd[5] = &timed_fork;
  go_to_cmd[6] = &timed_take;
  go_to_cmd[7] = &timed_set;
  go_to_cmd[8] = &timed_incantation;
  go_to_cmd[9] = &timed_broadcast;
  if (!(msg = malloc(sizeof(*msg))))
    return (false);
  msg->server = server;
  msg->player = player;
  msg->go_to_cmd = go_to_cmd[cmd];
  msg->res = res;
  return (msg_timer(msg, server->f, time));
}
