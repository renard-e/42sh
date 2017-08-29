/*
** my_isneg.c for my_isneg in /home/renard_e/Piscine_C_J03
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Sep 30 13:32:25 2015 gregoire renard
** Last update Fri Jan 22 04:20:03 2016 gregoire renard
*/

#include "my.h"

void	my_isneg(int n)
{
  if (n < 0)
    {
      my_putchar('N');
    }
  else
    {
      my_putchar('P');
    }
}
