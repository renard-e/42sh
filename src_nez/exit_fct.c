/*
** exit_fct.c for exit_fct in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue May 24 15:56:19 2016 gregoire renard
** Last update Thu Jun  2 21:12:29 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include "domage.h"
#include "my.h"

int		test_alpha(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (('0' <= str[i] && str[i] <= '9') || str[i] == '-')
	i++;
      else
	return (-1);
    }
  if (i > 10)
    return (-1);
  return (0);
}

int		exit_fct(t_info *info, char **param)
{
  int		indic;

  free_builtin_tab(info->builtin_tab);
  if ((my_strlen_tabb(param) > 2))
    return (merror(EXIT_ERROR, -1));
  if ((my_strlen_tabb(param) == 1))
    exit(0);
  if ((test_alpha(param[1])) == -1)
    return (merror(EXIT_ERROR, -1));
  indic = my_getnbr(param[1]);
  my_putstr(EXIT_STRING);
  exit(indic);
}
