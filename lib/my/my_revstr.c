/*
** my_revstr.c for my_revstr in /home/renard_e/Piscine_C_J06/ex_04
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Oct  5 19:26:06 2015 gregoire renard
** Last update Sat Oct 17 23:06:43 2015 gregoire renard
*/

char	*my_revstr(char *str)
{
  int	i;
  int	a;
  int	b;

  i = 0;
  a = 0;
  b = 0;
  while (str[a] != '\0')
    {
      a = a + 1;
    }
  a = a - 1;
  while (i < a)
    {
      b = str[i];
      str[i] = str[a];
      str[a] = b;
      i = i + 1;
      a = a - 1;
    }
  return (str);
}
