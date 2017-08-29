/*
** tripl_tabbb_pipe.c for triple_tabb_pipe.c in /media/dieu/2337a639-4d85-4f36-ade6-cdcedffd0cf2/rene_r/Cours/Semestre_2/Systeme_Unix/PSU_2015_42sh/src_rene
**
** Made by rodrigue rene
** Login   <rene_repitech.net>
**
** Started on  Fri Jun  3 21:40:31 2016 rodrigue rene
** Last update Sun Jun  5 16:15:38 2016 rodrigue rene
*/

#include <stdlib.h>
#include "rene.h"
#include "my.h"

void	fill_triple_tabb_pipe(char	****tabbb,
			      int	*nb_arg,
			      int	**sep_place,
			      t_info	*help)
{
  int	x;
  int	y;
  int	i;

  x = 0;
  i = 0;
  y = 0;
  while (i <= help->fill)
    {
      while (x < nb_arg[y])
	{
	  if (y > 0)
	    (*tabbb)[y][x] = TABBH[i + y];
	  else
	    (*tabbb)[y][x] = TABBH[i];
	  i++;
	  x++;
	}
      if ((*sep_place)[y] == -1)
	return ;
      y++;
      x = 0;
    }
}

void	w_alloc_triple_t(char	****tabbb,
			 int	**place_pipe,
			 int	nb_tabb,
			 int	**nb_arg)
{
  int	i;
  int	all;
  int	x;

  i = 0;
  x = 0;
  all = my_strlen_command((*place_pipe));
  while (i < all)
    {
      if (i > 0)
  	x = (*place_pipe)[i] - ((*place_pipe)[i - 1]);
      else if (i == 0)
  	x = (*place_pipe)[i] + 1;
      if ((*place_pipe)[i] == -1 && i > 0)
  	x = (nb_tabb - (*place_pipe)[i - 1]);
      if ((*place_pipe)[i] == -1 && i == 0)
  	x = nb_tabb + 1;
      (*nb_arg)[i] = x - 1;
      if (((*tabbb)[i] = malloc(sizeof(char *) * (x))) == NULL)
  	exit(-1);
      (*tabbb)[i][x - 1] = NULL;
      x = 0;
      i++;

    }
}

int	alloc_triple_tabb_pipe(int	**tabi,
			       int	**place_pipe,
			       char	****tabbb,
			       t_info	*help)
{
  int	all;
  int	i;
  int	x;
  int	nb_tabb;
  int	*nb_arg;

  i = 0;
  x = 0;
  all = 0;
  nb_tabb = my_strlen_tabb(TABBH);
  if (((*tabbb) = malloc(sizeof(char **) *
			 ((all = my_strlen_command((*tabi))) + 1))) == NULL
      || (nb_arg = malloc(sizeof(int) * (all + 1))) == NULL)
    exit (-1);
  nb_arg[all] = -1;
  (*tabbb)[all] = NULL;
  w_alloc_triple_t(tabbb, place_pipe, nb_tabb, &nb_arg);
  help->fill = nb_tabb;
  fill_triple_tabb_pipe(tabbb, nb_arg, place_pipe, help);
  return (0);
}
