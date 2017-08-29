/*
** concat_two_str_with_char.c for concat_two_str_with_char in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Fri May 27 17:16:04 2016 gregoire renard
** Last update Fri Jun  3 11:59:59 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

void		remp_first_str(char *first, char **new_str,
			       int *i_new, int i_all)
{
  while (first[i_all] != '\0')
    {
      (*new_str)[*i_new] = first[i_all];
      (*i_new)++;
      i_all++;
    }
}

void		remp_second_str(char *second, char **new_str,
				int *i_new, int i_all)
{
  while (second[i_all] != '\0')
    {
      (*new_str)[*i_new] = second[i_all];
      (*i_new)++;
      i_all++;
    }
}

char		*concat_two_str_with_char(char *first, char *second, char car)
{
  char		*new_str;
  int		i_new;
  int		i_all;
  int		len;

  i_new = 0;
  i_all = 0;
  len = my_strlen(first);
  if (second != NULL)
    len = len + my_strlen(second);
  if ((new_str = malloc(len + 2)) == NULL)
    return (NULL);
  remp_first_str(first, &new_str, &i_new, i_all);
  if (car != '\0')
    {
      new_str[i_new] = car;
      i_new++;
    }
  if (second != NULL)
    remp_second_str(second, &new_str, &i_new, i_all);
  new_str[i_new] = '\0';
  return (new_str);
}
