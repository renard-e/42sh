/*
** my_strupcase.c for my_strupcase in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Oct 15 17:20:16 2015 gregoire renard
** Last update Fri Oct 16 09:39:47 2015 gregoire renard
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
