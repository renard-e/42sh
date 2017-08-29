/*
** my_strcapitalize.c for my_strcapitalize in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri Oct 16 10:44:06 2015 gregoire renard
** Last update Sun Oct 18 12:20:46 2015 gregoire renard
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 1;
  if (str[0] >= 'a' && str[0] <= 'z')
    str[0] = str[0] - 32;
  while (str[i] != '\0')
    {
      if ((str[i] >= ' ' && str[i] <= '/') || (str[i] >= ':' && str[i] <= '@'))
	if ((str[i + 1] >= 'a' && str[i + 1] <= 'z'))
	  {
	    str[i + 1] = str[i + 1] - 32;
	    i = i + 1;
	  }
      if ((str[i] >= 91 && str[i] <= 96) || (str[i] >= '{' && str[i] <= '}'))
	if ((str[i + 1] >= 'a' && str[i + 1] <= 'z'))
	  str[i + 1] = str[i + 1] - 32;
      i = i + 1;
    }
  return (str);
}
