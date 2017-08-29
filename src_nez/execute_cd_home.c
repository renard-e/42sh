/*
** excute_cd_home.c for excute_cd_home in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 27 15:29:24 2016 gregoire renard
** Last update Sun Jun  5 17:46:29 2016 gregoire renard
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int		return_error_cd(char *str)
{
  my_putstr_error(str);
  my_putstr_error(": Permission denied.\n");
  return (-2);
}

int		execute_cd_home(t_info *info)
{
  int		addr;
  char		*home;
  char		**home2;

  if ((addr = my_get_addr_env(info->env, "HOME")) == -1)
    {
      my_putstr_error("Error : no home in env\n");
      return (-2);
    }
  if ((home = my_strdup(info->env[addr])) == NULL)
    return (-1);
  epur_str(&home, home, '=');
  if ((home2 = my_str_to_word_tab(home)) == NULL)
    return (-1);
  if (home2[2] == NULL)
    return (return_error_cd(NULL));
  if ((chdir(home2[2]) == -1))
    return (return_error_cd(home2[2]));
  if ((change_all_star_pwd(home2[2], info)) == -1)
    return (-2);
  free(home);
  free(home2);
  return (0);
}
