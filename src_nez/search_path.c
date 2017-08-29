/*
** search_path.c for search_path in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue May 24 10:27:45 2016 gregoire renard
** Last update Fri Jun  3 18:48:33 2016 rodrigue rene
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void		set_var_cpt(t_cpt *cpt, char *path)
{
  cpt->end = 0;
  cpt->start = 0;
  while (path[cpt->end] != '/' && path[cpt->end] != '\0')
    cpt->end++;
  cpt->start = cpt->end;
}

void		remp_fct(t_cpt cpt, char *param0, char *path, char *fct)
{
  int		i;
  int		i2;

  i = 0;
  i2 = 0;
  while (i < cpt.dif)
    {
      fct[i] = path[cpt.start];
      i++;
      cpt.start++;
    }
  fct[i] = '/';
  i++;
  while (param0[i2] != '\0')
    {
      fct[i] = param0[i2];
      i++;
      i2++;
    }
  fct[i] = '\0';
}

char		*search_full_path(char *param0, char *path)
{
  t_cpt		cpt;
  char		*fct;

  set_var_cpt(&cpt, path);
  while (path[cpt.end] != '\0')
    {
      while (path[cpt.end] != ':' && path[cpt.end] != '\0')
	cpt.end++;
      cpt.dif = cpt.end - cpt.start;
      if ((fct = malloc(cpt.dif + my_strlen(param0) + 2)) == NULL)
	return (NULL);
      remp_fct(cpt, param0, path, fct);
      if ((access(fct, X_OK)) != -1)
	return (fct);
      if (path[cpt.end] != '\0')
	cpt.end++;
      cpt.start = cpt.end;
      free(fct);
    }
  return (NULL);
}

char		*search_path(char *param0, char **env)
{
  int		addr_path;
  char		*fct;

  if ((access(param0, X_OK)) != -1)
    return (param0);
  if ((addr_path = my_get_addr_env(env, "PATH")) == -1)
    return (NULL);
  if ((fct = search_full_path(param0, env[addr_path])) == NULL)
    return (NULL);
  return (fct);
}
