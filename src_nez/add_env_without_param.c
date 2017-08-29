/*
** add_env_without_param.c for add_env_without_param in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu May 26 15:37:10 2016 gregoire renard
** Last update Thu May 26 16:24:47 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int		remp_new_env(char **new_env, char *param, int i)
{
  char		*new_char_star;
  int		len;
  int		cpt;

  cpt = 0;
  len = my_strlen(param);
  if ((new_char_star = malloc(len + 2)) == NULL)
    return (-1);
  while (param[cpt] != '\0')
    {
      new_char_star[cpt] = param[cpt];
      cpt++;
    }
  new_char_star[cpt] = '=';
  new_char_star[cpt + 1] = '\0';
  if ((new_env[i] = my_strdup(new_char_star)) == NULL)
    return (-1);
  free(new_char_star);
  return (0);
}

int		new_simple_add(t_info *info, char **param)
{
  char		**new_env;
  int		indic;
  int		i;

  i = 0;
  indic = my_strlen_tabb(info->env);
  if ((new_env = malloc(sizeof(char *) * (indic + 2))) == NULL)
    return (-1);
  while (info->env[i] != NULL)
    {
      if ((new_env[i] = my_strdup(info->env[i])) == NULL)
	return (-1);
      i++;
    }
  if ((remp_new_env(new_env, param[1], i)) == -1)
    return (-1);
  new_env[i + 1] = NULL;
  info->env = new_env;
  return (0);
}

int		reset_simple_env(t_info *info, int addr)
{
  int		x;

  x = 0;
  while (info->env[addr][x] != '=')
    x++;
  info->env[addr][x + 1] = '\0';
  return (0);
}

int		add_env_without_param(t_info *info, char **param)
{
  int		addr;

  if ((addr = my_get_addr_env(info->env, param[1])) == -1)
    {
      if ((new_simple_add(info, param)) == -1)
	return (-1);
    }
  else
    if ((reset_simple_env(info, addr)) == -1)
      return (-1);
  return (0);
}
