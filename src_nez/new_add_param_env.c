/*
** new_add_param_env.c for new_add_param_env in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu May 26 16:58:27 2016 gregoire renard
** Last update Thu May 26 17:11:10 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

void		remp_new_char_star2(t_pos *pos, int *cpt,
				   char **param, char **new_char_star)
{
  while (param[pos->y][pos->x] != '\0')
    {
      (*new_char_star)[*cpt] = param[pos->y][pos->x];
      pos->x++;
      (*cpt)++;
    }
  (*new_char_star)[*cpt] = '=';
  (*cpt)++;
  pos->x = 0;
  pos->y++;
}

char		*remp_new_char_star(char **param)
{
  char		*new_char_star;
  int		len;
  t_pos		pos;
  int		cpt;

  pos.x = 0;
  pos.y = 1;
  cpt = 0;
  len = my_strlen(param[1]);
  len = len + my_strlen(param[2]);
  if ((new_char_star = malloc(len + 2)) == NULL)
    return (NULL);
  while (param[pos.y] != NULL)
    remp_new_char_star2(&pos, &cpt, param, &new_char_star);
  new_char_star[cpt - 1] = '\0';
  return (new_char_star);
}

int		concat_two_param(char **new_env, int i, char **param)
{
  char		*new_char_star;

  if ((new_char_star = remp_new_char_star(param)) == NULL)
    return (-1);
  if ((new_env[i] = my_strdup(new_char_star)) == NULL)
    return (-1);
  free(new_char_star);
  return (0);
}

int		new_add_param_env(t_info *info, char **param)
{
  char		**new_env;
  int		i;

  i = my_strlen_tabb(info->env);
  if ((new_env = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (-1);
  i = 0;
  while (info->env[i] != NULL)
    {
      if ((new_env[i] = my_strdup(info->env[i])) == NULL)
	return (0);
      i++;
    }
  if ((concat_two_param(new_env, i, param)) == -1)
    return (-1);
  new_env[i + 1] = NULL;
  info->env = new_env;
  return (0);
}
