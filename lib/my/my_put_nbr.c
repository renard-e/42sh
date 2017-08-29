/*
** my_put_nbr.c for my_put_nbr in /home/renard_e/rendu/exo_re/put_nbr
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Oct 15 12:58:59 2015 gregoire renard
** Last update Wed Jun  1 12:11:38 2016 rodrigue rene
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	div;

  div = 1;
  while (nb / div >= 10)
    {
      div = div * 10;
    }
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
      my_put_nbr(nb);
    }
  if (nb >= 10)
    {
      while (div != 0)
	{
	  my_putchar(nb / div % 10 + '0');
	  div = div / 10;
	}
    }
  if (nb < 10)
    my_putchar(nb + '0');
}
