/*
** change_pwd.c for change_pwd in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May 29 17:40:46 2016 gregoire renard
** Last update Fri Jun  3 11:59:19 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int		replace_non_all_pwd(t_info *info, char *directory)
{
  char		*new_pwd;
  int		addr;
  int		i;

  if ((addr = my_get_addr_env(info->env, "PWD")) == -1)
    return (-2);
  if ((new_pwd = my_strdup(info->env[addr])) == NULL)
    return (-1);
  i = my_strlen(new_pwd) - 1;
  if (new_pwd[i] == '/')
    {
      if ((new_pwd =
	   concat_two_str_with_char(new_pwd, directory, '\0')) == NULL)
	return (-1);
    }
  else
    if ((new_pwd =
	 concat_two_str_with_char(new_pwd, directory, '/')) == NULL)
      return (-1);
  if ((info->env[addr] = my_strdup(new_pwd)) == NULL)
    return (-1);
  return (0);
}

int		all_replace_pwd(t_info *info, char *directory)
{
  char		*new_pwd;
  int		addr;

  if ((addr = my_get_addr_env(info->env, "PWD")) == -1)
    return (-2);
  if ((new_pwd = concat_two_str_with_char("PWD", directory, '=')) == NULL)
    return (-1);
  if ((info->env[addr] = my_strdup(new_pwd)) == NULL)
    return (-1);
  free(new_pwd);
  return (0);
}

int		back_fct(t_info *info)
{
  int		i;
  int		addr;

  if ((addr = my_get_addr_env(info->env, "PWD")) == -1)
    return (-2);
  i = my_strlen(info->env[addr]);
  while (info->env[addr][i] != '/' && i >= 0)
    i--;
  if (info->env[addr][i - 1] == '=')
    info->env[addr][i + 1] = '\0';
  else
    info->env[addr][i] = '\0';
}

int		change_pwd(t_info *info, char *directory)
{
  if (directory[0] == '/')
    {
      if ((all_replace_pwd(info, directory)) == -1)
	return (-1);
    }
  else if (directory[0] == '.' && directory[1] == '.'
	   && directory[2] == '\0')
    {
      if ((back_fct(info)) == -1)
	return (-1);
    }
  else
    if ((replace_non_all_pwd(info, directory)) == -1)
      return (-1);
  return (0);
}
