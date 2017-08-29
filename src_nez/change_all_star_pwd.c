/*
** change_all_star_pwd.c for change_all_star_pwd in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 27 18:10:07 2016 gregoire renard
** Last update Sun May 29 17:44:18 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int		change_all_star_pwd(char *directory, t_info *info)
{
  if ((my_get_addr_env(info->env, "OLDPWD")) != -1 &&
      (my_get_addr_env(info->env, "PWD")) != -1)
    {
      if ((change_old_pwd(info)) == -1)
	return (-1);
    }
  if ((my_get_addr_env(info->env, "PWD")) != -1)
    {
      if ((change_pwd(info, directory)) == -1)
	return (-1);
    }
  free(directory);
  return (0);
}
