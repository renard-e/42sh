/*
** unsetenv_fct.c for unsteenv in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed May 25 16:34:40 2016 gregoire renard
** Last update Thu Jun  2 21:43:05 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "domage.h"
#include "my.h"

int		copy_without_addr(t_info *info, int addr)
{
  int		i;
  int		cpt_n;
  int		cpt_e;
  char		**new_env;

  i = my_strlen_tabb(info->env);
  if ((new_env = malloc(sizeof(char *) * i)) == NULL)
    return (-1);
  cpt_n = 0;
  cpt_e = 0;
  while (info->env[cpt_e] != NULL)
    {
      if (cpt_e != addr)
	{
	  if ((new_env[cpt_n] = my_strdup(info->env[cpt_e])) == NULL)
	    return (-1);
	  cpt_n++;
	}
      cpt_e++;
    }
  new_env[cpt_n] = NULL;
  info->env = new_env;
  return (0);
}

int		all_unsetenv(t_info *info, char **param)
{
  int		cpt_w;
  int		addr;

  cpt_w = 1;
  while (param[cpt_w] != NULL)
    {
      if ((addr = my_get_addr_env(info->env, param[cpt_w])) != -1)
	{
	  if ((copy_without_addr(info, addr)) == -1)
	    return (-1);
	}
      cpt_w++;
    }
  return (0);
}

int		unsetenv_fct(t_info *info, char **param)
{
  if (param[1] == NULL)
    return (merror(USETENV_ERROR1, -1));
  if ((all_unsetenv(info, param)) == -1)
    return (merror(USETENV_ERROR2, -1));
  return (0);
}
