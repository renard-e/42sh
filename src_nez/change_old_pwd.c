/*
** change_old_pwd.c for change_old_pwd in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May 29 16:19:21 2016 gregoire renard
** Last update Thu Jun  2 17:01:38 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "nez.h"
#include "my.h"

int		update_old(t_info *info, char *new_old)
{
  int		addr;

  addr = my_get_addr_env(info->env, "OLDPWD");
  if ((info->env[addr] = my_strdup(new_old)) == NULL)
    return (-1);
  return (0);
}

int		change_old_pwd(t_info *info)
{
  char		*pwd;
  char		**pwd2;
  char		*new_old;
  int		addr;

  if ((addr = my_get_addr_env(info->env, "PWD")) == -1)
    return (-2);
  if ((pwd = my_strdup(info->env[addr])) == NULL)
    return (-1);
  epur_str(&pwd, pwd, '=');
  if ((pwd2 = my_str_to_word_tab(pwd)) == NULL)
    return (-1);
  if ((new_old = concat_two_str_with_char("OLDPWD", pwd2[2], '=')) == NULL)
    return (-1);
  if ((update_old(info, new_old)) == -1)
    return (-1);
  free(new_old);
  free_tab(pwd2);
  free(pwd);
  return (0);
}
