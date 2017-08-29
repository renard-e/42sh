/*
** pipe.c for pipe in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Fri Jun  3 21:16:04 2016 rodrigue rene
** Last update Sun Jun  5 17:17:53 2016 rodrigue rene
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "domage.h"
#include "my.h"
#include "rene.h"

int	pipe_function(t_info *help)
{
  if (grep_word("|", TABBH) != -1)
    {
      pipe_part_one(help);
      return (1);
    }
  return (0);
}
