/*
** remp_before_quotes.c for remp_before_quotes in /home/nakach_v/str_to_wt_re
** 
** Made by vincent nakache
** Login   <nakach_v@epitech.net>
** 
** Started on  Wed Jun  1 16:23:57 2016 vincent nakache
** Last update Fri Jun  3 15:01:25 2016 vincent nakache
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int		remp_before_quotes(char *arg, char **cmd, t_all *all)
{
  if (all->e == 0)
    return (0);
  if (arg[all->e - 1] == ' ')
    return (0);
  all->dif = all->e - all->s;
  all->remp = all->s;
  if ((cmd[all->dimen] = malloc((all->dif + 1) * sizeof(char))) == NULL)
    return (-1);
  while (all->remp < all->e)
    {
      cmd[all->dimen][all->i] = arg[all->remp];
      all->i++;
      all->remp++;
    }
  cmd[all->dimen][all->dif] = '\0';
  all->i = 0;
  all->dimen++;
  return (0);
}

int		quotes_fct(t_all *all, char **cmd, char *arg)
{
  if (arg[all->e] == '\"')
    {
      if (remp_before_quotes(arg, cmd, all) == -1)
	return (-1);
      if (remp_quotes(arg, cmd, all) == -1)
	return (-1);
    }
  all->e++;
  return (0);
}
