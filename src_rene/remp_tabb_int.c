/*
** remp_tabb_int.c for remp_tabb_int in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Fri Jun  3 20:54:47 2016 rodrigue rene
** Last update Sun Jun  5 13:03:24 2016 rodrigue rene
*/

#include "my.h"
#include "rene.h"

void	remp_tabb_int_two(char **tabb, int **tabi, int **separ_place, int i)
{
  int	z;

  z = 0;
  while (tabb[i] != NULL)
    {
      if (word_word("&&", tabb[i]) == 1)
	{
	  (*tabi)[z] = 2;
	  (*separ_place)[z] = i;
	  z++;
	}
      else if (word_word("||", tabb[i]) == 1)
	{
	  (*tabi)[z] = 1;
	  (*separ_place)[z] = i;
	  z++;
	}
      else if (word_word(";", tabb[i]) == 1)
	{
	  (*tabi)[z] = 0;
	  (*separ_place)[z] = i;
	  z++;
	}
      i++;
    }
}

void	remp_tabb_int_pipe(char **tabb, int **tabi, int **separ_place)
{
  int	i;
  int	z;

  i = 0;
  z = 0;
  while (tabb[i] != NULL)
    {
      if (word_word("|", tabb[i]) == 1)
	{
	  (*tabi)[z] = 1;
	  (*separ_place)[z] = i;
	  z++;
	}
      i++;
    }
}
