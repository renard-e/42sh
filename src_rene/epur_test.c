/*
** epur_test.c for epur_test in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene/entrainement
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Mon May 30 12:39:55 2016 rodrigue rene
** Last update Sun Jun  5 12:54:57 2016 rodrigue rene
*/

#include <stdlib.h>
#include "my.h"

void	fill_epur_test(char **s, int lenfinal, char *str, char c)
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

void	epur_minishell1_str_part2_test(char **s, char *str, char c)
{
  int	i;
  int	len;
  int	lenfinal;

  i = 0;
  lenfinal = 0;
  len = my_strlen((*s));
  while (str[i] != '\0')
    {
      if (str[i] == c)
	lenfinal = lenfinal + 2;
      i++;
    }
  lenfinal = len + lenfinal;
  if (((*s) = malloc(lenfinal + 1)) == NULL)
    my_exit_malloc();
  (*s)[lenfinal] = '\0';
  fill_epur_test(s, lenfinal, str, c);
}

void	epur_twice_test(char **s, char *str, char c)
{
  int	i;
  int	zz;

  zz = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c && str[i + 2] != '\0')
	if (str[i + 3] == c)
	  {
	    delete_char(i + 1, s);
	    delete_char(i + 1, s);
	    zz++;
	  }
      i++;
    }
}

void	epur_minishell1_str_test(char **s, char *str)
{
  epur_minishell1_str_part2_test(s, str, '|');
  epur_minishell1_str_part2_test(s, (*s), '>');
  epur_minishell1_str_part2_test(s, (*s), '<');
  epur_minishell1_str_part2_test(s, (*s), ';');
  epur_minishell1_str_part2_test(s, (*s), '&');
  epur_twice_test(s, (*s), '>');
  epur_twice_test(s, (*s), '<');
  epur_twice_test(s, (*s), '|');
  epur_twice_test(s, (*s), '&');
}
