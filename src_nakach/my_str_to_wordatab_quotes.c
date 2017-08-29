/*
** my_str_to_wordatab_quotes.c for lel in /home/nakach_v/PSU/PSU_2015_42sh/src_nakach
** 
** Made by vincent nakache
** Login   <nakach_v@epitech.net>
** 
** Started on  Fri Jun  3 18:02:01 2016 vincent nakache
** Last update Sun Jun  5 21:28:16 2016 Jean-Adrien Domage
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/nakach.h"

int		quotes_func(char **tabb, t_all *all, char *str)
{
  all->remp = 0;
  all->e += 1;
  all->s = all->e;
  while (str[all->e] != '"')
    all->e += 1;
  all->dif = all->e - all->s;
  if ((tabb[all->dimen] = malloc((all->dif + 1) * sizeof(char))) == NULL)
    return (-1);
  while (all->s < all->e)
    {
      tabb[all->dimen][all->remp] = str[all->s];
      all->s += 1;
      all->remp += 1;
    }
  tabb[all->dimen][all->dif] = '\0';
  all->e++;
  all->s = all->e;
  all->dimen += 1;
  return (0);
}

int		remp_normal(char **tabb, t_all *all, char *str)
{
  all->remp = 0;
  all->e = all->s;
  while (str[all->e] != ' ' && str[all->e] != '\t' && str[all->e] != '\0')
    all->e += 1;
  all->dif = all->e - all->s;
  if ((tabb[all->dimen] = malloc((all->dif + 1) * sizeof(char))) == NULL)
    return (-1);
  while (all->s < all->e)
    {
      tabb[all->dimen][all->remp] = str[all->s];
      all->remp += 1;
      all->s += 1;
    }
  tabb[all->dimen][all->dif] = '\0';
  all->s = all->e;
  all->dimen += 1;
  return (0);
}

int		remp_tabb(char **tabb, char *str, int nb, t_all all)
{
  while (all.dimen < nb)
    {
      while (str[all.s] == ' ' || str[all.s] == '\t' && str[all.s] != '\0')
	all.s += 1;
      all.e = all.s;
      while (str[all.e] != ' ' && str[all.e] != '\t' && str[all.e] != '\0')
	{
	  if (str[all.e] == '"')
	    quotes_func(tabb, &all, str);
	  if (str[all.e] == '\0')
	    {
	      tabb[all.dimen] = NULL;
	      return (0);
	    }
	  all.e += 1;
	}
      while (str[all.s] == ' ' || str[all.s] == '\t' && str[all.s] != '\0')
	all.s += 1;
      if (str[all.s] != '"')
	remp_normal(tabb, &all, str);
    }
  tabb[all.dimen] = NULL;
  return (0);
}

char		**my_str_to_wordtab_quotes(char *str)
{
  int		nb;
  char		**tabb;
  t_all		all;

  all.s = 0;
  all.dimen = 0;
  nb = count_words_quotes(str);
  if ((tabb = malloc((nb + 1) * sizeof(char*))) == NULL)
    return (NULL);
  remp_tabb(tabb, str, nb, all);
  return (tabb);
}
