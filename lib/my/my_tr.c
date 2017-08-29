/*
** my_tr.c for my_tr in /home/renard_e/systeme_unix/PSU_2015_my_ls
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Nov 24 14:47:02 2015 gregoire renard
** Last update Thu Apr 28 15:51:35 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int	my_swap_file(char **file1, char **file2)
{
  char	*tempo;

  tempo = (*file1);
  (*file1) = (*file2);
  (*file2) = tempo;
  return (0);
}

int	my_tr(char **file)
{
  int   i;
  int	ret_cmp;
  int   indic;

  indic = 1;
  i = 0;
  ret_cmp = 0;
  while (indic == 1)
    {
      indic = 0;
      i = 0;
      while (file[i + 1] != NULL)
	{
	  if ((ret_cmp = my_strcmp(file[i], file[i + 1]) > 0))
	    {
	      my_swap_file(&file[i], &file[i + 1]);
	      indic = 1;
	      i = i + 1;
	    }
	  else
	    i = i + 1;
	}
    }
  return (0);
}
