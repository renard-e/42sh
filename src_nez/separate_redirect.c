/*
** separate_redirect.c for separate in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Jun  5 19:35:13 2016 gregoire renard
** Last update Sun Jun  5 20:30:55 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int		grep_fct_arg(char **param, t_redi *redi, int cpt_w)
{
  int		i;

  i = 0;
  if ((redi->fct_arg = malloc(sizeof(char *) * (cpt_w + 1))) == NULL)
    return (-1);
  redi->fct_arg[cpt_w] = NULL;
  while (i < cpt_w)
    {
      if ((redi->fct_arg[i] = my_strdup(param[i])) == NULL)
	return (-1);
      i++;
    }
  return (0);
}

int		grep_file(char **param, t_redi *redi, int cpt_w)
{
  if (param[cpt_w + 1] != NULL)
    {
      if ((redi->file = my_strdup(param[cpt_w + 1])) == NULL)
	return (-1);
      return (0);
    }
  my_putstr_error("Missing name for redirect.\n");
  return (-1);
}

int		grep_fct(char **param, t_redi *redi, t_info *info)
{
  if (param[0] != NULL)
    {
      if ((redi->fct = my_strdup(param[0])) == NULL)
	return (-1);
      if ((redi->fct = search_path(redi->fct, info->env)) == NULL)
	return (-1);
      return (0);
    }
  return (-1);
}

int		separate_redirect(t_info *info, t_redi *redi, int cpt_w)
{
  if (TABB[0][0] == '>' || TABB[0][0] == '<')
    {
      my_putstr_error("Invalid null command.\n");
      return (-1);
    }
  if ((grep_fct(TABB, redi, info)) == -1)
    return (-1);
  if ((grep_file(TABB, redi, cpt_w)) == -1)
    return (-1);
  if ((grep_fct_arg(TABB, redi, cpt_w)) == -1)
    return (-1);
  return (0);
}
