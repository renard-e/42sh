/*
** error.c for error in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene/entrainement
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Mon May 30 23:01:00 2016 rodrigue rene
** Last update Sun Jun  5 20:16:36 2016 gregoire renard
*/

#include <stdlib.h>
#include "my.h"

int	error_null_command(void)
{
  my_putstr_error("Invalid null command.\n");
  return (-1);
}

int	error_missing(void)
{
  my_putstr_error("Missing name for redirect.\n");
  return (-1);
}

void	error_command_not(t_info *info)
{
  my_putstr_error(TABB[0]);
  my_putstr_error(": Command not found.\n");
}
