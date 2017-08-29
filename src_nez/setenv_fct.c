/*
** setenv_fct.c for setenv_fct in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu May 26 09:12:12 2016 gregoire renard
** Last update Sun Jun  5 17:39:41 2016 gregoire renard
*/

#include <stdlib.h>
#include "domage.h"
#include "my.h"

int		test_param_setenv(char **param)
{
  t_pos		pos;

  pos.x = 0;
  pos.y = 1;
  while (param[pos.y] != NULL)
    {
      while (param[pos.y][pos.x] != '\0')
	{
	  if (('A' <= param[pos.y][pos.x] && param[pos.y][pos.x] <= 'Z')
	      || ('a' <= param[pos.y][pos.x] && param[pos.y][pos.x] <= 'z')
	      || ('0' <= param[pos.y][pos.x] && param[pos.y][pos.x] <= '9')
	      || param[pos.y][pos.x] == '/' || param[pos.y][pos.x] == '_'
	      || param[pos.y][pos.x] == '-' || param[pos.y][pos.x] == ':'
	      || param[pos.y][pos.x] == '.')
	    pos.x++;
	  else
	    return (-1);
	}
      pos.x = 0;
      pos.y++;
    }
  return (0);
}

int		setenv_real(t_info *info, char **param)
{
  if ((test_param_setenv(param)) == -1)
    {
      my_putstr_error("setenv: Variable name must ");
      my_putstr_error("contain alphanumeric characters.\n");
      return (-2);
    }
  if (param[2] == NULL)
    {
      if ((add_env_without_param(info, param)) == -1)
	return (-1);
    }
  else
    if ((add_env_with_param(info, param)) == -1)
      return (-1);
  return (0);
}

int		setenv_fct(t_info *info, char **param)
{
  int		indic;

  if ((indic = my_strlen_tabb(param)) >= 4)
    return (merror(SETENV_ERROR, -1));
  else if (indic == 1)
    aff_tab(info->env);
  else
    if ((setenv_real(info, param)) == -1)
      return (merror(SETENV_MALLOC_ERROR, -1));
  return (0);
}
