/*
** builtins.c for builtins.c in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Thu Jun  2 14:25:52 2016 rodrigue rene
** Last update Thu Jun  2 19:53:09 2016 rodrigue rene
*/

#include "domage.h"
#include "my.h"

int	builtins(t_info *info)
{
  int	i;

  i = 0;
  info->witness = 0;
  if (TABB[0] != NULL)
    {
      while (info->builtin_tab[i])
	{
	  if ((word_word(TABB[0], info->builtin_tab[i])) == 1)
	    {
	      info->witness = 1;
	      if ((info->wit_comm = (builtin_fct[i])(info, TABB)) == -1)
		return (0);
	    }
	  i += 1;
	}
    }
  return (1);
}
