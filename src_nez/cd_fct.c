/*
** cd_fct.c for cd_fct in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Fri May 27 14:54:40 2016 gregoire renard
** Last update Thu Jun  2 21:42:41 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "domage.h"
#include "my.h"

int		cd_fct(t_info *info, char **param)
{
  int	ret;

  ret = 0;
  if ((my_strlen_tabb(param)) > 2)
    return (merror(CD_ERROR, -1));
  else if (param[1] == NULL || (param[1][0] == '-' && param[1][1] == '-' &&
				param[1][2] == '\0'))
    {
      if ((ret = execute_cd_home(info)) == -1)
	return (merror(CD_MALLOC_ERROR, -1));
    }
  else if (param[1][0] == '-' && param[1][1] == '\0')
    {
      if ((ret = cd_neg(info)) == -1)
	return (merror(CD_MALLOC_ERROR, -1));
    }
  else
    if ((ret = other_cd(info, param[1])) == -1)
      return (merror(CD_MALLOC_ERROR, -1));
  return (ret);
}
