/*
** epur.c for epur in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Sun Jun  5 12:53:04 2016 rodrigue rene
** Last update Sun Jun  5 19:37:49 2016 vincent nakache
*/

#include <stdlib.h>
#include "rene.h"
#include "my.h"

void	delete_char(int i, char **str)
{
  while ((*str)[i] != '\0' && (*str)[i + 1] != '\0')
    {
      (*str)[i] = (*str)[i + 1];
      i++;
    }
  (*str)[i] = '\0';
}

void	fill_epur_twice_test(char **s, char *str, char c)
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
