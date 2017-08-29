/*
** my_strstr.c for my_strstr in /home/renard_e/Piscine_C_J06/ex_05
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Oct  6 12:28:07 2015 gregoire renard
** Last update Thu Jun  2 17:16:45 2016 Jean-Adrien Domage
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (my_strlen(to_find) > my_strlen(str))
    return (NULL);
  while (str[i])
    {
      if (str[i] == to_find[j])
	j += 1;
      else
	j = 0;
      if (j == my_strlen(to_find))
	return (str + i);
      i += 1;
    }
  return (NULL);
}
