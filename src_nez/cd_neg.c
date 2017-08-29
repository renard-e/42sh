/*
** cd_neg.c for cd_neg in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Jun  1 13:34:35 2016 gregoire renard
** Last update Sun Jun  5 10:23:34 2016 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char		*attribute_neg(t_info *info, char *search)
{
  int		addr;
  char		*cut;
  char		**param;

  cut = NULL;
  if ((addr = my_get_addr_env(info->env, search)) == -1)
    return (NULL);
  if ((cut = my_strdup(info->env[addr])) == NULL)
    return (NULL);
  epur_str(&cut, cut, '=');
  if ((param = my_str_to_word_tab(cut)) == NULL)
    return (NULL);
  if (param[2] != NULL)
    if ((cut = my_strdup(param[2])) == NULL)
      return (NULL);
  free_tab(param);
  return (cut);
}

void		swap_old_new(t_info *info)
{
  char		*tmp;

  tmp = info->pwd;
  info->pwd = info->oldpwd;
  info->oldpwd = tmp;
}

int		cd_neg(t_info *info)
{
  if ((my_get_addr_env(info->env, "PWD")) != -1)
    if ((info->pwd = attribute_neg(info, "PWD")) == NULL)
      return (-1);
  if ((my_get_addr_env(info->env, "OLDPWD")) != -1)
    if ((info->oldpwd = attribute_neg(info, "OLDPWD")) == NULL)
      return (-1);
  if ((chdir(info->oldpwd)) == -1)
    return (return_error_cd(info->oldpwd));
  if ((change_all_star_pwd(info->oldpwd, info)) == -1)
    return (-1);
  swap_old_new(info);
  return (0);
}
