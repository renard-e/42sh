/*
** my_swap.c for my_swap in /home/renard_e/Piscine_C_J04
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Oct  1 10:45:49 2015 gregoire renard
** Last update Fri Jan 22 04:22:32 2016 gregoire renard
*/

void	my_swap(int *a, int *b)
{
  int	i;

  i = *a;
  *a = *b;
  *b = i;
}
