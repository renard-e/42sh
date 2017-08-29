/*
** my_strlen_tabb.c for my_strlen_tab in /home/renard_e/systeme_unix/PSU_2015_42sh/lib/my
**
** Made by gregoire renard
** Login   <renard_e@epitech.net>
**
** Started on  Tue May 24 16:02:13 2016 gregoire renard
** Last update Sun Jun  5 00:02:57 2016 rodrigue rene
*/

#include <stdlib.h>
#include "my.h"

int		my_strlen_tabb(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int		my_strlen_tabbb(char ***tabbb)
{
  int		i;

  i = 0;
  while (tabbb[i] != NULL)
    i++;
  return (i);
}
