/*
** my_strncpy.c for my_strncpy in /home/renard_e/Piscine_C_J06
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Oct  5 16:17:50 2015 gregoire renard
** Last update Tue Oct  6 23:12:54 2015 gregoire renard
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
