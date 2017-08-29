/*
** my_strlowcase.c for my_strlowcase in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Oct 16 09:56:58 2015 gregoire renard
** Last update Sat Oct 17 23:23:07 2015 gregoire renard
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str != '\0')
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
	str[i] = str [i] + 32;
      i = i + 1;
    }
  return (str);
}
