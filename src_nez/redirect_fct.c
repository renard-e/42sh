/*
** redirect_fct.c for reirect_fct in /home/renard_e/systeme_unix/PSU_2015_42sh/src_nez
** 
** Made by gregoire renard
** Login   <renard_e@epitech.net>
** 
** Started on  Sun Jun  5 18:56:00 2016 gregoire renard
** Last update Sun Jun  5 20:08:01 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int		ident_redirect(char **param, int *cpt_w)
{
  int		cpt_l;

  cpt_l = 0;
  while (param[*cpt_w] != NULL)
    {
      if (param[*cpt_w][cpt_l] == '>')
	{
	  if (param[*cpt_w][cpt_l + 1] == '>')
	    return (1);
	  return (0);
	}
      if (param[*cpt_w][cpt_l] == '<')
	{
	  if (param[*cpt_w][cpt_l + 1] == '<')
	    return (3);
	  return (2);
	}
      else
	(*cpt_w)++;
    }
  return (-1);
}

int		redirect_fct(t_info *info)
{
  int		cpt_w;
  int		indic;

  cpt_w = 0;
  if ((indic = ident_redirect(TABB, &cpt_w)) == -1)
    return (0);
  if (indic == 0)
    if ((simple_redirect_d(info, cpt_w)) == -1)
      return (-1);
  if (indic == 1)
    if ((double_redirect_d(info, cpt_w)) == -1)
      return (-1);
  if (indic == 2)
    if ((simple_redirect_g(info, cpt_w)) == -1)
      return (-1);
  if (indic == 3)
    if ((double_redirect_g(info, cpt_w)) == -1)
      return (-1);
  return (0);
}
