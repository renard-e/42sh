/*
** word_word.c for word_word in /home/renard_e/systeme_unix/PSU_2015_42sh/lib/my
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue May 24 09:11:48 2016 gregoire renard
** Last update Fri Jun  3 22:41:49 2016 rodrigue rene
*/

#include <stdlib.h>
#include "my.h"

int		word_word(char *str1, char *str2)
{
  int		i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (-1);
  while (str1[i] != '\0' && str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (-1);
      i++;
    }
  if (str1[i] == '\0' && str2[i] == '\0')
    return (1);
  return (-1);
}

int	grep_word(char *str, char **tabb)
{
  int	y;

  y = 0;
  while (tabb[y] != NULL)
    {
      if (word_word(str, tabb[y]) == 1)
	return (y);
      y++;
    }
  return (-1);
}
