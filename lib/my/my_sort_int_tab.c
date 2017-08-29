/*
** my_sort_int_tab.c for my_sort_int_tab in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Oct 13 22:33:04 2015 gregoire renard
** Last update Wed Oct 14 08:24:10 2015 gregoire renard
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;
  int	tmp;

  i = 1;
  while (i < size)
    {
      tmp = tab[i];
      j = i;
      while (j > 0 && tab[j - 1] > tmp)
	{
	  tab[j] = tab[j - 1];
	  j = j - 1;
	}
      tab[j] = tmp;
      i = i + 1;
    }
}
