/*
** add_env_with_param.c for add_env_with_param in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu May 26 15:35:22 2016 gregoire renard
** Last update Thu May 26 17:19:13 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int		add_env_with_param(t_info *info, char **param)
{
  int		addr;

  if ((addr = my_get_addr_env(info->env, param[1])) == -1)
    {
      if ((new_add_param_env(info, param)) == -1)
	return (-1);
    }
  else
    if ((concat_two_param(info->env, addr, param)) == -1)
      return (-1);
  return (0);
}
