/*
** my_str_isnum.c for my_str_isnum in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sat Oct 17 14:28:29 2015 gregoire renard
** Last update Sat Oct 17 23:19:59 2015 gregoire renard
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
