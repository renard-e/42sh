/*
** my_power_rec.c for my_power_rec in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Oct 14 09:16:09 2015 gregoire renard
** Last update Fri Jan 22 04:23:59 2016 gregoire renard
*/

int	my_power_rec2(int nb, int power, int bougepas)
{
  if (power > 1)
    {
      nb = nb * bougepas;
      power = power - 1;
      my_power_rec2(nb, power, bougepas);
    }
  return (nb);
}

void	my_power_rec(int nb, int power)
{
  my_power_rec2(nb, power, nb);
}
