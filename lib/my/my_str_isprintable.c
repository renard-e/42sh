/*
** my_str_isprintable.c for my_str_isprintable in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sat Oct 17 15:35:29 2015 gregoire renard
** Last update Sat Oct 17 23:20:38 2015 gregoire renard
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 32 && str[i] <= 126)
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
