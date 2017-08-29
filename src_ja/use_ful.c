/*
** use_ful.c for 42sh in /home/alice/rendu/TODO/PSU_2015_42sh/src_ja
** 
** Made by Jean-Adrien Domage
** Login   <domage_j@epitech.net>
** 
** Started on  Wed Jun  1 16:56:50 2016 Jean-Adrien Domage
** Last update Fri Jun  3 22:22:48 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "domage.h"
#include "kopo.h"
#include "my.h"

void	free_builtin_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i += 1;
    }
}

char	**init_builtin_fct(char **tab)
{
  if ((tab = malloc(sizeof(char *) * 6)) == NULL)
    return (verror(MALLOC_ERROR));
  tab[0] = my_strdup(EXIT);
  tab[1] = my_strdup(UNSETENV);
  tab[2] = my_strdup(SETENV);
  tab[3] = my_strdup(CD);
  tab[4] = my_strdup(ECHO);
  tab[5] = NULL;
  builtin_fct[0] = &exit_fct;
  builtin_fct[1] = &unsetenv_fct;
  builtin_fct[2] = &setenv_fct;
  builtin_fct[3] = &cd_fct;
  builtin_fct[4] = &echo;
  builtin_fct[5] = NULL;
  return (tab);
}

char	*my_nstrcpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (n > my_strlen(dest))
    return (NULL);
  while (src[i] && dest[i + n])
    {
      dest[i + n] = src[i];
      i = i + 1;
    }
  return (dest);
}
