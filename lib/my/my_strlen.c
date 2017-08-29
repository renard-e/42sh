/*
** my_strlen2.c for my_strlen in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Oct 16 09:46:58 2015 gregoire renard
** Last update Wed Jan 20 09:06:48 2016 gregoire renard
*/

int	my_strlen(char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a = a + 1;
  return (a);
}
