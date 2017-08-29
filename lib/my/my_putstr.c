/*
** my_putstr2.c for my_putstr in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Oct 16 09:42:13 2015 gregoire renard
** Last update Sun Jun  5 20:37:36 2016 vincent nakache
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
