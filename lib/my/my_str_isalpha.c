/*
** my_str_isalpha.c for my_str_isalpha in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sat Oct 17 09:31:34 2015 gregoire renard
** Last update Sat Oct 17 23:16:02 2015 gregoire renard
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
