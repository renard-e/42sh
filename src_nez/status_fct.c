/*
** status_fct.c for status_fct in /home/renard_e/programmation_shell/PSU_2015_minishell1
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Jan 24 22:41:19 2016 gregoire renard
** Last update Tue May 24 15:14:31 2016 gregoire renard
*/

#include <sys/wait.h>
#include "my.h"

void		status_fct(int status)
{
  int		sign;

  sign = WTERMSIG(status);
  if (sign == SIGSEGV )
    my_putstr("Segmentation fault\n");
  else if (sign == SIGKILL || sign == SIGQUIT)
    my_putstr("SIGKILL or SIGQUIT\n");
  else if (sign == SIGHUP)
    my_putstr("hangup detected on controlling terminal\n");
  else if (sign == SIGABRT)
    my_putstr("abort signal from abort\n");
  else if (sign == SIGALRM)
    my_putstr("timer signal from alarm\n");
  else if (sign == SIGTERM)
    my_putstr("Termination signal\n");
  else if (sign == SIGCHLD)
    my_putstr("Child stopped or terminated\n");
  else if (sign == SIGSTOP)
    my_putstr("Stop process\n");
  else if (sign == SIGTTIN)
    my_putstr("Terminal input for background process\n");
  else if (sign == SIGTTOU)
    my_putstr("Terminal output for background process\n");
}
