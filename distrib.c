/*
** distrib.c for distrib in /home/renard_e/systeme_unix/PSU_2015_42sh
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Jun  5 21:30:21 2016 gregoire renard
** Last update Sun Jun  5 21:30:22 2016 gregoire renard
*/

#include "my.h"
#include "rene.h"

int	distrib_command(t_info *info)
{
  int	i;

  i = 0;
  info->wit_comm = 0;
  while (info->triple_tabb[i] != NULL)
    {
      info->command_num = i;
      if (i == 0 || info->tabi[i - 1] == 0 ||
	  (info->wit_comm == -1 && info->tabi[i - 1] == 1) ||
	  (info->wit_comm == 0 && info->tabi[i - 1] == 2))
	{
	  /* if ((redirect_fct(info)) == -1) */
	  /*   return (-1); */
	  if (pipe_function(info) != 0)
	    return (1);
	  if (builtins(info) == 0)
	    return (-1);
	  else if (info->witness == 0)
	    if (((info->wit_comm = my_exec_param(TABB, info))) == -1)
	      error_command_not(info);
	}
      i++;
      info->command_num++;
    }
}
