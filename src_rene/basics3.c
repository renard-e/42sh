/*
** basics3.c for basics3 in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_minishell2
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Thu Mar 31 16:41:06 2016 rodrigue rene
** Last update Thu Jun  2 18:45:45 2016 rodrigue rene
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void	voidable(void *argc, void *argv)
{
  (void) argc;
  (void) argv;
}

int	len(char *str)
{
  return (my_strlen(str));
}

void	my_exit_malloc(void)
{
  my_putstr("Malloc failure !\n");
  exit(EXIT_FAILURE);
}

void	my_exit_sys(void)
{
  my_putstr("Call system failure !\n");
  exit(EXIT_FAILURE);
}

void	my_realloc_inverse(char **suits, int i, char *str)
{
  int	len;
  int	x;

  x = 0;
  len = my_strlen((*suits));
  if (((*suits) = malloc(len - i + 1)) == NULL)
    exit(-1);
  while (str[i] != '\0')
    {
      (*suits)[x] = str[i];
      i++;
      x++;
    }
  (*suits)[x] = '\0';
}
