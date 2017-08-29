/*
** aff_tab.c for aff_tab in /home/renard_e/bin/Makefile_lib/lib/my
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun May  1 16:00:43 2016 gregoire renard
** Last update Sun Jun  5 20:37:29 2016 vincent nakache
*/

#include <stdlib.h>
#include "my.h"

void		aff_tab(char **tabb)
{
  int		i;

  i = 0;
  while (tabb[i] != NULL)
    {
      my_putstr(tabb[i]);
      my_putchar('\n');
      i++;
    }
}
