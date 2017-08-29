/*
** my_strcat2.c for my_strcat in
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Fri Oct 16 09:44:51 2015 gregoire renard
** Last update Thu Jun  2 14:11:33 2016 rodrigue rene
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	c;

  i = 0;
  c = my_strlen(dest);
  while (src[i] != '\0')
    {
      dest[c + i] = src[i];
      i = i + 1;
    }
  dest[c + i] = '\0';
  return (dest);
}
