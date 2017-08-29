/*
** my_putstr_error.c for my_putstr_error in /home/renard_e/bin/Makefile_lib/lib/my
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Sat May 14 15:10:53 2016 gregoire renard
** Last update Sun Jun  5 13:55:25 2016 rodrigue rene
*/

#include <unistd.h>
#include "my.h"

void		my_putstr_error(char *str)
{
  write(2, str, my_strlen(str));
}

void	my_putstrd(char *str, int i)
{
  my_putstr(str);
  my_put_nbr(i);
}
