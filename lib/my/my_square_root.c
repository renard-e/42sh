/*
** my_square_root.c for my_square_root in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Oct 14 12:07:45 2015 gregoire renard
** Last update Sat Oct 17 23:11:22 2015 gregoire renard
*/

int	my_square_root(int nb)
{
  int	i;
  int	racine;

  racine = 0;
  i = 0;
  while (nb > racine)
    {
      racine = i * i;
      i = i + 1;
    }
  if (nb == racine)
    {
      i = i - 1;
      return (i);
    }
  else
    return (0);
}

