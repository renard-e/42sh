/*
** verif_syntax.c for verif_syntax in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene/entrainement
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Tue May 31 18:52:50 2016 rodrigue rene
** Last update Sun Jun  5 17:24:47 2016 rodrigue rene
*/

#include <stdlib.h>
#include "my.h"

int	good_redirect(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  if (str[i] == '>' || str[i] == '<')
    while (str[i] != 0)
      {
	i++;
      }
  if (i > 2)
    return (error_missing());
  else if (i > 0)
    return (1);
  return (0);
}

int	good_pipe(char **tabb)
{
  int	i;

  i = 0;
  while (tabb[i] != NULL)
    {
      if (word_word("|", tabb[i]) != -1 && (i == 0 || tabb[i + 1] == NULL))
	return (-1);
      i++;
    }
}

int	verif_syntax(t_info *help)
{
  int	ret;
  int	prev_ret;
  int	x;
  int	y;

  x = 0;
  y = 0;
  ret = 0;
  prev_ret = 0;
  while (help->triple_tabb[y] != NULL)
    {
      while (help->triple_tabb[y][x] != NULL)
	{
	  if (((ret = good_redirect(help->triple_tabb[y][x])) == -1) ||
	      (good_pipe(help->triple_tabb[y]) == -1))
	    return (-1);
	  if (ret == 1 && (prev_ret == 1 || help->triple_tabb[y][x + 1] == NULL))
	    return (-1);
	  prev_ret = ret;
	  x++;
	}
      x = 0;
      y++;
    }
  return (0);
}
