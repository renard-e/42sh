/*
** my_strcpy.c for my_strcpy in /home/renard_e/Piscine_C_J06
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Oct  5 14:04:31 2015 gregoire renard
** Last update Sat Oct 17 23:14:44 2015 gregoire renard
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = src[i];
  return (dest);
}
