/*
** verif_separator.c for verif_separator in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene/entrainement
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Mon May 30 19:53:12 2016 rodrigue rene
** Last update Sun Jun  5 15:12:23 2016 rodrigue rene
*/

#include <stdlib.h>
#include "my.h"

void	remp_tabb_int(int **tabb, int x)
{
  int	i;

  i = 0;
  while (i <= x)
    {
      (*tabb)[i] = -1;
      i++;
    }
}

int	verif_separator_if(int	*tabi,
			   int	*sep_place,
			   int	len,
			   int	*beginning,
			   int	i)
{
  (*beginning) = 'N';
  if (sep_place[i - 1] == sep_place[i] - 1)
    (*beginning) = 'B';
  if (tabi[i] == 1)
    {
      if ((*beginning) == 'B' || (sep_place[i] + 1) == len
	  || sep_place[i + 1] == (sep_place[i] + 1))
	return (error_null_command());
      (*beginning) = 'N';
    }
  else if (tabi[i] == 2)
    {
      if ((*beginning) != 'B' &&
	  ((sep_place[i] + 1) == len ||
	   sep_place[i + 1] == (sep_place[i] + 1)))
	return (error_null_command());
      (*beginning) = 'N';
    }
  (*beginning) = 'N';
  return (0);
}

int	verif_separator_part_two(int *tabi, int *s_p, int len, int i)
{
  int	begin;

  begin = 'N';
  if (s_p[i] == 0)
    begin = 'B';
  while (s_p[i] != -1)
    {
      if (i > 0 && verif_separator_if(tabi, s_p, len, &begin, i) == -1)
	return (-1);
      else if (tabi[i] == 1)
	{
	  if (begin == 'B' || (s_p[i] + 1) == len || s_p[i + 1] == (s_p[i] + 1))
	    return (error_null_command());
	  begin = 'N';
	}
      else if (tabi[i] == 2)
	{
	  if (begin != 'B' && ((s_p[i] + 1) == len || s_p[i + 1] == (s_p[i] + 1)))
	    return (error_null_command());
	  begin = 'N';
	}
      i++;
    }
  return (0);
}

int	verif_separator(t_info *help)
{
  int	x;

  if ((help->tabi = malloc(sizeof(int) *
			   ((x = my_strlen_tabb(help->tabb)) + 1))) == NULL
      || (help->sep_place = malloc(sizeof(int) * (x  + 1))) == NULL)
    my_exit_malloc();
  remp_tabb_int(&help->tabi, x);
  remp_tabb_int(&help->sep_place, x);
  remp_tabb_int_two(help->tabb, &help->tabi, &help->sep_place, 0);
  return (verif_separator_part_two(help->tabi, help->sep_place, x, 0));
}
