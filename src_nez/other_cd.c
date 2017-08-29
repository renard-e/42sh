/*
** other_cd.c for other_cd in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Mon May 30 13:19:12 2016 gregoire renard
** Last update Sun Jun  5 10:25:59 2016 Jean-Adrien Domage
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char		*save_pwd(char **env)
{
  char		*pwd_cpy;
  char		**param;
  int		addr;

  addr = my_get_addr_env(env, "PWD");
  if ((pwd_cpy = my_strdup(env[addr])) == NULL)
    return (NULL);
  epur_str(&pwd_cpy, pwd_cpy, '=');
  if ((param = my_str_to_word_tab(pwd_cpy)) == NULL)
    return (NULL);
  if ((pwd_cpy = concat_two_str_with_char("OLDPWD", param[2], '=')) == NULL)
    return (NULL);
  free_tab(param);
  return (pwd_cpy);
}

int		last_change_oldpwd(t_info *info, char *pwd)
{
  int		addr;

  addr = my_get_addr_env(info->env, "OLDPWD");
  if ((info->env[addr] = my_strdup(pwd)) == NULL)
    return (-1);
  free(pwd);
}

int		change_all_param(char **param, t_info *info)
{
  int		i;

  i = 0;
  while (param[i] != NULL)
    {
      if (param[i][0] == '.' && param[i][1] == '\0'
	  || param[i][0] == '/' && param[i][1] == '\0')
	i++;
      else
	{
	  if ((chdir(param[i])) == -1)
	    return (return_error_cd(param[i]));
	  if ((change_all_star_pwd(param[i], info)) == -1)
	    return (-1);
	  i++;
	}
    }
}

int		other_cd(t_info *info, char *directory)
{
  char		**param;
  char		*pwd;

  pwd = NULL;
  if ((access(directory, X_OK)) == -1)
    return (return_error_cd(directory));
  epur_str(&directory, directory, '/');
  if ((param = my_str_to_word_tab(directory)) == NULL)
    return (-1);
  if ((my_get_addr_env(info->env, "PWD")) != -1)
    if ((pwd = save_pwd(info->env)) == NULL)
      return (-1);
  if ((change_all_param(param, info)) == -1)
    return (-1);
  if (pwd != NULL)
    if ((last_change_oldpwd(info, pwd)) == -1)
      return (-1);
  return (0);
}
