/*
** double_redirect.c for double in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Jun  5 19:13:43 2016 gregoire renard
** Last update Sun Jun  5 20:19:25 2016 gregoire renard
*/

#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int		double_redirect_d(t_info *info, int cpt_w)
{
  t_redi	redi;

  if ((separate_redirect(info, &redi, cpt_w)) == -1)
    return (-1);
  if ((redi.fd = open(redi.file, O_WRONLY | O_APPEND | O_CREAT,
		      S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    return (-1);
  if ((redi.pid = fork()) == -1)
    return (-1);
  if (redi.pid == 0)
    {
      if ((dup2(redi.fd, 1)) == -1)
	return (-1);
      if ((close(redi.fd)) == -1)
	return (-1);
      if ((execve(redi.fct, redi.fct_arg, info->env)) == -1)
	exit(-1);
    }
  if ((waitpid(-1, &redi.status, 0)) == -1)
    return (-1);
  status_fct(redi.status);
  return (0);
}
