/*
** my_is_prime.c for my_is_prime in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Oct 14 16:01:00 2015 gregoire renard
** Last update Sat Oct 17 22:47:10 2015 gregoire renard
*/

int	my_is_prime(int nb)
{
  int	i;

  i = 2;
  while (i < nb)
    {
      if (nb % i == 0)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
