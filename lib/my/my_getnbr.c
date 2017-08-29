/*
** my_getnbr.c for my_getnbr in /home/renard_e/Piscine/Piscine_C_J03
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Oct 13 11:09:48 2015 gregoire renard
** Last update Fri Jan 22 04:23:08 2016 gregoire renard
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nbr;
  int	ii;

  ii = 0;
  nbr = 0;
  i = 0;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	ii = ii + 1;
      i = i + 1;
    }
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9') && i < 10)
    {
      nbr = nbr * 10 + str[i] - 48;
      i = i + 1;
    }
  if (ii % 2 != 0)
    {
      nbr = nbr * (-1);
    }
  return (nbr);
}
