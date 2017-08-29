/*
** my_str_isupper.c for my_str_isupper in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sat Oct 17 15:16:32 2015 gregoire renard
** Last update Sat Oct 17 23:21:41 2015 gregoire renard
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
