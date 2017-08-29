/*
** my_strcmp.c for my_strcmp in 
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Oct 15 10:20:32 2015 gregoire renard
** Last update Fri Nov 27 19:42:05 2015 gregoire renard
*/

int	my_maj(char s1, char s2, int indic1, int indic2)
{
  int	dif;

  if ('a' <= s1 && s1 <= 'z')
    {
      s1 = s1 - 32;
      indic1 = 1;
    }
  if ('a' <= s2 && s2 <= 'z')
    {
      s2 = s2 - 32;
      indic2 = 1;
    }
  dif = s1 - s2;
  if (indic1 == 1)
    {
      s1 = s1 + 32;
      indic1 = 0;
    }
  if (indic2 == 1)
    {
      s2 = s2 + 32;
      indic2 = 0;
    }
  return (dif);
}

int	my_strcmp2(char s1, char s2, int dif, int stop)
{
  if (stop == 1)
    return (dif);
  else
    if (s1 == '\0')
      return (-1);
    else
      if (s2 == '\0')
	return (1);
      else
	return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	stop;
  int	dif;
  int	indic1;
  int	indic2;

  i = 0;
  indic1 = 0;
  indic2 = 0;
  stop = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && stop != 1)
    {
      dif = my_maj(s1[i], s2[i], indic1, indic2);
      if (dif == 0)
	i = i + 1;
      else
	stop = 1;
    }
  dif = my_strcmp2(s1[i], s2[i], dif, stop);
  return (dif);
}
