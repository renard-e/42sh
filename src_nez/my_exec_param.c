/*
** my_exec_param.c for my_exec_param in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue May 24 09:57:08 2016 gregoire renard
** Last update Sun Jun  5 17:39:22 2016 gregoire renard
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		my_exec_param(char **param, t_info *info)
{
  char		*fct;
  pid_t		pid;
  int		status;

  if (param[0] == NULL)
    return (0);
  if ((fct = search_path(param[0], info->env)) == NULL)
    return (-1);
  if ((test_fct(fct)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    if ((execve(fct, param, info->env)) == -1)
      exit(-1);
  if ((waitpid(-1, &status, 0)) == -1)
    return (-1);
  status_fct(status);
  return (0);
}
