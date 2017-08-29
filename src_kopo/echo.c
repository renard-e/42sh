/*
** echo.c for echo echo echo echo echo echo echo echo echo echo echo echo echo echo echo echo LEE SIN in /home/rechou_a/rendu/PSU/PSU_2015_42sh/src_kopo
** 
** Made by Benjamin RECHOU
** Login   <rechou_a@epitech.net>
** 
** Started on  Mon May 30 15:59:07 2016 Benjamin RECHOU
** Last update Fri Jun  3 16:06:19 2016 vincent nakache
*/

#include "nez.h"
#include "kopo.h"
#include "nakach.h"
#include "my.h"

int			check_nb_quote(char *str)
{
  int			i;
  int			c;

  i = 0;
  c = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '"')
	c += 1;
      i += 1;
    }
  if (c % 2 == 0)
    return (1);
  else
    return (merror("Unmatched \".\n", 0));
}

int			echo(t_info *info, char **tab)
{
  int			i;

  i = 1;
  while (tab[i])
    {
      my_putstr(tab[i]);
      my_putchar(' ');
      i += 1;
    }
  my_putchar('\n');
  return (0);
}
