/*
** free_fct.c for free_fct.c in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue May 24 13:56:32 2016 gregoire renard
** Last update Sun May 29 17:28:51 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
