/*
** test_fct.c for test_fct in /home/renard_e/programmation_shell/PSU_2015_minishell2
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 24 14:25:52 2016 gregoire renard
** Last update Tue May 24 14:43:52 2016 gregoire renard
*/

#include "my.h"

int		test_fct(char *fct)
{
  int		i;

  i = 0;
  if (fct[0] != '/' && fct[0] != '.')
    return (-1);
  while (fct[i] != '\0')
    {
      if (fct[i] == '/' && fct[i + 1] == '/')
	return (-1);
      if (fct[i] == '.' && fct[i + 1] == '/' && i != 0 && fct[i - 1] == '/')
	return (-1);
      i++;
    }
  return (0);
}
