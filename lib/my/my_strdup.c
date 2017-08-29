/*
** my_strdup.c for my_strdup in /home/renard_e/programmation_shell/PSU_2015_minishell1/lib/my
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Jan 21 17:58:57 2016 gregoire renard
** Last update Thu Jan 21 18:33:07 2016 gregoire renard
*/

#include <stdlib.h>

char		*my_strdup(char *str)
{
  char		*copy;
  int		i;
  int		o;

  o = 0;
  i = 0;
  while (str[i] != '\0')
    i++;
  if ((copy = malloc(i + 1)) == NULL)
    return (NULL);
  while (str[o] != '\0')
    {
      copy[o] = str[o];
      o++;
    }
  copy[i] = '\0';
  return (copy);
}
