/*
** epur.c for epur in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_minishell2
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Thu Apr  7 14:19:24 2016 rodrigue rene
<<<<<<< HEAD:src_rene/epur.c
** Last update Mon May 30 12:44:23 2016 rodrigue rene
=======
** Last update Fri May 27 16:03:50 2016 gregoire renard
>>>>>>> edc3b8137b2b97ac45eb686c5ee13319e88195b2:lib/my/epur.c
*/

#include <stdlib.h>
#include "my.h"

void	fill_epur(char **s, int lenfinal, char *str, char c)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  (*s)[i + x] = ' ';
	  (*s)[i + x + 1] = str[i];
	  (*s)[i + x + 2] = ' ';
	  x = x + 2;
	}
      else
	(*s)[i + x] = str[i];
      i++;
    }
  (*s)[lenfinal] = '\0';
}

void	fill_epur_twice(char **s, char *str, char c)
{
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c && str[i + 2] != '\0')
	{
	  if (str[i + 3] == c)
	    {

	      (*s)[i - x] = str[i];
	      i = i + 3;
	      x = x + 2;

	      (*s)[i - x] = str[i];
	    }
	}
      else
	(*s)[i - x] = str[i];
      i++;
    }
  (*s)[i - x] = '\0';
}

void	epur_str(char **s, char *str, char c)
{
  int	i;
  int	len;
  int	lenfinal;

  i = 0;
  lenfinal = 0;
  len = my_strlen((*s));
  while ((*s)[i] != '\0')
    {
      if ((*s)[i] == c)
	lenfinal = lenfinal + 2;
      i++;
    }
  lenfinal = len + lenfinal;
  if (((*s) = malloc(lenfinal + 1)) == NULL)
    exit(0);
  (*s)[lenfinal] = '\0';
  fill_epur(s, lenfinal, str, c);
}

void	epur_twice(char **s, char *str, char c)
{
  int	i;
  int	zz;

  zz = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c && str[i + 2] != '\0')
	if (str[i + 3] == c)
	  zz++;
      i++;
    }
  if (zz != 0)
    {
      if (((*s) = malloc(my_strlen(str) - zz + 1)) == NULL)
	exit(0);
      fill_epur_twice(s, str, c);
    }
}
