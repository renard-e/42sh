/*
** tabb_to_triple_tabb.c for tabb_to_triple_tabb in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene/entrainement
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Tue May 31 18:57:18 2016 rodrigue rene
** Last update Sun Jun  5 16:14:39 2016 rodrigue rene
*/

#include <stdlib.h>
#include "my.h"

int	my_strlen_command(int *tabi)
{
  int	i;

  i = 0;
  while (tabi[i] != -1)
    i++;
  return (i + 1);
}

void	aff_triple_tabb(char ***tabbb)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (tabbb[y] != NULL)
    {
      my_putstrd("CMD", y);
      my_putstr("= ");
      while (tabbb[y][x] != NULL)
	{
	  my_putchar('#');
	  my_putstr(tabbb[y][x]);
      	  my_putstr(" #");
	  x++;
	}
      x = 0;
      y++;
      my_putchar('\n');
    }
}

void	fill_triple_tabb(t_info *help, int i, int *nb_arg, int nb_tabb)
{
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (i <= nb_tabb)
    {
      while (x < nb_arg[y])
	{
	  if (y > 0)
	    help->triple_tabb[y][x] = help->tabb[i + y];
	  else
	    help->triple_tabb[y][x] = help->tabb[i];
	  i++;
	  x++;
	}
      if (help->sep_place[y] == -1)
	return ;
      y++;
      x = 0;
    }
}

void	w_alloc_triple_tabb(int *x, t_info *help, int *i, int **nb_arg)
{
  if ((*i) > 0)
    (*x) = help->sep_place[(*i)] - (help->sep_place[(*i) - 1]);
  else if ((*i) == 0)
    (*x) = help->sep_place[(*i)] + 1;
  if (help->sep_place[(*i)] == -1 && (*i) > 0)
    (*x) = (help->nb_tabb - help->sep_place[(*i) - 1]);
  if (help->sep_place[(*i)] == -1 && (*i) == 0)
    (*x) = (help->nb_tabb + 1);
  (*nb_arg)[(*i)] = (*x) - 1;
  if ((help->triple_tabb[(*i)] = malloc(sizeof(char *) * ((*x)))) == NULL)
    exit(-1);
  help->triple_tabb[(*i)][(*x) - 1] = NULL;
  (*x) = 0;
}

int	alloc_triple_tabb(t_info *help)
{
  int	all;
  int	i;
  int	x;
  int	*nb_arg;

  i = 0;
  x = 0;
  all = 0;
  if ((help->triple_tabb = malloc(sizeof(char **) *
				  ((all = my_strlen_command(help->tabi)) + 1))) == NULL
      || (nb_arg = malloc(sizeof(int) * (all + 1))) == NULL)
    exit(-1);
  nb_arg[all] = -1;
  help->triple_tabb[all] = NULL;
  while (i < all)
    {
      w_alloc_triple_tabb(&x, help, &i, &nb_arg);
    i++;
    }
  fill_triple_tabb(help, 0, nb_arg, help->nb_tabb);
  return (0);
}
