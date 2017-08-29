/*
** free_tabb.c for free_tabb in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Thu Jun  2 18:33:19 2016 rodrigue rene
** Last update Thu Jun  2 19:39:37 2016 rodrigue rene
*/

#include <stdlib.h>
#include "my.h"
#include "rene.h"

void	free_str(char *str)
{
  free(str);
}

void	free_tabb(char **tabb)
{
  int	i;

  i = 0;
  while (tabb[i] != NULL)
    {
      free(tabb[i]);
      i++;
    }
  free(tabb);
}

void	free_triple_tabb(char ***tabbb)
{
  int	i;

  i = 0;
  while (tabbb[i] != NULL)
    {
      free_tabb(tabbb[i]);
      i++;
    }
  free(tabbb);
}
